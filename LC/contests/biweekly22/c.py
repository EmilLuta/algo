class Solution:
    def __init__(self):
        self._cache = {}
        self.values = []

    def _compute_values(self, x):
        steps = 0
        to_cache = [x]
        while x != 1:
            if x in self._cache:
                steps += self._cache[x]
                break
            if x % 2 == 0:
                x //= 2
                to_cache.append(x)
            else:
                x = x * 3 + 1
                to_cache.append(x)
            steps += 1
        for i in range(len(to_cache) - 1):
            self._cache[to_cache[i]] = steps - i
        return steps
    def getKth(self, lo: int, hi: int, k: int) -> int:
        for i in range(lo, hi + 1):
            self.values.append((self._compute_values(i), i))
        self.values.sort()
        return self.values[k - 1][1]

assert Solution().getKth(12, 15, 2) == 13
assert Solution().getKth(1, 1, 1) == 1
assert Solution().getKth(7, 11, 4) == 7
assert Solution().getKth(10, 20, 5) == 13
assert Solution().getKth(1, 1000, 777) == 570
