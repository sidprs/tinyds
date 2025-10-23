

class UnitConverter:
    def __init__(self, mp : list[tuple[str, int]]):
        """
        create adjacenceny List 
        """
        for src, dst in mp:
            if src not in adjlist:
                adjlist[src] = []
            if dst not in adjlist:
                adjlist[dst] = []
            adjlist[src].append(dst)

