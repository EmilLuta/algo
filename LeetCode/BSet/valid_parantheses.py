class Solution:
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        keep = []
        for i in s:
            if i == ')':
                if len(keep) == 0:
                    return False
                if keep[-1] != '(':
                    return False
                keep.pop()
            elif i == '}':
                if len(keep) == 0:
                    return False
                if keep[-1] != '{':
                    return False
                keep.pop()
            elif i == ']':
                if len(keep) == 0:
                    return False
                if keep[-1] != '[':
                    return False
                keep.pop()
            else:
                keep.append(i)
        return len(keep) == 0
