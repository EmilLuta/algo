'''
https://leetcode.com/problems/remove-duplicates-from-sorted-array/

Given a string containing only digits, restore it by returning all possible valid IP address combinations.

A valid IP address consists of exactly four integers (each integer is between 0 and 255) separated by single points.

Example:

Input: "25525511135"
Output: ["255.255.11.135", "255.255.111.35"]
'''

from itertools import combinations

class Solution:
    def _verify_part(self, p):
        if len(p) > 1 and p[0] == '0':
            return False
        return int(p) < 256
    
    def restoreIpAddresses(self, s: str) -> List[str]:
        n = len(s)
        answer = []
        if n > 12:
            return answer
        for comb in combinations(range(1, n), 3):
            a = s[:comb[0]]
            b = s[comb[0]:comb[1]]
            c = s[comb[1]:comb[2]]
            d = s[comb[2]:]
            if self._verify_part(a) and self._verify_part(b) and self._verify_part(c) and self._verify_part(d):    
                answer.append(f'{a}.{b}.{c}.{d}')
        return answer
