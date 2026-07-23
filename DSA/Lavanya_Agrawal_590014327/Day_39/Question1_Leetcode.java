import java.util.Scanner;

public class Question1_Leetcode {

    public static int timeRequiredToBuy(int[] tickets, int k) {

        int time = 0;

        while (tickets[k] > 0) {

            for (int i = 0; i < tickets.length; i++) {

                if (tickets[i] > 0) {
                    tickets[i]--;
                    time++;

                    if (tickets[k] == 0) {
                        return time;
                    }
                }
            }
        }

        return time;
    }

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        String ticketLine = sc.nextLine();
        String kLine = sc.nextLine();

        String numbers = ticketLine
                .replaceAll("[^0-9 ]", " ")
                .trim();

        String[] parts = numbers.split("\\s+");

        int[] tickets = new int[parts.length];

        for (int i = 0; i < parts.length; i++) {
            tickets[i] = Integer.parseInt(parts[i]);
        }

        int k = Integer.parseInt(
                kLine.replaceAll("[^0-9]", "")
        );

        int result = timeRequiredToBuy(tickets, k);

        System.out.println(result);

        sc.close();
    }
}