class Solution {
    public int countStudents(int[] students, int[] sandwiches) {

        int count0 = 0 , count1 = 0;

        for( int k = 0 ; k < students.length ; k++ ){

            if( students[k] == 0 ){
                count0++;
            }
            else{
                count1++;
            }
        }

        for( int i = 0 ; i < sandwiches.length ; i++ ){

            if( sandwiches[i] == 0 && count0 > 0 ){
                count0--;
            }
            else if( sandwiches[i]== 1 && count1 > 0 ){
                    count1--;
            }
            else{
                break;
            }

        }
        return count0+count1;
    }
}