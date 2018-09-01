from string import ascii_letters, digits

class Solution:
    def isPalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        l = ascii_letters + digits
        letters = set(i for i in l)
        i = 0
        j = len(s) - 1
        while i < j:
            if s[i] not in letters:
                i += 1
                continue
            if s[j] not in letters:
                j -= 1
                continue
            if s[i].lower() != s[j].lower():
                return False
            i += 1
            j -= 1
        return True

print(Solution().isPalindrome('A man, a plan, a canal: Panama'))
print(Solution().isPalindrome('race a car'))
print(Solution().isPalindrome('0P'))
