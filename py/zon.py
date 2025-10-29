class Solutions:
    def combinations(self, n:int, k:int)->list[list[int]]:
        results = []

        def backtrack(self, n, k, path):
            if len(path) == k:
                results.append(path)
                return
            if i > n:
                return
            
            path.append(i)
            backtrack(n+1, k, path)
            path.pop()
            backtrack(n+1, k, path)
        backtrack(1, [], n, k)
