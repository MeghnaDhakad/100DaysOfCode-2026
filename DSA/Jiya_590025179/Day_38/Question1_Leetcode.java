class Solution {
    public int countStudents(int[] stu,int[] sand) {
        int[] count=new int[2];
        for(int i=0;i<stu.length;i++) count[stu[i]]++;
        for(int i=0;i<sand.length;i++){
            if(count[sand[i]]==0) return sand.length-i;
            count[sand[i]]--;
        }
        return 0;
    }
}
