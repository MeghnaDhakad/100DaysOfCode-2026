class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        ans=0
        for i in range(0,len(nums),2):
            ans=ans+nums[i]
        return ans
