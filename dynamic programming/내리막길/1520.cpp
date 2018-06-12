#include <iostream>
#include <cstring>

using namespace std;

int M, N;
int map[505][505];
int chk[505][505];
int dp[505][505];

int rr[4] = {-1, 0, 1, 0};
int cc[4] = {0, 1, 0, -1};

int dfs(int r, int c) {
    if(dp[r][c] != -1) {
        return dp[r][c] ;
    }
    if(r == M && N == c) {
        return 1;
    }

    dp[r][c] = 0;
    for(int i = 0; i < 4; i ++) {
        int nextR = r + rr[i];
        int nextC = c + cc[i];
        if(nextR >= 1 && nextC >= 1 && nextR <= M && nextC <= N) {
            if(!chk[nextR][nextC] && map[nextR][nextC] < map[r][c]) {
                chk[nextR][nextC] = 1;
                dp[r][c] += dfs(nextR, nextC);
                chk[nextR][nextC] = 0;
            }
        }
    }
    return dp[r][c];
}

int main() {
    cin >> M >> N;
    memset(dp, -1, sizeof(dp));
    for(int i = 1; i <= M; i ++) {
        for(int j = 1; j <= N; j++) {
            cin >> map[i][j];
        }
    }
    chk[1][1] = 1;
    dfs(1, 1);
    cout << dp[1][1];
    return 0;
}
