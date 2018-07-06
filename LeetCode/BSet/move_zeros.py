class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        start = 0
        for num in nums:
            if num != 0:
                nums[start] = num
                start += 1
        for i in range(start, len(nums)):
            nums[i] = 0
