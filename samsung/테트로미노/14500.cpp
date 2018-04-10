#include <iostream>
#include <algorithm>

using namespace std;

int dr[4] = {1, 0, -1, 0};
int dc[4] = {0, 1, 0, -1};
int map[501][501];
int chk[501][501];
int N, M, ans = 0;

void check() {
    // ㅗ
    for(int i = 1; i < N; i ++) {
        for(int j = 1; j < M - 1; j ++) {
            int temp = map[i][j] + map[i - 1][j] + map[i][j - 1] + map[i][j + 1];
            ans = max(ans, temp);
        }
    }

    // ㅜ
    for(int i = 0; i < N - 1; i ++) {
        for(int j = 1; j < M - 1; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i][j - 1] + map[i][j + 1];
            ans = max(ans, temp);
        }
    }

    // ㅓ
    for(int i = 1; i < N - 1; i ++) {
        for(int j = 1; j < M; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j - 1];
            ans = max(ans, temp);
        }
    }

    // ㅏ
    for(int i = 1; i < N - 1; i ++) {
        for(int j = 0; j < M - 1; j ++) {
            int temp = map[i][j] + map[i + 1][j] + map[i - 1][j] + map[i][j + 1];
            ans = max(ans, temp);
        }
    }
}

void dfs(int r, int c, int cnt, int sum) {
    if(cnt == 4) {
        ans = max(ans, sum);
        return;
    }

    for(int i = 0; i < 4; i ++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if (nextR < N && nextR >= 0 && nextC < M && nextC >= 0 && chk[nextR][nextC] != 1) {
            chk[nextR][nextC] = 1;
            dfs(nextR, nextC, cnt + 1, sum + map[nextR][nextC]);
            chk[nextR][nextC] = 0;
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            chk[i][j] = 1;
            dfs(i, j, 1, map[i][j]);
            chk[i][j] = 0;
        }
    }

    check();
    cout << ans;
    return 0;
}
