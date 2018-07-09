class Solution:
    def trap(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        n = len(height)
        if n == 0:
            return 0
        left = [0] * n
        right = [0] * n
        water = 0
        left[0] = height[0]
        for i in range(1, n):
            left[i] = max(left[i - 1], height[i])
        right[n - 1] = height[n - 1]
        for i in range(n - 2, -1, -1):
            right[i] = max(right[i + 1], height[i])
        for i in range(0, n):
            water += min(left[i], right[i]) - height[i]
        return water

    def trap(self, height):
        result = 0
        left_max = 0
        right_max = 0
        lo = 0
        hi = n-1
        while(lo <= hi):
            if(arr[lo] < arr[hi]):
                if(arr[lo] > left_max):
                    left_max = arr[lo]
                else:
                    result += left_max - arr[lo]
                lo+=1
            else:
                if(arr[hi] > right_max):
                    right_max = arr[hi]
                else:
                    result += right_max - arr[hi]
                hi-=1
        return result
print(Solution().trap([0,1,0,2,1,0,1,3,2,1,2,1]))
