#include <iostream>
#include <deque>
#include <vector>
using namespace std;

vector<int> cardTrick(int n) {
    deque<int> deck;

    for (int card = n; card >= 1; card--) {
        if (!deck.empty()) {
            deck.push_front(deck.back());
            deck.pop_back();
        }
        deck.push_front(card);
    }

    return vector<int>(deck.begin(), deck.end());
}

int main() {
    int n = 4;

    vector<int> ans = cardTrick(n);

    for (int x : ans)
        cout << x << " ";

    return 0;
}