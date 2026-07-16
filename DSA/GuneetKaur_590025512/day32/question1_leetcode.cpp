
#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char ch : s) {

            if (!st.empty() &&
                ((st.top() == 'A' && ch == 'B') ||
                 (st.top() == 'C' && ch == 'D'))) {

                st.pop();   // Remove AB or CD
            }
            else {
                st.push(ch);
            }
        }

        return st.size();
    }
};