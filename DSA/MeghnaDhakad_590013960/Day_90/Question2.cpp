#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int videoStitching(vector<vector<int>>& clips, int time) {
    // Sort clips primarily by start time
    sort(clips.begin(), clips.end());
    
    int count = 0;
    int current_end = 0;
    int max_reach = 0;
    int i = 0;
    int n = clips.size();
    
    while (current_end < time) {
        // Find the clip that extends our reach the furthest, 
        // given it overlaps with our currently covered segment.
        while (i < n && clips[i][0] <= current_end) {
            max_reach = max(max_reach, clips[i][1]);
            i++;
        }
        
        // If we couldn't extend our reach, there's a gap we can't cross
        if (current_end == max_reach) {
            return -1; 
        }
        
        // Commit to the furthest reaching clip
        current_end = max_reach;
        count++;
    }
    
    return count;
}

int main() {
    vector<vector<int>> clips = {{0, 2}, {1, 6}, {4, 8}, {7, 10}, {9, 12}};
    int time = 10;
    
    cout << "Output: " << videoStitching(clips, time) << "\n";
    // Expected Output: 4
    
    return 0;
}