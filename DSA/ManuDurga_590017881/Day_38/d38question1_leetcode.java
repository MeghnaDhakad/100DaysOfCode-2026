package Day_38;

import java.util.*;

public class d38question1_leetcode {
    
    public static int countStudents(int[] students, int[] sandwiches) {
        int c=0;;
        Stack<Integer> sandwich = new Stack<>();
        Queue<Integer> student = new LinkedList<>();
        for(int i:students){student.add(i);}
        for(int i= sandwiches.length-1;i>-1;i--){sandwich.push(sandwiches[i]);}
         for(int i=0; i<10*(sandwiches.length);i++){
            if(!sandwich.isEmpty()&&sandwich.peek()==student.peek()){
                sandwich.pop();
                student.poll();
                c++;
                System.out.print("Student POPPED ");
            }
            else if(!student.isEmpty()){student.add(student.remove());}
        }
        return students.length-c;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter Size of Array: ");
        int n = sc.nextInt();
        int[] Arr1 = new int[n];
        for(int i=0;i<n;i++){
            System.out.print(": ");
            Arr1[i]=sc.nextInt();}
        System.out.print("Enter Size of Array: ");
        n = sc.nextInt();
        int[] Arr2 = new int[n];
        for(int i=0;i<n;i++){
            System.out.print(": ");
            Arr2[i]=sc.nextInt();}
        System.out.print(countStudents(Arr1,Arr2));
        sc.close();
    }}

