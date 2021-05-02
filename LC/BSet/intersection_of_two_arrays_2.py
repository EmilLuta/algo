class Solution:
    def intersect(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        from collections import Counter
        a, b = map(Counter, [nums1, nums2])
        o = []
        for i in a:
            if i in b:
                o+= [i] * min(a[i], b[i])
        return o
