bool lemonadeChange(int* bills, int billsSize) {
    int five = 0;
    int ten = 0;

    for (int i = 0; i < billsSize; i++) {

        if (bills[i] == 5) {
            five++;
        }

        else if (bills[i] == 10) {
            if (five == 0)
                return false;

            five--;
            ten++;
        }

        else if (bills[i] == 20) {

            // Prefer $10 + $5
            if (ten > 0 && five > 0) {
                ten--;
                five--;
            }

            // Otherwise use three $5 bills
            else if (five >= 3) {
                five -= 3;
            }

            else {
                return false;
            }
        }
    }

    return true;
}
