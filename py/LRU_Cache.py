class Node:
    def __init__(self, key, val):
        self.key, self.val = key, val
        self.prev = self.next = None

class LRUCache:
    def __init__(self, capacity: int):
        self.cap = capacity
        self.cache = {}  # map key to node

        self.left, self.right = Node(0, 0), Node(0, 0)
        self.left.next, self.right.prev = self.right, self.left

    def remove(self, node):
        prev, nxt = node.prev, node.next
        prev.next, nxt.prev = nxt, prev

    def insert(self, node):
        prev, nxt = self.right.prev, self.right
        prev.next = nxt.prev = node
        node.next, node.prev = nxt, prev

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
        self.cache[key] = Node(key, value)
        self.insert(self.cache[key])

        if len(self.cache) > self.cap:
            lru = self.left.next
            self.remove(lru)
            del self.cache[lru.key]

import heapq
from collections import defaultdict


class stringRelplacement:
    def solution(self, s:str ) -> str:
        res = ""
        counter = defaultdict(int)
        for c in s:
            counter[ord(c)-ord('a')] += 1

        arr_c = [[-cnt, char] for cnt, char in counter.items()]

        heapq.heapify(arr_c)



        return res


"""
You are given a string s, rearrange the characters of s so that any two adjacent characters are not the same.

You can return any possible rearrangement of s or return "" if not posssible.

Example 1:

Input: s = "axyy"

freq y -2
     x -1
     a -1

use most frequent word
then cannot use the word we just previously used
then pick the second frequent word 
repeat until the heapq is empty 

Output: "xyay"

class Solution:
    def reorganizeString(self, s: str) -> str:
        count = Counter(s)
        maxHeap = [[-cnt, char] for char, cnt in count.items()]
        heapq.heapify(maxHeap)

        prev = None
        res = ""
        while maxHeap or prev:
            if prev and not maxHeap:
                return ""

            cnt, char = heapq.heappop(maxHeap)
            res += char
            cnt += 1

            if prev:
                heapq.heappush(maxHeap, prev)
                prev = None

            if cnt != 0:
                prev = [cnt, char]

        return res

"""


