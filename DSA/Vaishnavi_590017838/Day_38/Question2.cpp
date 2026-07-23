#include <iostream>
#include <vector>
#include <deque>
using namespace std;

vector<int> arrangeCards(int n) {
    deque<int> deck;
    for(int card = n; card >= 1; card--) {
        if(!deck.empty()) {
            deck.push_front(deck.back());
            deck.pop_back();
        }
        deck.push_front(card);
    }
    return vector<int>(deck.begin(), deck.end());
}

int main() {
    int n;
    cout << "Enter the number of cards: ";
    cin >> n;
    vector<int> result = arrangeCards(n);
    cout << "Initial arrangement: ";
    for(int card : result)
        cout << card << " ";
    return 0;
}
