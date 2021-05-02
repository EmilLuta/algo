from typing import List



class Solution:
    def __init__(self):
        self._cache = {}

    def _rec(self, slices):
        if slices in self._cache:
            return self._cache[slices]
        n = len(slices)
        if n == 3:
            x = max(slices)
            self._cache[slices] = x
            return x
        value = float('-inf')
        for i in range(n):
            left, right = i - 1 if i - 1 >= 0 else n - 1, (i + 1) % n
            print(tuple(slices[j] for j in range(n) if j != i and j != left and j != right))
            value = max(value, slices[i] + self._rec(tuple(slices[j] for j in range(n) if j != i and j != left and j != right)))
        self._cache[slices] = value
        return value

    def maxSizeSlices(self, slices: List[int]) -> int:
        return self._rec(tuple(i for i in slices))

# print(Solution().maxSizeSlices([1, 2, 3, 4, 5, 6]))
assert Solution().maxSizeSlices([1,2,3,4,5,6]) == 10
assert Solution().maxSizeSlices([8,9,8,6,1,1]) == 16
assert Solution().maxSizeSlices([4,1,2,5,8,3,1,9,7]) == 21
assert Solution().maxSizeSlices([3,1,2]) == 3
assert Solution().maxSizeSlices([9,8,1,7,7,9,5,10,7,9,3,8,3,4,8]) == 45
print(Solution().maxSizeSlices([3,9,4,5,3,8,1,10,3,7,2,9,10,2,6,2,9,8,7,10,7,5,1,6,5,8,9,10,6,5,7,7,2,5,3,10,4,3,4]))
# [9,8,1,7,7,9,5,10,7,9,3,8,3,4,8]
