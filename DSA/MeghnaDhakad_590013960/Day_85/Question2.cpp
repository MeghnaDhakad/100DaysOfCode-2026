#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// Struct to neatly group the start and end times
struct Activity {
    int start;
    int end;
};

// Custom comparator to sort activities by their end time
bool compareActivities(const Activity& a, const Activity& b) {
    return a.end < b.end;
}

int maxActivities(int n, const vector<int>& start, const vector<int>& end) {
    if (n == 0) return 0;

    vector<Activity> activities(n);
    for (int i = 0; i < n; i++) {
        activities[i] = {start[i], end[i]};
    }

    // Step 1: Sort activities by earliest end time
    sort(activities.begin(), activities.end(), compareActivities);

    int count = 1; // The first activity is always selected
    int last_end_time = activities[0].end;

    // Step 2: Greedily pick non-overlapping activities
    for (int i = 1; i < n; i++) {
        if (activities[i].start >= last_end_time) {
            count++;
            last_end_time = activities[i].end; // Update the busy schedule
        }
    }

    return count;
}

int main() {
    int n = 6;
    vector<int> start = {1, 3, 0, 5, 8, 5};
    vector<int> end = {2, 4, 6, 7, 9, 9};

    cout << "Output: " << maxActivities(n, start, end) << "\n";
    // Expected Output: 4
    
    return 0;
}