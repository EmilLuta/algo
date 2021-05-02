class Solution:
    def validPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] != s[j]:
                return self.is_palindrome(i + 1, j, s) or self.is_palindrome(i, j - 1, s)
            i += 1
            j -= 1
        return True

    def is_palindrome(self, i, j, s):
        while i < j:
            if s[i] != s[j]:
                return False
            i += 1
            j -= 1
        return True

print(Solution().validPalindrome('abcda'))
print(Solution().validPalindrome("aguokepatgbnvfqmgmlcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupuculmgmqfvnbgtapekouga"))
print(Solution().validPalindrome("lcupuufxoohdfpgjdmysgvhmvffcnqxjjxqncffvmhvgsymdjgpfdhooxfuupucul"))
print(Solution().validPalindrome("lcupuufuupucul"))
print(Solution().validPalindrome('tcaac'))
