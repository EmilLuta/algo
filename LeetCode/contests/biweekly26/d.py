from typing import List

class Solution:
    def _compare_tuples(self, a, b):
        n = len(a)
        m = len(b)
        if n > m:
            return 1
        if n < m:
            return -1
        # if n != len(b):
        #     raise ValueError('what you comparing, boy?')
        for i in range(n):
            if a[i] > b[i]:
                return 1
            elif a[i] < b[i]:
                return -1
        return 0

    def largestNumber(self, costs: List[int], target: int) -> str:
        n = 5001
        s = set(costs)
        dp = [tuple() for _ in range(n)]
        for i in range(len(costs)):
            dp[costs[i]] = (i + 1, )
        for i in range(target + 1):
            for j in range(len(costs)):
                cost = costs[j]
                if i >= cost:
                    curr_length = len(dp[i])
                    if len(dp[i - cost]) != 0 and len(dp[i - cost]) + 1 >= curr_length:
                        new_tuple = tuple(sorted(dp[i - cost] + (j + 1,), reverse=True))
                        if self._compare_tuples(dp[i], new_tuple) == -1:
                            dp[i] = new_tuple
        return ''.join(str(i) for i in dp[target])

print(Solution().largestNumber([4,3,2,5,6,7,2,5,5], 9))
