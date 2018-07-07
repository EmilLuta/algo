class Solution:
    def reverseString(self, s):
        """
        :type s: str
        :rtype: str
        """
        s_l = [l for l in s]
        n = len(s_l)
        for i in range(n // 2):
            s_l[i], s_l[n - i - 1] = s_l[n - i - 1], s_l[i]
        return ''.join(s_l)

