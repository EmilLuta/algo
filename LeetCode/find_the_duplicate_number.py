class Solution:
    def findDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        slow = nums[0]
        fast = nums[nums[0]]
        n = 0
        while slow != fast:
            slow = nums[slow]
            fast = nums[nums[fast]]
        while slow != n:
            slow = nums[slow]
            n = nums[n]
        return slow

print(Solution().findDuplicate([1,3,4,2,2]))
