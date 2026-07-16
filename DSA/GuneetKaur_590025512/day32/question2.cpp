#include <iostream>
#include <stack>
using namespace std;

void copyStack(stack<int> &st, stack<int> &newStack) {

    if (st.empty())
        return;
    int x = st.top();
    st.pop();

    copyStack(st, newStack);
    st.push(x);
    newStack.push(x);
}

int main() {
    stack<int> st;
    stack<int> newStack;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    copyStack(st, newStack);

    cout << "Copied Stack (Top to Bottom): ";

    while (!newStack.empty()) {
        cout << newStack.top() << " ";
        newStack.pop();
    }

    return 0;
}