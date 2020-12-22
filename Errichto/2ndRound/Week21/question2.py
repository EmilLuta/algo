"""
Given a set of points in the xy-plane, determine the minimum area of a rectangle formed from these points, with sides parallel to the x and y axes.

If there isn't any rectangle, return 0.

 

Example 1:

Input: [[1,1],[1,3],[3,1],[3,3],[2,2]]
Output: 4
Example 2:

Input: [[1,1],[1,3],[3,1],[3,3],[4,1],[4,3]]
Output: 2
 

Note:

1 <= points.length <= 500
0 <= points[i][0] <= 40000
0 <= points[i][1] <= 40000
All points are distinct.
"""

# V1

from collections import defaultdict
from typing import List

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        answer = float('inf')
        for p1 in points:
            for p2 in points:
                for p3 in points:
                    for p4 in points:
                        if p1 == p2 or p1 == p3 or p1 == p4 or p2 == p3 or p2 == p4 or p3 == p4:
                            continue
                        if p1[0] == p2[0] and p1[1] == p3[1] and p2[1] == p4[1] and p3[0] == p4[0]:
                            answer = min(answer, abs(p2[1] - p1[1]) * abs(p3[0] - p1[0]))
        return answer if answer != float('inf') else 0


# V2

from collections import defaultdict

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        answer = float('inf')
        x_axis = defaultdict(set)
        y_axis = defaultdict(set)
        for p in points:
            point = (p[0], p[1])
            x_axis[p[0]].add(point)
            y_axis[p[1]].add(point)
        for p1 in points:
            for p2 in points:
                if p1 == p2 or p1[0] == p2[0] or p1[1] == p2[1]:
                    continue
                potential_p3 = x_axis[p1[0]].intersection(y_axis[p2[1]])
                if len(potential_p3) == 0:
                    continue
                p3 = potential_p3.pop()
                potential_p4 = x_axis[p2[0]].intersection(y_axis[p1[1]])
                if len(potential_p4) == 0:
                    continue
                p4 = potential_p4.pop()
                answer = min(answer, abs(p2[1] - p1[1]) * abs(p2[0] - p1[0]))
        return answer if answer != float('inf') else 0

# V3

from collections import defaultdict

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        answer = float('inf')
        x_axis = defaultdict(set)
        y_axis = defaultdict(set)
        for p in points:
            point = (p[0], p[1])
            x_axis[p[0]].add(point[1])
            y_axis[p[1]].add(point[0])
        for p1 in points:
            for p2 in points:
                if p1 == p2 or p1[0] == p2[0] or p1[1] == p2[1]:
                    continue
                if p2[1] not in x_axis[p1[0]]:
                    continue
                if p1[1] not in x_axis[p2[0]]:
                    continue
                answer = min(answer, abs(p2[1] - p1[1]) * abs(p2[0] - p1[0]))
        return answer if answer != float('inf') else 0

# V4

from collections import defaultdict

class Solution:
    def minAreaRect(self, points: List[List[int]]) -> int:
        answer = float('inf')
        n = len(points)
        points.sort()
        x_axis = defaultdict(set)
        y_axis = defaultdict(set)
        for p in points:
            point = (p[0], p[1])
            x_axis[p[0]].add(point[1])
            y_axis[p[1]].add(point[0])
        for i in range(n):
            p1 = points[i]
            for j in range(i + 1, n):
                p2 = points[j]
                if p1 == p2 or p1[0] == p2[0] or p1[1] == p2[1]:
                    continue
                if p2[1] not in x_axis[p1[0]]:
                    continue
                if p1[1] not in x_axis[p2[0]]:
                    continue
                answer = min(answer, abs(p2[1] - p1[1]) * abs(p2[0] - p1[0]))
        return answer if answer != float('inf') else 0
