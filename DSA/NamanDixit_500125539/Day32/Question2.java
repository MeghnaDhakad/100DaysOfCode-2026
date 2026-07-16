
import java.util.Scanner;
import java.util.Stack;

public class Question2 {

    public static void main(String[] args) {

        // Create Scanner object
        Scanner sc = new Scanner(System.in);

        // Create original stack
        Stack<Integer> original = new Stack<>();

        // Create copied stack
        Stack<Integer> copied = new Stack<>();

        // Create temporary stack
        Stack<Integer> temp = new Stack<>();

        // Input number of elements
        System.out.print("Enter number of elements: ");
        int n = sc.nextInt();

        // Input stack elements
        System.out.println("Enter stack elements:");

        for (int i = 0; i < n; i++) {
            original.push(sc.nextInt());
        }

        // Step 1:
        // Move all elements from original to temporary stack
        while (!original.isEmpty()) {
            temp.push(original.pop());
        }

        // Step 2:
        // Restore original stack
        // Also copy elements into copied stack
        while (!temp.isEmpty()) {

            // Remove top element from temporary stack
            int element = temp.pop();

            // Restore original stack
            original.push(element);

            // Copy into second stack
            copied.push(element);
        }

        // Print original stack
        System.out.println("Original Stack = " + original);

        // Print copied stack
        System.out.println("Copied Stack = " + copied);

        // Close Scanner
        sc.close();
    }
}
