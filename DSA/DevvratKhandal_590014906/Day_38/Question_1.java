import java.util.*;

public class Question_1 {

    public static int countStudents(int[] students, int[] sandwiches) {
        Queue<Integer> queue = new LinkedList<>();

        for (int student : students) {
            queue.add(student);
        }

        int sandwichIndex = 0;
        int attempts = 0;

        while (!queue.isEmpty() && attempts < queue.size()) {

            if (queue.peek() == sandwiches[sandwichIndex]) {
                queue.poll();
                sandwichIndex++;
                attempts = 0;
            } else {
                queue.add(queue.poll());
                attempts++;
            }
        }

        return queue.size();
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of students: ");
        int n = sc.nextInt();

        int[] students = new int[n];
        int[] sandwiches = new int[n];

        System.out.println("Enter student preferences (0 or 1):");
        for (int i = 0; i < n; i++) {
            students[i] = sc.nextInt();
        }

        System.out.println("Enter sandwich types (0 or 1):");
        for (int i = 0; i < n; i++) {
            sandwiches[i] = sc.nextInt();
        }

        int result = countStudents(students, sandwiches);

        System.out.println("Number of students unable to eat: " + result);

        sc.close();
    }
}