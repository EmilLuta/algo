from collections import Counter

class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        a = Counter(nums1)
        b = Counter(nums2)
        output = []
        for i in a:
            if i in b:
                output += [i] * min(a[i], b[i])
        return output

    def intersect(self, nums1, nums2):
        nums = Counter(nums1)
        output = []
        for i in nums2:
            if i in nums and nums[i] > 0:
                output.append(i)
                nums[i] -= 1
        return output

print(Solution().intersect([1, 2, 2, 1], [2, 2]))
print(Solution().intersect([4, 9, 5], [9, 4, 9, 8, 4]))
