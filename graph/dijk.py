

from collections import defaultdict, deque
import heapq
class Dijkstra:
    def __self__(self, nodes:list[tuple[int]], weight:list[int]):
        self.weights = weight
        self.zip = zip(nodes, weight)
        self.nodes = nodes
        self.adjacencylist = defaultdict(list)
        for (src, dst) in nodes:
            if src or dst not in self.adjacencylist:
                self.adjacencylist[src].append(dst)

    def dijkstra(self, adjlist:defaultdict)->list[int]:
        pass