#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int M, N, H;
int map[105][105][105];
int rr[4] = {-1 , 0, 1, 0};
int cc[4] = {0, 1, 0, -1};

struct tomato {
    int r;
    int c;
    int h;
    int cnt;
};

queue<tomato> q;

int main() {
    cin >> M >> N >> H;

    for(int h = 0; h < H; h++) {
        for(int i = 0; i < N; i ++){
            for(int j = 0; j < M; j ++) {
                cin >> map[i][j][h];

                if(map[i][j][h] == 1) {
                    q.push({i, j, h, 0});
                }
            }
        }
    }
    int ans = -1;
    while(!q.empty()) {
        int r = q.front().r;
        int c = q.front().c;
        int h = q.front().h;
        int cnt = q.front().cnt;
        ans = max(ans, cnt);
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nextR = r + rr[i];
            int nextC = c + cc[i];
            if(nextR >= 0 && nextC >= 0 && nextC < M && nextR < N && map[nextR][nextC][h] == 0) {
                map[nextR][nextC][h] = 1;
                q.push({nextR, nextC, h, cnt + 1});
            }
        }
        int up = h + 1;
        int down = h - 1;
        if(up < H) {
            if(map[r][c][up] == 0) {
                map[r][c][up] = 1;
                q.push({r, c, up, cnt + 1});
            }
        }
        if(down >= 0) {
            if(map[r][c][down] == 0) {
                map[r][c][down] = 1;
                q.push({r, c, down, cnt + 1});
            }
        }
    }

    for(int h = 0; h < H; h++) {
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < M; ++j) {
                if (map[i][j][h] == 0) {
                    cout << -1 << '\n';
                    return 0;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
