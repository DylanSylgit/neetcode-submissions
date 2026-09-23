class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        ret = []
        nums = sorted(nums)

        for i in range(len(nums)):
            a = nums[i]
            if i > 0 and nums[i-1] == a:
                continue
            left = i+1
            right = len(nums)-1

            while left < right:
                condition = (a + nums[left] + nums[right])
                if condition == 0:
                    ret.append([a,nums[left],nums[right]])
                    left +=1
                    right -=1
                    while (nums[left] == nums[left-1]) and left < right:
                        left +=1
                    while nums[right] == nums[right+1] and right > left:
                        right -=1
                elif condition < 0:
                    left+=1
                elif condition > 0:
                    right-=1
        return ret
                


            