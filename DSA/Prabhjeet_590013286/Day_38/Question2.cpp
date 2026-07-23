//Need to reconstruct the original deck arrangement

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    int n = 4;

    vector<int> ans(n);
    queue<int> pos;

    for (int i = 0; i < n; i++)
    {
        pos.push(i);
    }

    for (int card = 1; card <= n; card++)
    {
        int index = pos.front();
        pos.pop();

        ans[index] = card;

        // move the next position to the back
        if (!pos.empty())
        {
            pos.push(pos.front());
            pos.pop();
        }
    }

    for (int x : ans)
    {
        cout << x << " ";
    }

    return 0;
}