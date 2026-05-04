class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        prod = 1
        numZeros = 0
        res = []*len(nums)
        for i in range(len(nums)):
            if nums[i] == 0: 
                numZeros+=1
                continue
            prod = prod * nums[i]
        if numZeros > 1:
            return [0]*len(nums)

        if numZeros == 1:
                res = [0]*len(nums)
                res[nums.index(0)] = prod
                return res
            

        for i in range(len(nums)):
            res.append(prod//nums[i])
        return res
