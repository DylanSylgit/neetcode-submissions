class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxArea = 0
        left = 0
        right = len(heights)-1

        while left < right:
            length = right - left
            height = min(heights[left],heights[right])
            area = length * height
            maxArea = max(maxArea,area)

            if heights[left] > heights[right]:
                right -=1
            elif heights[left] < heights[right]:
                left+=1
            else:
                left +=1
                right-=1
        return maxArea