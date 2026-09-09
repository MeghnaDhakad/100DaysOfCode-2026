class Question1_leetcode {
      public static boolean lemonadeChange(int[] bills) {
 
        // We only ever need to keep track of how many $5 bills and $10 bills we have.
        // We never need to give $20 bills back as change (nobody pays with a $20
        // and expects a $20 back), so we don't even need to count them.
        int five = 0;   // how many $5 bills we currently have
        int ten = 0;    // how many $10 bills we currently have
 
        // Go through every customer's payment, one at a time, in order.
        for (int bill : bills) {
 
            // CASE 1: Customer pays with a $5 bill.
            // Lemonade costs $5, so no change is needed.
            // We just add this $5 to our pile.
            if (bill == 5) {
                five++;
            }
 
            // CASE 2: Customer pays with a $10 bill.
            // Lemonade costs $5, so we owe them $5 back.
            // We must give them one $5 bill as change.
            else if (bill == 10) {
                if (five > 0) {
                    // We have a $5 bill to give back. Do it.
                    five--;      // give away one $5 bill
                    ten++;       // keep the $10 bill we received
                } else {
                    // We have no $5 bills left to give as change. Fail.
                    return false;
                }
            }
 
            // CASE 3: Customer pays with a $20 bill.
            // Lemonade costs $5, so we owe them $15 back.
            // There are two ways to make $15:
            //   a) one $10 bill + one $5 bill  (preferred, since $10 bills
            //      are only useful for making $15, while $5 bills are more
            //      flexible and can be used to make change for $10 too)
            //   b) three $5 bills (only if we don't have a $10 bill)
            else { // bill == 20
                if (ten > 0 && five > 0) {
                    // Preferred option: use one $10 + one $5
                    ten--;
                    five--;
                } else if (five >= 3) {
                    // Backup option: use three $5 bills
                    five -= 3;
                } else {
                    // Not enough change available. Fail.
                    return false;
                }
                // Note: we don't need to track the $20 bill itself,
                // since it can never be used as change later.
            }
        }
 
        // If we successfully gave change to every customer, we succeed.
        return true;
    }
 
}