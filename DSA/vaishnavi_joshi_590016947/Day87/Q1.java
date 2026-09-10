class Solution {
    public boolean lemonadeChange(int[] bills) {

        int five = 0;
        int ten = 0;

        for (int bill : bills) {

            if (bill == 5) {
                five++;
            }

            else if (bill == 10) {
                if (five == 0) {
                    return false;
                }

                five--;
                ten++;
            }

            else if (bill == 20) {

                // Give $10 + $5 as change
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

                // Otherwise give three $5 notes
                else if (five >= 3) {
                    five -= 3;
                }

                // Cannot give $15 change
                else {
                    return false;
                }
            }
        }

        return true;
    }
}