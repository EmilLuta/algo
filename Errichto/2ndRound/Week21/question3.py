"""
Given two strings str1 and str2 of the same length, determine whether you can transform str1 into str2 by doing zero or more conversions.

In one conversion you can convert all occurrences of one character in str1 to any other lowercase English character.

Return true if and only if you can transform str1 into str2.

 

Example 1:

Input: str1 = "aabcc", str2 = "ccdee"
Output: true
Explanation: Convert 'c' to 'e' then 'b' to 'd' then 'a' to 'c'. Note that the order of conversions matter.
Example 2:

Input: str1 = "leetcode", str2 = "codeleet"
Output: false
Explanation: There is no way to transform str1 to str2.
 

Note:

1 <= str1.length == str2.length <= 10^4
Both str1 and str2 contain only lowercase English letters.
"""

# V1 - Wrong - str1 = "abcdefghijklmnopqrstuvwxyz", str2 = "bcdefghijklmnopqrstuvwxyza" - Should be False

class Solution:
    def _get_ranges(self, a):
        n = len(a)
        ranges = []
        start = 0
        for i in range(1, n):
            if a[i] != a[i - 1]:
                ranges.append((start, i - 1))
                start = i
        ranges.append((start, n - 1))
        return ranges
    
    def canConvert(self, str1: str, str2: str) -> bool:
        n = len(str1)
        ranges = self._get_ranges(str2)
        for start, end in ranges:
            if start > 0:
                if str1[start] == str1[start - 1]:
                    return False
            if end < n - 1:
                if str1[end] == str1[end + 1]:
                    return False
        return True

# V2 - Wrong - str1 = "abcdefghijklmnopqrstuvwxyz", str2 = "bcdefghijklmnopqrstuvwxyzq" - Should be True

class Solution:
    def canConvert(self, str1: str, str2: str) -> bool:
        n = len(str1)
        d = {}
        if str1 == str2:
            return True
        for i in range(n):
            if str1[i] in d and d[str1[i]] != str2[i]:
                return False
            d[str1[i]] = str2[i]
        return True

# V3

class solution:
    def canconvert(self, str1: str, str2: str) -> bool:
        n = len(str1)
        d = {}
        if str1 == str2:
            return true
        if len(set(str2)) == 26:
            return false
        for i in range(n):
            if str1[i] in d and d[str1[i]] != str2[i]:
                return false
            d[str1[i]] = str2[i]
        return true

print(Solution().canConvert('abcdefghijklmnopqrstuvwxyz', 'bcdefghijklmnopqrstuvwxyza'))
