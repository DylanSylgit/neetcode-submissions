class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        res = []
        for i in range(len(nums)):
            left = nums[:i]
            right = nums[i+1:]
            value1 = 1
            value2 = 1
            if len(left) != 0:
                for j in range(len(left)):
                    value1 = value1 * left[j]
            if len(right) !=0:
                for k in range(len(right)):
                    value2 = value2 * right[k]
            res.append(value2*value1)
        return res