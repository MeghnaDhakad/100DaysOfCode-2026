#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Job {
    int id;
    int deadline;
    int profit;
};

// Comparator to sort jobs by profit in descending order
bool compareJobs(const Job& a, const Job& b) {
    return a.profit > b.profit;
}

int maxJobProfit(const vector<int>& deadlines, const vector<int>& profits) {
    int n = deadlines.size();
    if (n == 0) return 0;

    vector<Job> jobs(n);
    int maxDeadline = 0;

    // Bundle data and find the maximum deadline
    for (int i = 0; i < n; ++i) {
        jobs[i] = {i + 1, deadlines[i], profits[i]};
        maxDeadline = max(maxDeadline, deadlines[i]);
    }

    // Step 1: Sort jobs primarily by highest profit
    sort(jobs.begin(), jobs.end(), compareJobs);

    // Step 2: Create time slots (1-indexed for simplicity)
    vector<int> slots(maxDeadline + 1, -1);
    int totalProfit = 0;

    // Step 3: Greedily schedule each job as close to its deadline as possible
    for (int i = 0; i < n; ++i) {
        // Scan backwards from the job's deadline
        for (int j = jobs[i].deadline; j > 0; --j) {
            // If the slot is empty, schedule the job here
            if (slots[j] == -1) {
                slots[j] = jobs[i].id;
                totalProfit += jobs[i].profit;
                break; // Job scheduled, move to the next job
            }
        }
    }

    return totalProfit;
}

int main() {
    vector<int> deadline = {4, 1, 1, 1};
    vector<int> profit = {20, 10, 40, 30};
    
    cout << "Output: " << maxJobProfit(deadline, profit) << "\n";
    // Expected Output: 60 (Job 3 at slot 1, Job 1 at slot 4)
    
    return 0;
}