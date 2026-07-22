package DSA.TanmaySharma_590011578.Day_38;

import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;

public class Question2 {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter the number of cards: ");
        int n = sc.nextInt();

        Queue<Integer> positions = new LinkedList<>();

        for (int i = 0; i < n; i++) {
            positions.offer(i);
        }

        int[] deck = new int[n];

        for (int card = 1; card <= n; card++) {
            int index = positions.poll();
            deck[index] = card;

            if (!positions.isEmpty()) {
                positions.offer(positions.poll());
            }
        }

        System.out.println("Initial deck arrangement:");

        for (int i = 0; i < n; i++) {
            System.out.print(deck[i] + " ");
        }

        sc.close();
    }
}