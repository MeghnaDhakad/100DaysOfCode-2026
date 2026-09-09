class Solution {
    public boolean lemonadeChange(int[] bills) {
        int f=0; //five
        int t=0; //ten
        for(int b:bills){
            if(b==5){
                f++;
            } else if(b==10){
                if(f==0) return false;
                f--;
                t++;
            } else{
                if(f>0 && t>0){
                    f--;
                    t--;
                } else if(f>=3){
                    f-=3;
                } else{
                    return false;
                }
            }
        }
        return true;
    }
}