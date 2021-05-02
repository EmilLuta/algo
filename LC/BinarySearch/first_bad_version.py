def isBadVersion(x):
    return x >= 1

class Solution:
    def firstBadVersion(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 0, n
        while low < high:
            mid = (low + high) // 2
            if isBadVersion(mid):
                high = mid
            else:
                low = mid + 1
        if not(isBadVersion(mid)) and isBadVersion(mid + 1):
            return mid + 1
        else:
            return mid

print(Solution().firstBadVersion(1))
