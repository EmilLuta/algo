from typing import List

class Solution:
    def minDominoRotations(self, a: List[int], b: List[int]) -> int:
        counter = {}
        n = len(a)
        for i in range(n):
            counter.setdefault(a[i], [0, 0, 0])
            counter.setdefault(b[i], [0, 0, 0])
            if a[i] != b[i]:
                counter[b[i]][0] += 1
            counter[a[i]][0] += 1
            counter[a[i]][1] += 1
            counter[b[i]][2] += 1

        rotations_needed = float('-inf')
        for key in counter:
            if counter[key][0] == n:
                rotations_needed = max(rotations_needed, counter[key][1], counter[key][2])
        if rotations_needed != float('-inf'):
            return n - rotations_needed
        return -1

print(Solution().minDominoRotations([2,1,2,4,2,2], [5,2,6,2,3,2]))
