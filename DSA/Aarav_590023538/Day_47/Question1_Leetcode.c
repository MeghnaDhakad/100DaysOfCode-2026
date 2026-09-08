#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>

pp
#include <vector>
#include <string>
#include <algorithm>
#include <numeric>
using namespace std;

class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<int> idx(n);
        iota(idx.begin(), idx.end(), 0);

        // Sort indices by score descending
        sort(idx.begin(), idx.end(), [&](int a, int b) {
            return score[a] > score[b];
        });

        vector<string> answer(n);
        for (int rank = 0; rank < n; rank++) {
            int athlete = idx[rank];
            if (rank == 0) answer[athlete] = "Gold Medal";
            else if (rank == 1) answer[athlete] = "Silver Medal";
            else if (rank == 2) answer[athlete] = "Bronze Medal";
            else answer[athlete] = to_string(rank + 1);
        }
        return answer;
    }
};

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
