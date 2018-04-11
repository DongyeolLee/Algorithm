#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int N, M, ans = 0;
int temp[9][9];
int map[9][9];
int dr[4] = {0, 0, -1, 1};
int dc[4] = {1, -1, 0, 0};
vector<pair<int, int>> v;
queue<pair<int, int>> q;

int map_copy() {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            temp[i][j] = map[i][j];
        }
    }
    return 0;
}

int map_recover() {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            map[i][j] = temp[i][j];
        }
    }
    return 0;
}

int virus_count() {
    int cnt = 0;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            if(map[i][j] == 0){
                cnt ++;
            }
        }
    }
    ans = max(ans, cnt);
    return 0;
}

int dfs(int cnt) {
    if(cnt == 3) {
        map_copy();
        for(int a = 0; a < v.size(); a ++) {
            q.push(v[a]);
        }

        while(!q.empty()) {
            int r = q.front().first;
            int c = q.front().second;
            q.pop();

            for(int x = 0; x < 4; x ++) {
                int nextR = r + dr[x];
                int nextC = c + dc[x];

                if(map[nextR][nextC] == 0 && nextR >= 0 && nextR < N && nextC >= 0 && nextC < M) {
                    map[nextR][nextC] = 2;
                    q.push(make_pair(nextR, nextC));
                }
            }
        }
        virus_count();
        map_recover();
        return 0;
    }

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                dfs(cnt + 1);
                map[i][j] = 0;
            }
        }
    }
    return 0;
}

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            cin >> map[i][j];
            if(map[i][j] == 2) {
                v.push_back(make_pair(i, j));
            }
        }
    }

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j< M; j ++) {
            if(map[i][j] == 0) {
                map[i][j] = 1;
                dfs(1);
                map[i][j] = 0;
            }
        }
    }

    cout << ans;
    return 0;
}