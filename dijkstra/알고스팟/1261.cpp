#include<iostream>
#include <cstring>
#include <queue>
using namespace std;

int r, c;
int map[101][101];
int broken[101][101];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};

priority_queue<pair<int, pair<int, int>>> pq;

int main() {
    cin >> c >> r;
    memset(broken, -1, sizeof(broken));

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            scanf(" %1d", &map[i][j]);
        }
    }

    pq.push({0, {0, 0}});

    while(!pq.empty()) {
        int broken_cnt = -pq.top().first;
        int rr = pq.top().second.first;
        int cc = pq.top().second.second;
        pq.pop();

        if(broken[rr][cc] != -1) {
            continue;
        }

        broken[rr][cc] = broken_cnt;

        for(int i = 0; i < 4; i ++) {
            int nr = rr + dr[i];
            int nc = cc + dc[i];

            if(nr >= 0 && nc >= 0 && nr < r && nc < c) {
                if(broken[nr][nc] == -1) {
                    if(map[nr][nc] == 1) {
                        pq.push({-(broken_cnt + 1), {nr, nc}});
                    }
                    else {
                        pq.push({-broken_cnt, {nr, nc}});
                    }
                }
            }
        }
    }

    cout << broken[r-1][c-1];
    return 0;
}