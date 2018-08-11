#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int r, c;
int map[301][301];
int visited[301][301];
int map_copied[301][301];
vector<pair<int, int>> ice;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

void dfs(int rr, int cc) {
    for(int a = 0; a < 4; a ++) {
        int nextR = rr + dr[a];
        int nextC = cc + dc[a];
        if(nextC >= 0 && nextR >= 0 && nextC < c && nextR < r) {
            if(map[nextR][nextC] > 0 && visited[nextR][nextC] != 1) {
                visited[nextR][nextC] = 1;
                dfs(nextR, nextC);
            }
        }
    }
}

int main() {
    cin >> r >> c;

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            cin >> map[i][j];

            if(map[i][j] > 0) {
                ice.push_back({i, j});
            }
        }
    }

    int year = 0;

    while(1) {
        memset(map_copied, 0, sizeof(map_copied));
        memset(visited, 0, sizeof(visited));
        year ++;

        for(int i = 0; i < ice.size(); i ++) {
            int rr = ice[i].first;
            int cc = ice[i].second;
            int cnt = 0;

            if(map[rr][cc] > 0) {
                for(int a = 0; a < 4; a ++) {
                    int nextR = rr + dr[a];
                    int nextC = cc + dc[a];

                    if(nextC >= 0 && nextR >= 0 && nextC < c && nextR < r) {
                        if(map[nextR][nextC] == 0) {
                            cnt ++;
                        }
                    }
                }
            }
            int num = map[rr][cc] - cnt;
            if(num > 0)
                map_copied[rr][cc] = num;
            else
                map_copied[rr][cc] = 0;
        }

        memcpy(map, map_copied, sizeof(map_copied));

        int ans = 0;
        for(int i = 0; i < r; i ++) {
            for(int j = 0; j < c; j ++) {
                if(map[i][j] > 0 && visited[i][j] != 1) {
                    visited[i][j] = 1;
                    dfs(i, j);
                    ans ++;
                }
            }
        }

        if(ans > 1) {
            cout << year;
            return 0;
        } else if(ans == 0) {
            cout << 0;
            return 0;
        }
    }
}
