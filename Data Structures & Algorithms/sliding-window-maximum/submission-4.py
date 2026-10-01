from collections import deque
class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        if k > len(nums):
            return [max(nums)]

        l = 0
        r = 0
        ret = []
        local = deque()

        while r < k-1:
            while local and nums[local[-1]] < nums[r]:
                local.pop()
            local.append(r)
            r += 1
        while r < len(nums):
            while local and nums[local[-1]] < nums[r]:
                local.pop()
            local.append(r)
            ret.append(nums[local[0]])
            r +=1 
            l +=1
            if local and local[0] < l:
                local.popleft()
            
        return ret