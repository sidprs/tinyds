

hello my name is siya dubey
hello my 

from collections import defaultdict
class UnitConverter:
    def __init__(self, mp : list[tuple[str, int]]):
        """
        create adjacenceny List 
        """
        self.adjlist = defaultdict(list)
        for src, dst in mp:
            if src not in self.adjlist:
                self.adjlist[src] = []
            if dst not in self.adjlist:
                self.adjlist[dst] = []
            self.adjlist[src].append(dst)


