"""
There are N network nodes, labelled 1 to N.

Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.

Now, we send a signal from a certain node K. How long will it take for all nodes to receive the signal? If it is impossible, return -1.

Example 1:

Input: times = [[2,1,1],[2,3,1],[3,4,1]], N = 4, K = 2
Output: 2

Note:

N will be in the range [1, 100].
K will be in the range [1, N].
The length of times will be in the range [1, 6000].
All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 0 <= w <= 100.
"""

import heapq

from collections import defaultdict
from typing import List

class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = defaultdict(list)
        for node in times:
            graph[node[0]].append((node[1], node[2]))
        parents = defaultdict(int)
        parents[K] = 0
        h = [(node[1], node[0], K) for node in graph[K]]
        heapq.heapify(h)
        while len(h) > 0:
            cost, node, parent = heapq.heappop(h)
            if node not in parents:
                parents[node] = cost
                for child_info in graph[node]:
                    if child_info not in parents:
                        heapq.heappush(h, (child_info[1] + parents[node], child_info[0], node))
        if len(parents) == N:
            return max(parents.values())
        return -1
