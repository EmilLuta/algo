class Solution:
    def networkDelayTime(self, times: List[List[int]], N: int, K: int) -> int:
        graph = defaultdict(list)
        for node in times:
            graph[node[0]].append((node[1], node[2]))
        h = [(0, K)]
        processed = set()
        distance = [float('inf')] * (N + 1)
        distance[K] = 0
        while len(h) > 0:
            cost, node = heapq.heappop(h)
            if node not in processed:
                processed.add(node)
                for nei, edge_cost in graph[node]:
                    if distance[nei] > distance[node] + edge_cost:
                        distance[nei] = distance[node] + edge_cost
                        heapq.heappush(h, (distance[nei], nei))
