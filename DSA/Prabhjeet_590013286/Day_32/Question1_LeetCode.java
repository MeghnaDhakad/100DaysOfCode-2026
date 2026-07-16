/**
 * LeetCode 2696 - Minimum String Length After Removing Substrings
 * https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
 */

//Need to keep removing "AB" and "CD" until nothing is left

import java.util.Stack;

class Solution {

    public int minLength(String s) {

        Stack<Character> stack = new Stack<>();

        for (int i = 0; i < s.length(); i++) {

            char ch = s.charAt(i);

            // found one of the removable pairs
            if (!stack.isEmpty() &&
               ((stack.peek() == 'A' && ch == 'B') ||
                (stack.peek() == 'C' && ch == 'D'))) {

                stack.pop();

            } else {

                stack.push(ch);
            }
        }

        return stack.size();
    }
}