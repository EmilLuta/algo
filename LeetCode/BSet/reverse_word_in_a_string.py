class Solution:
    def reverseWords(self, s):
        """
        :type str: List[str]
        :rtype: void Do not return anything, modify str in-place instead.
        """
        n = len(s)
        def reverse(i, j):
            n = j + i - 1
            for k in range(i, (j + i) // 2):
                s[k], s[n - k] = s[n - k], s[k]
        reverse(0, n)
        start = 0
        for i in range(n):
            if s[i] == ' ':
                reverse(start, i)
                start = i + 1
        reverse(start, n)
