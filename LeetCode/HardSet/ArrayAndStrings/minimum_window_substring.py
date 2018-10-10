from collections import Counter

class Solution:
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        counter, left = Counter(t), len(t)
        i = I = J = 0
        for j, c in enumerate(s, 1):
            if counter[c] > 0:
                left -= 1
            counter[c] -= 1
            if left == 0:
                while i < j and counter[s[i]] < 0:
                    counter[s[i]] += 1
                    i += 1
                if not J or j - i <= J - I:
                    I, J = i, j
        return s[I:J]

print(Solution().minWindow('ADOBECODEBANC', 'BANC'))
