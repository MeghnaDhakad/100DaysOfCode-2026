class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> line;
        for(int student : students)
            line.push(student);
        int index = 0;
        int skipped = 0;
        while(!line.empty() && skipped < line.size()) {
            if(line.front() == sandwiches[index]) {
                line.pop();
                index++;
                skipped = 0;
            }
            else {
                line.push(line.front());
                line.pop();
                skipped++;
            }
        }
        return line.size();
    }
};
