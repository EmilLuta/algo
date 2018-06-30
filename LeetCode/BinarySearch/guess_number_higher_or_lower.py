# The guess API is already defined for you.
# @param num, your guess
# @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
# def guess(num):

def guess(num):
    if num == 6:
        return 0
    if 6 > num:
        return 1
    return -1

class Solution(object):
    def guessNumber(self, n):
        """
        :type n: int
        :rtype: int
        """
        low, high = 0, n
        while low <= high:
            mid = (low + high) // 2
            g = guess(mid)
            if g == 0:
                return mid
            elif g == -1:
                high = mid - 1
            else:
                low = mid + 1

print(Solution().guessNumber(10))
