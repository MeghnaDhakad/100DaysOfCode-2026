class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        a=sorted(nums)
        return sum(a[::2])

        
