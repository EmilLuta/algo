class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        m = 0
        end = len(height) - 1
        start = 0
        while end > start:
            current = min(height[start], height[end]) * (end - start)
            if current > m:
                m = current
            if height[start] < height[end]:
                start += 1
            else:
                end -= 1
        return m

print(Solution().maxArea([1,8,6,2,5,4,8,3,7]))
