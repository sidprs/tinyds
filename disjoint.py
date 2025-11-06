

class DisjointSet:
    def __init__(self, n):
        self.paren = {}
        self.height = {}
            
        # Disjoint(3)
        # creates 3 nodes with each parent pointing at
        for i in range(1, n+1):
            self.paren[i] = i
            self.height[i] = 0


    def find(self, n):
        p = self.paren[n]

        while p != self.paren[p]:

            # path compression
            self.paren[p] = self.paren[self.paren[p]]
            p = self.paren[p]
        return p 


    def union(self, n1, n2):
        p1, p2 = self.find(n1), self.find(n2)

        if p1 == p2:
            return False
        
        if self.rank[p1] > self.rank[p2]:
            self.par[p2] = p1
        elif self.rank[p1] < self.rank[p2]:
            self.par[p1] = p2
        else:
            self.par[p1] = p2
            self.rank[p2] += 1
        return True


    def redudunantCycles(self):
        pass
    def connectedComponents(self):
        pass
