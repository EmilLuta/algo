class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        left = [0] * n
        right = [0] * n
        m = 0
        for i in range(n):
            left[i] = max(m, height[i])
            m = left[i]
        m = 0
        for i in range(len(height) - 1, -1, -1):
            right[i] = max(m, height[i])
            m = right[i]
        total = 0
        for i in range(len(height)):
            total += min(left[i], right[i]) - height[i]
        return total

print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]))
