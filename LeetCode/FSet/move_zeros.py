class Solution:
    def moveZeroes(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        if len(nums) == 0:
            return
        for i in range(len(nums)):
            if nums[i] == 0:
                j = i
                while j < len(nums) and nums[j] == 0:
                    j += 1
                if j == len(nums):
                    return
                nums[i], nums[j] = nums[j], nums[i]
        return

print(Solution().moveZeroes([0,1,0,3,12]))
