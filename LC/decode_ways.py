class Solution:
    def _is_double(self, a, b):
        if (a == '1' and b != '0') or (a == '2' and b > '0' and b < '7'):
            return True
        return False

    def _is_single(self, a, b):
        if b == '0' and (a == '1' or a == '2'):
            return True
        return False

    def _should_stop(self, a, b):
        if (a == b and a == '0') or (a > '2' and b == '0'):
            return True
        return False

    def numDecodings(self, s: str) -> int:
        n = len(s)
        if n == 0:
            return 0
        if s[0] == '0':
            return 0
        if n == 1:
            return 1
        dp = [1] * n
        if self._should_stop(s[0], s[1]):
            return 0
        if self._is_double(s[0], s[1]):
            dp[1] = 2
        for i in range(2, n):
            if self._should_stop(s[i - 1], s[i]):
                return 0
            elif self._is_single(s[i - 1], s[i]):
                dp[i] = dp[i - 2]
            elif self._is_double(s[i - 1], s[i]):
                dp[i] = dp[i - 2] + dp[i - 1]
            else:
                dp[i] = dp[i - 1]
        return dp[n - 1]


assert Solution().numDecodings('100') == 0
assert Solution().numDecodings('226') == 3
assert Solution().numDecodings('0') == 0
assert Solution().numDecodings('10') == 1
assert Solution().numDecodings('27') == 1
assert Solution().numDecodings('230') == 0
assert Solution().numDecodings('1212') == 5
assert (
    Solution().numDecodings(
        '4757562545844617494555774581341211511296816786586787755257741178599337186486723247528324612117156948'
    )
    == 589824
)
assert Solution().numDecodings('01') == 0
assert Solution().numDecodings('1') == 1
assert Solution().numDecodings('110') == 1
assert Solution().numDecodings('301') == 0
assert Solution().numDecodings('12120') == 3
