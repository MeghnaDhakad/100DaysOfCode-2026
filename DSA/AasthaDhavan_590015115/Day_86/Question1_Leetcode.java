class Solution {
    public int longestPalindrome(String s) {
       int []cnt=new int[128];
       for(char c:s.toCharArray()){
        cnt[c]++;
    
       } 
       int res=0;
       for(int i=0;i<128;i++){
        int val=cnt[i];
        res=res+(val/2)*2;
        if(res%2==0 && val%2==1){
            res++;
        }
       }
       return res;
    }
}