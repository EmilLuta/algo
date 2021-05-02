class Solution:
    def licenseKeyFormatting(self, S: str, K: int) -> str:
        out = ''
        s = S.replace('-', '').upper()[::-1]
        n = len(s)
        curr = ''
        i = K
        while i < n:
            out += s[i - K:i]
            out += '-'
            i += K
            if i == n - 1:
                continue
        out += s[i - K:min(i, n)]
        return out[::-1]

print(Solution().licenseKeyFormatting("5F3Z-2e-9-w", 4))
print(Solution().licenseKeyFormatting("2-5g-3-J", 2))
