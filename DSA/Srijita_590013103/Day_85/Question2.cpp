#include <bits/stdc++.h>
using namespace std;

int maxActivities(vector<int>& start, vector<int>& end) {
    int n = start.size();

    vector<pair<int, int>> activities;

    for (int i = 0; i < n; i++) {
        activities.push_back({end[i], start[i]});
    }

    sort(activities.begin(), activities.end());

    int count = 0;
    long long lastEnd = -1;

    for (auto &activity : activities) {
        int endTime = activity.first;
        int startTime = activity.second;

        if (startTime >= lastEnd) {
            count++;
            lastEnd = endTime;
        }
    }

    return count;
}