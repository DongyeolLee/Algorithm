#include<iostream>
#include<vector>
#include<string>
#include<cstring>

using namespace std;


string input[100];
int mine[100][100];
int n, m;


void check(int i, int j) {
    if (i + 1 < n) {
        mine[i + 1][j]++;
        if(j+1 < m)
            mine[i + 1][j + 1]++;
        if(j-1 >= 0)
            mine[i + 1][j - 1]++;
    }

    if (j + 1 < m)
        mine[i][j + 1]++;

    if (j - 1 >= 0)
        mine[i][j - 1]++;

    if (i - 1 >= 0) {
        mine[i - 1][j]++;
        if (j + 1 < m)
            mine[i - 1][j + 1]++;
        if (j - 1 >= 0)
            mine[i - 1][j - 1]++;
    }

}

int main() {

    int cnt = 1;
    while (1) {
        cin >> n >> m;
        if (n == 0 && m == 0) {
            break;
        }

        if(cnt>=2)
            cout << endl;

        memset(mine, 0, sizeof(mine));

        for (int i = 0; i < n; i++) {
            cin >> input[i];
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (input[i][j] == '*') {
                    check(i, j); // if it is mine, set the matrix
                }
            }
        }

        printf("Field #%d:\n", cnt++);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (input[i][j] == '*')
                    printf("*");
                else
                    printf("%d", mine[i][j]);
            }
            printf("\n");
        }

    }
        return 0;
}
