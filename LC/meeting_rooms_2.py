from collections import defaultdict

class Solution:

    def _overlaps(self, l1, l2):
        start = 0
        end = 1
        if l1[start] >= l2[end]:
            return False
        if l1[end] <= l2[start]:
            return False
        return True

    def minMeetingRooms(self, intervals: List[List[int]]) -> int:
        overlaps = defaultdict(int)
        for l1 in intervals:
            for l2 in intervals:
                if l1 == l2:
                    continue
                if self._overlaps(l1, l2):
                    overlaps[l1] += 1
        return max(overlaps.values())
