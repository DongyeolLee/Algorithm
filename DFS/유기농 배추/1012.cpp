#include <iostream>
#include <cstring>

using namespace std;

int T, M, N, K;
int map[51][51];
int visited[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

int dfs(int r, int c) {
    for(int i = 0; i < 4; i ++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if(nextC >= 0 && nextR >= 0 && nextC < N && nextR < M) {
            if(map[nextR][nextC] && !visited[nextR][nextC]) {
                visited[nextR][nextC] = 1;
                dfs(nextR, nextC);
            }
        }
    }
    return 0;
}

int main() {
    cin >> T;
    while(T--) {
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cin >> M >> N >> K;
        for(int i = 0; i < K; i ++) {
            int r, c;
            cin >> r >> c;
            map[r][c] = 1;
        }
        int ans = 0;
        for(int i = 0; i < M; i ++) {
            for(int j = 0; j < N; j ++) {
                if(map[i][j] && !visited[i][j]) {
                    visited[i][j] = 1;
                    dfs(i, j);
                    ans ++;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
