from bisect import bisect_right
from typing import List


class Solution:
    def _hash_word(self, word: str) -> int:
        letter = "z"
        count = 0
        for c in word:
            if letter == c:
                count += 1
            elif letter > c:
                letter = c
                count = 1
        return count

    def numSmallerByFrequency(self, queries: List[str], words: List[str]) -> List[int]:
        n = len(words)
        values = []
        out = []
        for word in words:
            values.append(self._hash_word(word))
        values.sort()
        for query in queries:
            count = self._hash_word(query)
            out.append(n - bisect_right(values, count))
        return out


print(Solution().numSmallerByFrequency(["bba","abaaaaaa","aaaaaa","bbabbabaab","aba","aa","baab","bbbbbb","aab","bbabbaabb"], ["aaabbb","aab","babbab","babbbb","b","bbbbbbbbab","a","bbbbbbbbbb","baaabbaab","aa"]))
print(Solution().numSmallerByFrequency(["bbb", "cc"], ["a", "aa", "aaa", "aaaa"]))
print(Solution().numSmallerByFrequency(["cbd"], ["zaaaz"]))
