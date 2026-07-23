class Solution {
    public int countStudents(int[] students, int[] sandwiches) {
        int[] c = new int[2];

        for (int x : students)
            c[x]++;

        for (int x : sandwiches) {
            if (c[x] == 0)
                break;
            c[x]--;
        }

        return c[0] + c[1];
    }
}