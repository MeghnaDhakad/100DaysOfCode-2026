pp
#include <bits/stdc++.h>
using namespace std;

string encryptGrid(const string& s) {
    string text;
    for (char c : s) if (c != ' ') text += c;
    int L = text.size();
    if (L == 0) return "";

    int cols = (int)ceil(sqrt((double)L));
    int rows = (int)ceil((double)L / cols);

    vector<string> grid(rows, string(cols, '\0'));
    int idx = 0;
    for (int r = 0; r < rows && idx < L; r++)
        for (int c = 0; c < cols && idx < L; c++)
            grid[r][c] = text[idx++];

    string result;
    for (int c = 0; c < cols; c++) {
        string col;
        for (int r = 0; r < rows; r++)
            if (grid[r][c] != '\0') col += grid[r][c];
        if (!col.empty()) {
            if (!result.empty()) result += ' ';
            result += col;
        }
    }
    return result;
}

int main() {
    string line;
    getline(cin, line);
    cout << encryptGrid(line) << "\n";
    return 0;
}
