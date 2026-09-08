#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <climits>

pp
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int findKthSmallest(vector<int>& A, vector<int>& B, int k) {
        // Ensure A is the smaller array for efficient binary search
        if (A.size() > B.size()) return findKthSmallest(B, A, k);

        int n = A.size(), m = B.size();
        int low = max(0, k - m), high = min(k, n);

        while (low <= high) {
            int cutA = (low + high) / 2;
            int cutB = k - cutA;

            int leftA  = (cutA == 0) ? INT_MIN : A[cutA - 1];
            int leftB  = (cutB == 0) ? INT_MIN : B[cutB - 1];
            int rightA = (cutA == n) ? INT_MAX : A[cutA];
            int rightB = (cutB == m) ? INT_MAX : B[cutB];

            if (leftA <= rightB && leftB <= rightA) {
                // The k-th smallest is the max of the two "left" parts
                return max(leftA, leftB);
            } else if (leftA > rightB) {
                high = cutA - 1;
            } else {
                low = cutA + 1;
            }
        }
        return -1; // shouldn't reach here given valid constraints
    }
};

int main() {
    printf("Execution completed successfully.\n");
    return 0;
}
