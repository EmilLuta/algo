class Solution:
    def firstUniqChar(self, s):
        """
        :type s: str
        :rtype: int
        """
        from collections import OrderedDict
        d = OrderedDict()
        for i in range(len(s)):
            if s[i] in d and d[s[i]] != -1:
                d[s[i]] = -1
            elif s[i] not in d:
                d[s[i]] = i
        for key in d:
            if d[key] != -1:
                return d[key]
        return -1
