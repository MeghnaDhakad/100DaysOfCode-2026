#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        // Step 1: Sort the array
        sort(nums.begin(), nums.end());
        
        int maxSum = 0;
        
        // Step 2: Sum the elements at even indices
        for (int i = 0; i < nums.size(); i += 2) {
            maxSum += nums[i];
        }
        
        return maxSum;
    }
};