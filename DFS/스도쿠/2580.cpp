#include <iostream>
#include <vector>
#include <utility>
#include <cstdlib>

using namespace std;

int sudoku[9][9];
vector<pair<int, int>> arr;

bool chk_vertical(int c, int num) {
    for(int r = 0; r < 9; r ++) {
        if(sudoku[r][c] == num) {
            return false;
        }
    }
    return true;
}

bool chk_horizontal(int r, int num) {
    for(int c = 0; c < 9; c ++) {
        if(sudoku[r][c] == num) {
            return false;
        }
    }
    return true;
}

bool chk_square(int r, int c, int num) {
    r = r / 3;
    c = c / 3;
    for(int rr = r * 3; rr < (r * 3) + 3; rr ++) {
        for(int cc = c * 3 ; cc < (c * 3) + 3; cc ++) {
            if(sudoku[rr][cc] == num) {
                return false;
            }
        }
    }
    return true;
}

void dfs(int idx) {
    if(idx == arr.size()) {
        for(int i = 0; i < 9; i ++) {
            for(int j = 0; j < 9; j ++) {
                cout << sudoku[i][j] << " ";
            }
            cout << "\n";
        }
        exit(0);
    }

    for(int num = 1; num <= 9; num ++) {
        int r = arr[idx].first;
        int c = arr[idx].second;

        if(chk_vertical(c, num) && chk_horizontal(r, num) && chk_square(r, c, num)) {
            sudoku[r][c] = num;
            dfs(idx + 1);
            sudoku[r][c] = 0;
        }
    }
}

int main() {
    for(int i = 0; i < 9; i ++) {
        for(int j = 0; j < 9; j ++) {
            cin >> sudoku[i][j];
            if(sudoku[i][j] == 0) {
                arr.push_back({ i, j });
            }
        }
    }
    for(int num = 1; num <= 9; num ++) {
        int r = arr[0].first;
        int c = arr[0].second;

       if(chk_vertical(c, num) && chk_horizontal(r, num) && chk_square(r, c, num)) {
           sudoku[r][c] = num;
           dfs(1);
           sudoku[r][c] = 0;
       }
    }
    return 0;
}
