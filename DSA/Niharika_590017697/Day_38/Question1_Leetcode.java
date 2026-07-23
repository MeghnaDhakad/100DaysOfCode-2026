class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] c = new int[2];
        for (int student : students) 
        {
            c[student]++;
        }

        for (int sandwich : sandwiches) 
        {
            if (c[sandwich] == 0) 
            {
                break;
            }
            c[sandwich]--;
        }
        return c[0] + c[1];
    }
}
