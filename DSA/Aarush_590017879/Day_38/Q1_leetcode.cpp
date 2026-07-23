#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int countStudents(vector<int>& students, vector<int>& sandwiches) {
    queue<int> q;

    for (int student : students)
        q.push(student);

    int index = 0;
    int count = 0;

    while (!q.empty() && count < q.size()) {
        if (q.front() == sandwiches[index]) {
            q.pop();
            index++;
            count = 0;
        } else {
            q.push(q.front());
            q.pop();
            count++;
        }
    }

    return q.size();
}

int main() {
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << countStudents(students, sandwiches);

    return 0;
}