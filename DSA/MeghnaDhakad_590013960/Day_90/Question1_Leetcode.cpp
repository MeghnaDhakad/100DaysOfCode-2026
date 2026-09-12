#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.empty()) return 0;
        
        // Sort balloons by their end coordinate
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });
        
        int arrows = 1;
        int currentEnd = points[0][1];
        
        for (int i = 1; i < points.size(); ++i) {
            // If the current balloon starts strictly after the previous end, 
            // the previous arrow can't reach it. We need a new arrow.
            if (points[i][0] > currentEnd) {
                arrows++;
                currentEnd = points[i][1];
            }
        }
        
        return arrows;
    }
};