class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        fart = {}

        for i in range(len(nums)):
            find = target - nums[i]

            if find in fart:
                return [fart[find],i]
            else:
                if nums[i] in fart:
                    fart[nums[i]].append(i)
                else:
                    fart[nums[i]] = i
