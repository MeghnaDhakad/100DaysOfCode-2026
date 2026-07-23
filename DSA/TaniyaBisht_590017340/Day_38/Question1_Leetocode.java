
class Solution {
    public int countStudents(int[] st, int[] sa) {
        int st0 = 0;
        int st1 = 0;
        for(int choice : st){
            if(choice==0){
                st0++;
            }
            else{
            st1++;
            }
        }
        for(int sandwich : sa ){
            if(sandwich==0 && st0==0){
                return st1;
            }
            if(sandwich ==1 && st1==0){
                return st0;
            }
            if(sandwich==0){
                st0--;
            }
            else{
                st1--;
            }
        }
        return 0;
    }
}