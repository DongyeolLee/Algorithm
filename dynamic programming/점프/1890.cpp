#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int N;
int map[100][100];
long long int dp[100][100];

long long int dfs(int r, int c) {
    if(r < 0 || c < 0 || r >= N || c >= N)
        return 0;
    if(dp[r][c] > 0) {
        return dp[r][c];
    }
    if(r == N - 1 && c == N - 1) {
        dp[r][c] = 1;
        return dp[r][c];
    }
    if(map[r][c] == 0) {
        return 0;
    }
    
    long long int num = dfs(r + map[r][c], c) + dfs(r, c + map[r][c]);

    dp[r][c] = num;
    return dp[r][c];
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            cin >> map[i][j];
        }
    }

    memset(dp, 0, sizeof(dp));
    cout << dfs(0, 0);
    return 0;
}
