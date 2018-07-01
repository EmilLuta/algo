class Solution:
    def findPeakElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) < 3:
            return nums.index(max(nums))
        low, high = 0, len(nums) - 1
        while low < high:
            mid = (low + high) // 2
            if nums[mid] < nums[mid +  1]:
                low = mid + 1
            else:
                high = mid
        return low
print(Solution().findPeakElement([1, 6, 5, 4, 3, 2, 1]))
