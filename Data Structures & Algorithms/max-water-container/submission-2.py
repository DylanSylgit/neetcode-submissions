class Solution:
    def maxArea(self, heights: List[int]) -> int:
        maxA = 0

        start = 0
        end = len(heights)-1

        while start < end:
            height = min(heights[start],heights[end])
            length = end - start

            area = height * length

            if area > maxA:
                maxA = area

            
            if heights[start] < heights[end]:
                start+=1
            elif heights[start] > heights[end]:
                end-=1
            else:
                start+=1
                end-=1

        return maxA

