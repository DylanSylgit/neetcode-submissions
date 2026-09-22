class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers)-1

        while i != j:
            left = numbers[i]
            right = numbers[j]
            x = left+right
            if x == target:
                return [i+1,j+1]
            if x > target:
                j -=1
            if x < target:
                i +=1