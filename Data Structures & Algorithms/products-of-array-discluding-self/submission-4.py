class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        pre = 1
        post = 1
        for i in range(len(nums)):
            res[i] = res[i]*pre
            pre = pre*nums[i]
            res[len(nums)-1-i] = res[len(nums)-1-i]*post
            post = post*nums[len(nums)-1-i]
        
        return res