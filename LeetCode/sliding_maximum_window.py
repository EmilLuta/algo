from collections import deque
class Solution:
    def maxSlidingWindow(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums:
            return []
        if k == 0:
            return nums
        deq = deque()
        result = []
        for i in range(k):
            while len(deq) != 0 and nums[i] > nums[deq[-1]]:
                deq.pop()
            deq.append(i)
        for i in range(k, len(nums)):
            result.append(nums[deq[0]])
            if deq[0] < i - k + 1:
                deq.popleft()
            while len(deq) != 0 and nums[i] > nums[deq[-1]]:
                deq.pop()
            deq.append(i)
        result.append(nums[deq[0]])
        return result
