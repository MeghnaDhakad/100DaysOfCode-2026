#include <iostream>
#include <stack>
using namespace std;

stack<int> copyStack(stack<int> st) {
    stack<int> temp, ans;

    // Reverse original into temp
    while (!st.empty()) {
        temp.push(st.top());
        st.pop();
    }

    // Restore order into ans
    while (!temp.empty()) {
        ans.push(temp.top());
        temp.pop();
    }

    return ans;
}

int main() {
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    stack<int> copied = copyStack(st);

    while (!copied.empty()) {
        cout << copied.top() << " ";
        copied.pop();
    }

    return 0;
}