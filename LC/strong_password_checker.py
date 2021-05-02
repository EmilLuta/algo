class Solution:
    def strongPasswordChecker(self, s: str) -> int:
        n = len(s)
        repeating_sequences = []
        i = 1
        lower = False
        upper = False
        digit = False
        while i < n:
            j = i
            while j < n and s[j] == s[j - 1]:
                j += 1
            if j - i >= 1:
                repeating_sequences.append((i - 1, j))
                i = j
            else:
                i += 1
        for c in s:
            if c.isdigit():
                digit = True
            if c >= 'a' and c <= 'z':
                lower = True
            if c >= 'A' and c <= 'Z':
                upper = True
        import code
        code.interact(local=dict(globals(), **locals()))
        change = 0
        if n >= 6 and n <= 20 and lower and upper and digit and len(repeating_sequences) == 0:
            return 0
        if len(repeating_sequences) == 0:
            if n > 20:
                change += n - 20
                if not lower:
                    change += 1
                if not upper:
                    change += 1
                if not digit:
                    change += 1
                return change
            if n < 6:
                if not lower:
                    change += 1
                    n += 1
                if not upper:
                    change += 1
                    n += 1
                if not digit:
                    change += 1
                    n += 1
                change += max(6 - n, 0)
                return change
            if not lower:
                change += 1
            if not upper:
                change += 1
            if not digit:
                change += 1
            return change
        to_remove = 0
        for seq in repeating_sequences:
            diff = seq[1] - seq[0]
            if not lower:
                diff -= 3
                lower = True
                change += 1
            if diff <= 2:
                continue
            if not upper:
                diff -= 3
                upper = True
                change += 1
            if diff <= 2:
                continue
            if not digit:
                diff -= 3
                digit = True
                change += 1
            if diff > 2:
                to_remove += diff - 2
        if n > 20:
            change += max(n - 20, to_remove)
            if not lower:
                change += 1
            if not upper:
                change += 1
            if not digit:
                change += 1
            return change
        if n < 6:
            change += to_remove
            if not lower:
                change += 1
                n += 1
            if not upper:
                change += 1
                n += 1
            if not digit:
                change += 1
                n += 1
            change += max(6 - n, 0)
            return change
        change += to_remove
        if not lower:
            change += 1
        if not upper:
            change += 1
        if not digit:
            change += 1
        return change

print(Solution().strongPasswordChecker("aaa111"))
print(Solution().strongPasswordChecker("1111111111"))
