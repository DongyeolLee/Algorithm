#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

struct fish {
    int r;
    int c;
    int size;
    int eat;
    int time;
};

int N;
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int map[21][21];
int visited[21][21];

queue<fish> q;
vector<fish> v;

bool cmp(fish a, fish b) {
    if (a.time <= b.time) {
        if (a.time == b.time) {
            if (a.r <= b.r) {
                if (a.r == b.r) {
                    if (a.c < b.c) {
                        return true;
                    }
                    return false;
                }
                return true;
            }
            return false;
        }
        return true;
    }
    return false;
}

int main() {
    cin >> N;
    fish ex;
    for (int r = 0; r < N; r++) {
        for (int c = 0; c < N; c++) {
            cin >> map[r][c];
            if (map[r][c] == 9) {
                map[r][c] = 0;
                ex = {r, c, 2, 0, 0};
            }
        }
    }
    int ans = 0;
    while (1) {
        v.clear();
        memset(visited, 0, sizeof(visited));
        visited[ex.r][ex.c] = 1;
        q.push(ex);

        while (!q.empty()) {
            int r = q.front().r;
            int c = q.front().c;
            int size = q.front().size;
            int eat = q.front().eat;
            int time = q.front().time;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int nr = r + dr[i];
                int nc = c + dc[i];
                if (nr >= 0 && nr < N && nc >= 0 && nc < N) {
                    if (!visited[nr][nc]) {
                        if (map[nr][nc] == 0 || map[nr][nc] == size) {
                            visited[nr][nc] = 1;
                            q.push({nr, nc, size, eat, time + 1});
                        } else if (map[nr][nc] < size) {
                            visited[nr][nc] = 1;
                            v.push_back({nr, nc, size, eat + 1, time + 1});
                        }
                    }
                }
            }
        }

        if (v.size() == 0) {
            break;
        }

        sort(v.begin(), v.end(), cmp);
        if (v[0].size == v[0].eat) {
            v[0].size++;
            v[0].eat = 0;
        }
        map[v[0].r][v[0].c] = 0;
        ans += v[0].time;
        ex = {v[0].r, v[0].c, v[0].size, v[0].eat, 0};
    }

    cout << ans;
    return 0;
}