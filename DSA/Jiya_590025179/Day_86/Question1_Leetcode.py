class Solution:
    def longestPalindrome(self,s:str)->int:
        f={}
        ans=0
        odd=0
        for i in s:
            f[i]=f.get(i,0)+1
        for j in f.values():
            ans=ans+(j//2)*2
            if j%2:
                odd=1
        return ans+odd
