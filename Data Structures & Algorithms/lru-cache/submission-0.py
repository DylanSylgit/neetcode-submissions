class node:
    def __init__(self, key, val):
        self.val = val
        self.key = key
        self.next = None
        self.prev = None

class LRUCache:

    def __init__(self, capacity: int):
        self.capacity = capacity
        self.cache = {}

        self.left, self.right = node(0,0), node(0,0)
        self.left.next = self.right
        self.right.prev = self.left

    def remove(self, node: node) -> None:
        prev, nxt = node.prev, node.next 
        prev.next, nxt.prev = nxt, prev

    def insert(self, node: node) -> None:
        p = self.right.prev
        p.next = node
        node.next = self.right
        node.prev = p
        self.right.prev = node

    def get(self, key: int) -> int:
        if key in self.cache:
            self.remove(self.cache[key])
            self.insert(self.cache[key])
            return self.cache[key].val
        return -1

    def put(self, key: int, value: int) -> None:
        if key in self.cache:
            self.remove(self.cache[key])
            self.cache[key].val = value
            self.insert(self.cache[key])
        else:
            self.cache[key] = node(key, value)
            self.insert(self.cache[key])
            
            if len(self.cache) > self.capacity:
                lru = self.left.next
                self.remove(lru)
                del self.cache[lru.key]