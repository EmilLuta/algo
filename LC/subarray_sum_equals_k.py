class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        n = len(nums)
        if n == 0:
            return 0
        prefix_sum = [0]
        for number in nums:
            prefix_sum.append(number + prefix_sum[-1])
        c = 0
        for i in range(n):
            for j in range(i, n):
                if prefix_sum[j + 1] - prefix_sum[i] == k:
                    c += 1
        return c
