class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int res=students.length;
        int cnt[]=new int[2];
        for(int s:students){
            cnt[s]++;
        }
        for(int d:sandwiches){
            if (cnt[d]>0){
                res--;
                cnt[d]--;
            } else{
                break;
            }
        }
        return res;
    }
}