#include <stdio.h>

int lemonadeChange(int bills[], int billsSize) {
    int five = 0;
    int ten = 0;

    for (int i = 0; i < billsSize; i++) {

        if (bills[i] == 5) {
            five++;
        }

        else if (bills[i] == 10) {
            if (five == 0)
                return 0;

            five--;
            ten++;
        }

        else {  // $20 bill
            if (ten > 0 && five > 0) {
                // Give $10 + $5
                ten--;
                five--;
            }
            else if (five >= 3) {
                // Give three $5 bills
                five -= 3;
            }
            else {
                return 0;
            }
        }
    }

    return 1;
}

int main() {
    int n;

    printf("Enter number of customers: ");
    scanf("%d", &n);

    int bills[n];

    printf("Enter the bills: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &bills[i]);
    }

    if (lemonadeChange(bills, n))
        printf("true\n");
    else
        printf("false\n");

    return 0;
}