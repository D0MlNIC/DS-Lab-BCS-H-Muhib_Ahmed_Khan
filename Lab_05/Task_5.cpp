#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &sud, int r, int c, int num) {

    for (int x = 0; x <= 8; x++)
        if (sud[r][x] == num)
            return false;

    for (int x = 0; x <= 8; x++)
        if (sud[x][c] == num)
            return false;

    int sr = r - (r % 3), sc = c - (c % 3);

    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            if (sud[i + sr][j + sc] == num)
                return false;

    return true;
}

bool solveSudRecursively(vector<vector<int>> &sud, int r, int c) {
    int n = sud.size();

    if (r == n - 1 && c == n)
        return true;

    if (c == n) {
        r++;
        c = 0;
    }

    if (sud[r][c] != 0)
        return solveSudRecursively(sud, r, c + 1);

    for (int num = 1; num <= n; num++) {
        if (isSafe(sud, r, c, num)) {
            sud[r][c] = num;
            if (solveSudRecursively(sud, r, c + 1))
                return true;
            sud[r][c] = 0;
        }
    }
  
  	return false;
}

int main() {
    vector<vector<int>> sud = {
        {0, 0, 0, 2, 6, 0, 7, 0, 1},
        {6, 8, 0, 0, 7, 0, 0, 9, 0},
        {1, 9, 0, 0, 0, 4, 5, 0, 0},
        {8, 2, 0, 1, 0, 0, 0, 4, 0},
        {0, 0, 4, 6, 0, 2, 9, 0, 0},
        {0, 5, 0, 0, 0, 3, 0, 2, 8},
        {0, 0, 9, 3, 0, 0, 0, 7, 4},
        {0, 4, 0, 0, 5, 0, 0, 3, 6},
        {7, 0, 3, 0, 1, 8, 0, 0, 0}
    };


  	solveSudRecursively(sud, 0, 0);
    
  	for (int i = 0; i < sud.size(); i++) {
        for (int j = 0; j < sud.size(); j++)
            cout << sud[i][j] << " ";
        cout << endl;
    }

    return 0;
}