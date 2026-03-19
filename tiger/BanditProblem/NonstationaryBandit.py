from nArmedBandit import *
import numpy as np
import matplotlib.pyplot as plt

def init_bandit_ns(n):
    #initialize equal true values for the arms
    q_star = np.ones(n) * np.random.normal(loc=0, scale=1, size=None)

    Q = np.zeros(n)
    N = np.zeros(n)

    return q_star, Q, N

def add_random_walk(q_star: np.ndarray):
    q_star = q_star + np.random.normal(loc=0, scale=0.01, size=q_star.shape)

    return q_star

def run_ns_bandit_cnst_step(initfn, n, eps, num_steps, step_size):
    # this functio nuses the constant parameter as step_size 
    # see nArmedBandit for the sample average case
    q_star, Q, N = initfn(n)
    rewards = np.zeros(num_steps)
    optimal = np.zeros(num_steps)

    for i in range(num_steps):
        # change the true value of the action
        action = take_greedy_action(Q, eps)
        reward = np.random.normal(q_star[action], 1)
        rewards[i] = reward
        N[action] += 1
        Q[action] += (reward - Q[action])*step_size

        if action == np.argmax(q_star):
            optimal[i] = 1
        
        q_star = add_random_walk(q_star)
    
    return rewards, optimal

def run_ns_greedy_bandit_sample_avg(initfn, n, eps, num_steps):

    q_star, Q, N = initfn(n)
    # track the reward obtained at each step
    rewards = np.zeros(num_steps)
    # track whether the optimal action was taken. Optimal action is the arm with the highest true value
    optimal = np.zeros(num_steps)

    for i in range(num_steps):
        action = take_greedy_action(Q, eps)
        reward = np.random.normal(q_star[action], 1)
        rewards[i] = reward
        N[action] += 1
        Q[action] += (reward - Q[action])/N[action]

        if action == np.argmax(q_star):
            optimal[i] = 1
        
        q_star = add_random_walk(q_star)
    
    return rewards, optimal

def run_ns_greedy_unbiased_step_size(initfn, n, eps, num_steps, step_size):
    q_star, Q, N = initfn(n)
    # track the reward obtained at each step
    rewards = np.zeros(num_steps)
    # track whether the optimal action was taken. Optimal action is the arm with the highest true value
    optimal = np.zeros(num_steps)
    beta = 1
    trace = 0 # trace is \bar{O_n}

    for i in range(num_steps):
        action = take_greedy_action(Q, eps)
        reward = np.random.normal(q_star[action], 1)
        rewards[i] = reward
        N[action] += 1

        # unbiased step size
        trace += step_size*(1-trace)
        # print(trace)
        beta = step_size/trace

        Q[action] += (reward - Q[action])*beta

        if action == np.argmax(q_star):
            optimal[i] = 1
        
        q_star = add_random_walk(q_star)
    
    return rewards, optimal

def run_ns_UCB_bandit_sample_avg(initfn, n, c, num_steps):
    q_star, Q, N = initfn(n)
    # track the reward obtained at each step
    rewards = np.zeros(num_steps)
    # track whether the optimal action was taken. Optimal action is the arm with the highest true value
    optimal = np.zeros(num_steps)

    for i in range(num_steps):
        action = take_UCB_action(c, Q, N, i)
        reward = np.random.normal(q_star[action], 1)
        rewards[i] = reward
        N[action] += 1
        Q[action] += (reward - Q[action])/N[action]

        if action == np.argmax(q_star):
            optimal[i] = 1

        q_star = add_random_walk(q_star)
    
    return rewards, optimal 


def run_ns_Gradient_bandit(initfn, n, alpha, num_steps):
    q_star, H, N = initfn(n)
    # track the reward obtained at each step
    rewards = np.zeros(num_steps)
    # track whether the optimal action was taken. Optimal action is the arm with the highest true value
    optimal = np.zeros(num_steps)
    # init the policy
    policy = np.zeros(n)
    
    r_avg = 0

    for i in range(num_steps):
        policy = update_gradient_policy(policy, H)
        # print("policy: ",policy)

        action = take_gradient_action(policy)
        reward = np.random.normal(q_star[action], 1)
        # print(reward)
        rewards[i] = reward
        if (i == 0):
            r_avg = reward

        N[action] += 1
        # update gradient preferences
        for a in range(n):
            if (a == action):
                H[a] = H[a] + alpha*(reward - r_avg)*(1-policy[a])
            else:
                H[a] = H[a] - alpha*(reward - r_avg)*(policy[a])
        # print("prefs: ", H)
        # update reward average after updating the preferences to not include the new reward
        r_avg = r_avg + (reward - r_avg)/(i+1)
        # print("Avg reward: ", r_avg)

        if action == np.argmax(q_star):
            optimal[i] = 1

        q_star = add_random_walk(q_star)
        
    # print("policy: ",policy)
    return rewards, optimal