class Solution:
    def findContentChildren(self,g: List[int],s: List[int]) -> int:
        g.sort()
        s.sort()
        i=j=ans=0
        while (i<len(g) and j<len(s)):
            if (s[j]>=g[i]):
                ans=ans+1
                i=i+1
            j=j+1
        return ans
