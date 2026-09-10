import java.util.*;

public class Main {

    static boolean lemonadeChange(int[] bills) {
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

            else { 
                if (ten > 0 && five > 0) {
                    ten--;
                    five--;
                }

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

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[] bills = new int[n];

        for (int i = 0; i < n; i++) {
            bills[i] = sc.nextInt();
        }

        System.out.println(lemonadeChange(bills));

        sc.close();
    }
}