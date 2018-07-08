class MovingAverage:

    def __init__(self, size):
        """
        Initialize your data structure here.
        :type size: int
        """
        self.current = []
        self.size = size
        self.current_size = 0
        self.sum = 0

    def next(self, val):
        """
        :type val: int
        :rtype: float
        """
        if len(self.current) == self.size:
            self.sum -= self.current.pop(0)
            self.current_size -= 1
        self.current.append(val)
        self.current_size += 1
        self.sum += val
        return self.sum / self.current_size


obj = MovingAverage(3)
print(obj.next(1))
print(obj.next(10))
print(obj.next(3))
print(obj.next(5))
