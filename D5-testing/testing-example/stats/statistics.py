class Stats(object):
    def __init__(self):
        self.num_entries = 0.
        self.sum = 0.

    def fill(self, x):
        if x < 20:
            self.sum += x
        else:
            self.sum += x*x*x
        self.num_entries += 1

    def avg(self):
        return self.sum / self.num_entries



