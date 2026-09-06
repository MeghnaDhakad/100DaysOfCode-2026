#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        // Step 1: Sort both arrays to enable the greedy choice
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int child_i = 0;
        int cookie_j = 0;
        
        // Step 2: Iterate with two pointers
        while (child_i < g.size() && cookie_j < s.size()) {
            // If the cookie satisfies the child, increment the child pointer
            if (s[cookie_j] >= g[child_i]) {
                child_i++;
            }
            // Always move to the next cookie (either it was used, or it was too small)
            cookie_j++;
        }
        
        return child_i; // The child pointer index represents the number of content children
    }
};