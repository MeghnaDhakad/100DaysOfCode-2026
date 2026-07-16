//Need to copy one stack into another without changing the order

#include <iostream>
#include <stack>
using namespace std;

int main()
{
    stack<int> original;
    stack<int> temp;
    stack<int> copied;

    original.push(1);
    original.push(2);
    original.push(3);
    original.push(4);

    // first reverse the stack
    while (!original.empty())
    {
        temp.push(original.top());
        original.pop();
    }

    // restore original and build the copied stack
    while (!temp.empty())
    {
        original.push(temp.top());
        copied.push(temp.top());
        temp.pop();
    }

    while (!copied.empty())
    {
        cout << copied.top() << " ";
        copied.pop();
    }

    return 0;
}