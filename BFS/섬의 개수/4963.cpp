#include <iostream>
#include <cstring>

using namespace std;

int h, w;
int map[50][50];
int visited[50][50];
// 동 북 남 서
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, -1, 0, 1};
// 대각선 방향
int dx2[4] = {1, 1, -1, -1};
int dy2[4] = {1, -1, -1, 1};

int dfs(int i, int j) {

    visited[i][j] = 1;

    for(int k = 0; k < 4; k ++) {
        // 지도 범위 체크
        if(j + dx[k] >= 0 && j + dx[k] < w && i + dy[k] >= 0 && i + dy[k] < h) {
            // 땅이면서 방문하지 않았는지 체크
            if(map[i + dy[k]][j + dx[k]] && !visited[i + dy[k]][j + dx[k]])
                dfs(i + dy[k], j + dx[k]);
        }
    }

    for(int k = 0; k < 4; k ++) {
        if(j + dx2[k] >= 0 && j + dx2[k] < w && i + dy2[k] >= 0 && i + dy2[k] < h) {
            if(map[i + dy2[k]][j + dx2[k]] && !visited[i + dy2[k]][j + dx2[k]])
                dfs(i + dy2[k], j + dx2[k]);
        }
    }

    return 0;
}

int main() {

    while(1) {

        cin >> w >> h;

        if(w == 0 && h == 0)
            break;

        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                cin >> map[i][j];
            }
        }

        int cnt = 0;
        for(int i = 0; i < h; i ++) {
            for(int j = 0; j < w; j ++) {
                if(map[i][j] && !visited[i][j]) {
                    cnt ++;
                    dfs(i, j);
                }
            }
        }

        cout << cnt << '\n';
    }

    return 0;
}
