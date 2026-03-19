import numpy as np

def init_bandit(n: int):

    # initializing true mean reward for each arm. 
    q_star = np.random.normal(loc=0, scale=1,size=n)
    # loc is the mean, scale is the standard deviation, 
    # and size is the number of samples to draw 

    # initializing the agent's estimated mean reward for each arm
    Q = np.zeros(n)

    # initializing number of times each arm has been chosen
    N = np.zeros(n)

    return q_star, Q, N

# Optimistic initial value
def init_optimal(n, optimistic=5):
    # initializing true mean reward for each arm. 
    q_star = np.random.normal(loc=0, scale=1,size=n)
    # loc is the mean, scale is the standard deviation, 
    # and size is the number of samples to draw 

    # initializing the agent's estimated mean reward for each arm
    Q = np.ones(n)*optimistic

    # initializing number of times each arm has been chosen
    N = np.zeros(n)

    return q_star, Q, N

# Baselined true value
def init_baseline(n, baseline=5):
    # initializing true mean reward for each arm. 
    q_star = np.random.normal(loc=baseline, scale=1,size=n)
    # loc is the mean, scale is the standard deviation, 
    # and size is the number of samples to draw 

    # initializing the agent's estimated mean reward for each arm
    Q = np.zeros(n)

    # initializing number of times each arm has been chosen
    N = np.zeros(n)

    return q_star, Q, N

# eps is a number between [1, 0]
def take_greedy_action(Q, eps):

    # random_sample samples a randome number between [1, 0]
    if np.random.random_sample() < eps: 
        # Explore: choose a randome action
        action = np.random.randint(len(Q))
    else:
        # Exploit: choose the action with the highes estimate
        maxQ = np.max(Q)
        best = np.asarray(Q == maxQ).nonzero()[0] # the zero index returns the array. the function also returns the dtype in a tuple
        if len(best) > 1:
            action = np.random.choice(best)
        else:
            action = best[0]

    return action

def run_greedy_bandit_sample_avg(initfn, n, eps, num_steps):

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
    
    return rewards, optimal

def take_UCB_action(c, Q: np.ndarray, N, t):
    num_arms = len(Q)
    # 1. calculate the UCB for each action
    Ucb = np.zeros(num_arms)
    #print(N)
    for i in range(num_arms):
        if (N[i] > 0 and t > 0):
            Ucb[i] = Q[i] + c * np.sqrt(np.log(t)/N[i])
        else:
            Ucb[i] = 10000 # basically infinity  

    #print(Ucb)
    # 2. select index/action w the max UCB value
    maxQ = np.max(Ucb)
    best = np.asarray(Ucb == maxQ).nonzero()[0] # the zero index returns the array. the function also returns the dtype in a tuple
    if len(best) > 1:
        # 3. if tied, select randomly between the actions w max value
        action = np.random.choice(best)
    else:
        action = best[0]

    return action



def run_UCB_bandit_sample_avg(initfn, n, c, num_steps):
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
    
    return rewards, optimal
    

# gradient bandit
def take_gradient_action(policy):

    action = np.random.choice(a=len(policy), size=None, p=policy)

    return action

def update_gradient_policy(policy, preferences):

    expPrefs = np.zeros(len(policy))
    den = 1e-5
    for b in range (len(policy)):
        expPrefs[b] = np.exp(preferences[b])
        den = den + expPrefs[b]

    for a in range (len(policy)):
        policy[a] = expPrefs[a] / den


    return policy


def run_Gradient_bandit(initfn, n, alpha, num_steps):
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
    # print("policy: ",policy)
    return rewards, optimal