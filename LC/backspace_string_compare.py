class Solution:
    def backspaceCompare(self, S: str, T: str) -> bool:
        s = []
        t = []
        for c in S:
            if c == "#":
                if len(s) > 0:
                    s.pop()
            else:
                s.append(c)
        for c in T:
            if c == "#":
                if len(t) > 0:
                    t.pop()
            else:
                t.append(c)
        if len(s) != len(t):
            return False
        for i in range(0, len(s)):
            if t[i] != s[i]:
                return False
        return True


print(Solution().backspaceCompare("ab##", "c#d#"))
