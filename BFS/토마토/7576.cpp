#include <iostream>
#include <cstring>
#include <queue>
#include <utility>

using namespace std;

int M, N;
int tomato[1000][1000];
int visited[1000][1000];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};

queue<pair<int, pair<int, int>>> q;
int main() {

    cin >> M >> N;

    memset(tomato, 0, sizeof(tomato));
    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            cin >> tomato[i][j];

            if(tomato[i][j] == 1) {
                visited[i][j] = 1;
                q.push(make_pair(i, make_pair(j, 1)));
            }
        }
    }

    while(!q.empty()) {
        int r = q.front().first;
        int c = q.front().second.first;
        int cnt = q.front().second.second;
        q.pop();

        for(int i = 0; i < 4; i ++) {
            int nextR = r + dr[i];
            int nextC = c + dc[i];

            if(nextC >= 0 && nextR >= 0 && nextR < N && nextC < M) {
                if (tomato[nextR][nextC] != -1 && visited[nextR][nextC] == 0) {
                    tomato[nextR][nextC] = 1;
                    visited[nextR][nextC] = cnt + 1;

                    q.push(make_pair(nextR, make_pair(nextC, cnt + 1)));
                }
            }
        }
    }

    int flag = 0;
    int ans = 0;
    for (int i = 0; i < N; ++i) {
        if(flag) {
            break;
        }

        for (int j = 0; j < M; ++j) {
            if (tomato[i][j] == 0) {
                cout << -1 << '\n';
                flag = 1;
                break;
            } else {
                ans = ans < visited[i][j] ? visited[i][j] : ans;
            }
        }
    }

    if(!flag)
        cout << ans-1;

    return 0;
}
