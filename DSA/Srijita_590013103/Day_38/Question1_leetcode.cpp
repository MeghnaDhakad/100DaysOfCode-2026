class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count[]={0,0};
        for(int stu : students){

            count[stu]++;

        }
        for(int sandwich: sandwiches){

            if(count[sandwich]==0){

                break;

            }

            count[sandwich]--;

        }
        
        return count[0]+count[1];
    }
};