#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <cmath>
using namespace std;

struct battery {
    int r;
    int c;
    int cover; // 범위
    int P; // 성능
};

struct data {
    int r;
    int c;
    int cnt;
};

int T, M, A, ans1, ans2; // M: 이동 횟수, A: 배터리 갯수
int dr[5] = {0, -1, 0, 1, 0};
int dc[5] = {0, 0, 1, 0, -1};
int visited[11][11];
vector<vector<int>> users;
vector<vector<vector<int>>> map;
vector<battery> batteries;
queue<data> q;

void init() {
    users.clear();
    map.clear();
    batteries.clear();
    users.assign(2, vector<int>(0, 0));
    map.assign(11, vector<vector<int>>(11, vector<int> (0, 0)));
    ans1 = 0;
    ans2 = 0;
}

void draw_battery() {
    for(int b = 0; b < batteries.size(); b ++) {
        int r = batteries[b].r;
        int c = batteries[b].c;
        int cover = batteries[b].cover;

        visited[r][c] = 1;
        map[r][c].push_back(b + 1);
        q.push({r, c, 0});
        while(!q.empty()) {
            int rr = q.front().r;
            int cc = q.front().c;
            int cnt = q.front().cnt;
            q.pop();

            if(cnt == cover) {
                while(!q.empty()) {
                    q.pop();
                }
                memset(visited, 0, sizeof(visited));
                break;
            }

            for(int i = 1; i <= 4; i ++) {
                int nr = rr + dr[i];
                int nc = cc + dc[i];

                if(nr < 10 && nr >= 0 && nc < 10 && nc >= 0) {
                    if(!visited[nr][nc]) {
                        visited[nr][nc] = 1;
                        map[nr][nc].push_back(b + 1);
                        q.push({nr, nc, cnt + 1});
                    }
                }
            }
        }
    }
}

void user_move() {
    int max_num = 0;
    if(map[0][0].size() > 0) {
        for(int b = 0; b < map[0][0].size(); b ++) {
            max_num = max(max_num, batteries[map[0][0][b] - 1].P);
        }
        ans1 += max_num;
    }

    max_num = 0;
    if(map[9][9].size() > 0) {
        for(int b = 0; b < map[9][9].size(); b ++) {
            max_num = max(max_num, batteries[map[9][9][b] - 1].P);
        }
        ans2 += max_num;
    }

    int r = 0, c =0, r2 = 9, c2 = 9;
    for(int tt = 0; tt < M; tt ++) {
        int nr = r + dr[users[0][tt]];
        int nc = c + dc[users[0][tt]];
        int nr2 = r2 + dr[users[1][tt]];
        int nc2 = c2 + dc[users[1][tt]];
        int user1_b_idx = -1, user1_p = 0, user2_b_idx = -1, user2_p = 0;

        for(int b = 0; b < map[nr][nc].size(); b ++) {
            if(user1_p < batteries[map[nr][nc][b] - 1].P) {
                user1_b_idx = map[nr][nc][b] - 1;
                user1_p = batteries[map[nr][nc][b] - 1].P;
            }
        }

        for(int b = 0; b < map[nr2][nc2].size(); b ++) {
            if(user2_p < batteries[map[nr2][nc2][b] - 1].P) {
                user2_b_idx = map[nr2][nc2][b] - 1;
                user2_p = batteries[map[nr2][nc2][b] - 1].P;
            }
        }

        if(user1_b_idx == user2_b_idx && user1_b_idx != -1 && user2_b_idx != -1) {
            if(map[nr][nc].size() == 1 && map[nr2][nc2].size() == 1) {
                user1_p /= 2;
                user2_p /= 2;
            }
            else {
                int t1 = -1, t2 = -1;
                for(int b = 0; b < map[nr][nc].size(); b ++) {
                    if(map[nr][nc][b] - 1 != user1_b_idx) {
                        if(batteries[map[nr][nc][b] - 1].P > t1) {
                            t1 = batteries[map[nr][nc][b] - 1].P;
                        }
                    }
                }

                for(int b = 0; b < map[nr2][nc2].size(); b ++) {
                    if(map[nr2][nc2][b] - 1 != user2_b_idx) {
                        if(batteries[map[nr2][nc2][b] - 1].P > t2) {
                            t2 = batteries[map[nr2][nc2][b] - 1].P;
                        }
                    }
                }

                if(t1 == 0) {
                    user2_p = t2;
                }
                else if(t2 == 0) {
                    user1_p = t1;
                }
                else {
                    if(t1 > t2) {
                        user1_p = t1;
                    }
                    else {
                        user2_p = t2;
                    }
                }
            }
        }

        ans1 += user1_p;
        ans2 += user2_p;
        r = nr, c = nc, r2 = nr2, c2 = nc2;
    }
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t ++) {
        init();
        cin >> M >> A;

        // 이동 경로 저장
        for(int u = 0; u < 2; u ++) {
            for(int m = 0; m < M; m ++) {
                int move;
                cin >> move;
                users[u].push_back(move);
            }
        }

        // 배터리 정보 입력
        for(int a = 0; a < A; a ++) {
            int r, c, cover, P;
            cin >> c >> r >> cover >> P;
            batteries.push_back({r - 1, c - 1, cover, P});
        }

        draw_battery();
        user_move();
        cout << '#' << t << ' ' << ans1 + ans2 << '\n';
    }
    return 0;
}
