import numpy as np

    # initialize bandit
    # select action
    # get reward 
    # update action selection
    # update value estimate

class RunExperiment():
    def __init__(self, bandit, num_steps) -> None:
        self.bandit = bandit
        self.num_steps = num_steps
    
    def run(self):
        for i in range(self.num_steps):
            action = bandit.arm()
            reward = bandit.np_random.normal(bandit.q_star[action], 1)
            bandit.update(action, reward)


class Bandit():
    """Class for repeatable pseudo-random Bandit Algorithms"""
    def __init__(self, n=10) -> None:
        self.n = n
        self.np_random : np.random.RandomState
        self.q_star = []
        self.seed()
        
    def seed(self, seed=None):
        self.np_random = np.random.RandomState(seed)
    
    def arm(self):
        raise NotImplementedError()
    
    def update(self, arm, reward):
        pass

    def reset(self): # somewhere this will need to be overriden to allow for other initalizatoins
        self.q_star = self.np_random.normal(loc=0, scale=1, size=self.n)

class AveragingBandit(Bandit):
    def __init__(self, n=10, epsilon=0.1) -> None:
        super().__init__(n)
        self.epsilon = epsilon
        self.N = []
        self.Q = []
        self.reset()
    
    def arm(self):
        # random_sample samples a randome number between [1, 0]
        if self.np_random.random_sample() < self.epsilon: 
            # Explore: choose a randome action
            action = self.np_random.randint(0, self.n)
        else:
            # Exploit: choose the action with the highes estimate
            maxQ = np.max(self.Q)
            best = np.asarray(self.Q == maxQ).nonzero()[0] # the zero index returns the array. the function also returns the dtype in a tuple
            if len(best) > 1:
                action = self.np_random.choice(best)
            else:
                action = best[0]
        return action
    
    def update(self, arm, reward):
        self.N[arm] += 1
        self.Q[arm] += (reward - self.Q[arm])/self.N[arm]

    def reset(self):
        self.Q = np.zeros(self.n)
        self.N = np.zeros(self.n)
        super().reset()

if (__name__ == "__main__"):
    bandit = AveragingBandit(n=10, epsilon=0.01)

