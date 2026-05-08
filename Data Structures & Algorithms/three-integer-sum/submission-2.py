class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums = sorted(nums)
        res = []
        for i in range(len(nums)):
            find = nums[i] * -1
            j = i+1
            k = len(nums)-1

            if (i > 0) and (nums[i-1] == nums[i]):
                continue

            while j < k:
                if nums[j]+nums[k] == find:
                    res.append([nums[i], nums[j], nums[k]])
                    j+=1
                    while nums[j] == nums[j-1] and j<k:
                        j+=1
                    k-=1
                elif (nums[j]+nums[k]) < find:
                    j+=1
                elif (nums[j]+nums[k]) > find:
                    k-=1
        return res
                
