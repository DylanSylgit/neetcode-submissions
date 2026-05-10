class Solution:
    def trap(self, height: List[int]) -> int:
        left = 0
        right = len(height)-1

        maxL = height[left]
        maxR = height[right]

        res = 0

        while left < right:
            if maxL <= maxR:
                left+=1
                res += max(0, (maxL - height[left]))
                if maxL < height[left]: maxL = height[left]
            elif maxL > maxR:
                right-=1
                res += max(0,maxR-height[right])
                if maxR < height[right]: maxR = height[right]
        return res
