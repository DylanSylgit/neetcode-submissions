class Solution:
    def minEatingSpeed(self, piles: List[int], h: int) -> int:
        left = 1
        right = max(piles)
        res = right

        while left<=right:
            k = (left+right) //2
            hoursSpent = self.helper(piles,k)
            if hoursSpent <= h:
                res = k
                right = k-1
            elif hoursSpent > h:
                left = k+1
        return res


    def helper(self, piles: List[int], k: int) -> int:
        hoursSpent = 0
        for pile in piles:
            hoursSpent += math.ceil(pile/k)
        return hoursSpent