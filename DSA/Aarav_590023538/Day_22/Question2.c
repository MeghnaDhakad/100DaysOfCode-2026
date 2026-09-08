#include <stdio.h>
int main()
{
    int n;
    // Input number of cards
    scanf("%d", &n);
    int cards[n];
    // Input card values
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &cards[i]);
    }
    int left = 0;
    int right = n - 1;
    int player1 = 0;
    int player2 = 0;
    int turn = 0; // 0 -> Player 1, 1 -> Player 2
    // Continue until all cards are picked
    while (left <= right)
    {
        int picked;
        // Pick the larger value from either end
        if (cards[left] > cards[right])
        {
            picked = cards[left];
            left++;
        }
        else
        {
            picked = cards[right];
            right--;
        }
        // Add picked card to the current player's score
        if (turn == 0)
        {
            player1 += picked;
            turn = 1;
        }
        else
        {
            player2 += picked;
            turn = 0;
        }
    }
    // Print final scores
    printf("%d %d\n", player1, player2);
    return 0;
}
