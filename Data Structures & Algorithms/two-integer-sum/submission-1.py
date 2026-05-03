class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        fart = {}

        for i, n in enumerate(nums):
            diff = target - n

            if diff in fart:
                return [fart[diff],i]
            fart[n] = i
        