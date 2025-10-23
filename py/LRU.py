class Solution:
    def hasPathSum(self, root, targetSum: int) -> bool:
        def dfs(node, current_sum):
            if not node:
                return False
            
            # Add current node's value to sum
            current_sum += node.val
            
            # Check if it's a leaf node and sum matches target
            if not node.left and not node.right:
                return current_sum == targetSum
            
            # Recursively check left and right subtrees
            return dfs(node.left, current_sum) or dfs(node.right, current_sum)
        
        return dfs(root, 0)


# Alternative solution if you want to collect all paths
class SolutionWithPaths:
    def findPathsWithSum(self, root, targetSum: int):
        """Returns all root-to-leaf paths that sum to targetSum"""
        result = []
        
        def dfs(node, path, current_sum):
            if not node:
                return
            
            # Add current node to path and sum
            path.append(node.val)
            current_sum += node.val
            
            # If leaf node and sum matches, save the path
            if not node.left and not node.right:
                if current_sum == targetSum:
                    result.append(path[:])
            else:
                # Continue exploring
                dfs(node.left, path, current_sum)
                dfs(node.right, path, current_sum)
            
            # Backtrack
            path.pop()
        
        dfs(root, [], 0)
        return result



