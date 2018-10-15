#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <utility>
using namespace std;

int N, M, ans = 987654321;
int map[10][10];
int temp[10][10];
int dir[10];

int dr1[4] = {-1, 0, 1, 0};
int dc1[4] = {0, 1, 0, -1};

int dr2[2] = {-1, 0};
int dc2[2] = {0, 1};
int dr22[2] = {1, 0};
int dc22[2] = {0, -1};

int dr3[4] = {-1, 0, 1, 0};
int dc3[4] = {0, 1, 0, -1};
int dr33[4] = {0, 1, 0, -1};
int dc33[4] = {1, 0, -1, 0};

int dr4[4] = {-1, 0, 1, 0};
int dc4[4] = {0, 1, 0, -1};
int dr44[4] = {0, 1, 0, -1};
int dc44[4] = {1, 0, -1, 0};
int dr444[4] = {0, -1, 0, 1};
int dc444[4] = {-1, 0, 1, 0};

struct info {
    int rr;
    int cc;
    int num;
};

vector<info> v;
vector<info> barrier;

void dfs(int num) {
    if(num == v.size()) {
        memset(temp, 0, sizeof(temp));
        for(int i = 0; i < barrier.size(); i++) {
            temp[barrier[i].rr][barrier[i].cc] = 6;
        }
        for(int i = 0; i < v.size(); i ++) {
            int dd = dir[i];
            int nnum = v[i].num;
            temp[v[i].rr][v[i].cc] = 7;

            switch (nnum) {
                case 1 : {
                    int nc = v[i].cc + dc1[dd];
                    int nr = v[i].rr + dr1[dd];
                    while (temp[nr][nc] != 6 && nr >= 0 && nr < N && nc >= 0 && nc < M) {
                        temp[nr][nc] = 7;
                        nr = nr + dr1[dd];
                        nc = nc + dc1[dd];
                    }
                }
                break;
                case 2 : {
                    dd = dd % 2;
                    int nr1 = v[i].rr + dr2[dd];
                    int nc1 = v[i].cc + dc2[dd];
                    int nr2 = v[i].rr + dr22[dd];
                    int nc2 = v[i].cc + dc22[dd];

                    while (temp[nr1][nc1] != 6 && nr1 >= 0 && nr1 < N && nc1 >= 0 && nc1 < M) {
                        temp[nr1][nc1] = 7;
                        nr1 = nr1 + dr2[dd];
                        nc1 = nc1 + dc2[dd];
                    }
                    while (temp[nr2][nc2] != 6 && nr2 >= 0 && nr2 < N && nc2 >= 0 && nc2 < M) {
                        temp[nr2][nc2] = 7;
                        nr2 = nr2 + dr22[dd];
                        nc2 = nc2 + dc22[dd];
                    }
                }
                break;

                case 3 : {
                    int nr1 = v[i].rr + dr3[dd];
                    int nc1 = v[i].cc + dc3[dd];
                    int nr2 = v[i].rr + dr33[dd];
                    int nc2 = v[i].cc + dc33[dd];

                    while (temp[nr1][nc1] != 6 && nr1 >= 0 && nr1 < N && nc1 >= 0 && nc1 < M) {
                        temp[nr1][nc1] = 7;
                        nr1 = nr1 + dr3[dd];
                        nc1 = nc1 + dc3[dd];
                    }
                    while (temp[nr2][nc2] != 6 && nr2 >= 0 && nr2 < N && nc2 >= 0 && nc2 < M) {
                        temp[nr2][nc2] = 7;
                        nr2 = nr2 + dr33[dd];
                        nc2 = nc2 + dc33[dd];
                    }
                }
                break;

                case 4 : {
                    int nr1 = v[i].rr + dr4[dd];
                    int nc1 = v[i].cc + dc4[dd];
                    int nr2 = v[i].rr + dr44[dd];
                    int nc2 = v[i].cc + dc44[dd];
                    int nr3 = v[i].rr + dr444[dd];
                    int nc3 = v[i].cc + dc444[dd];

                    while (temp[nr1][nc1] != 6 && nr1 >= 0 && nr1 < N && nc1 >= 0 && nc1 < M) {
                        temp[nr1][nc1] = 7;
                        nr1 = nr1 + dr4[dd];
                        nc1 = nc1 + dc4[dd];
                    }
                    while (temp[nr2][nc2] != 6 && nr2 >= 0 && nr2 < N && nc2 >= 0 && nc2 < M) {
                        temp[nr2][nc2] = 7;
                        nr2 = nr2 + dr44[dd];
                        nc2 = nc2 + dc44[dd];
                    }
                    while (temp[nr3][nc3] != 6 && nr3 >= 0 && nr3 < N && nc3 >= 0 && nc3 < M) {
                        temp[nr3][nc3] = 7;
                        nr3 = nr3 + dr444[dd];
                        nc3 = nc3 + dc444[dd];
                    }
                }
                break;
                case 5 : {
                    int nrr = v[i].rr;
                    int ncc = v[i].cc;

                    while (temp[nrr][ncc] != 6 && nrr >= 0 && nrr < N && ncc >= 0 && ncc < M) {
                        temp[nrr][ncc] = 7;
                        nrr--;
                    }

                    nrr = v[i].rr;
                    ncc = v[i].cc;
                    while (temp[nrr][ncc] != 6 && nrr >= 0 && nrr < N && ncc >= 0 && ncc < M) {
                        temp[nrr][ncc] = 7;
                        nrr++;
                    }

                    nrr = v[i].rr;
                    ncc = v[i].cc;
                    while (temp[nrr][ncc] != 6 && nrr >= 0 && nrr < N && ncc >= 0 && ncc < M) {
                        temp[nrr][ncc] = 7;
                        ncc--;
                    }
                    nrr = v[i].rr;
                    ncc = v[i].cc;
                    while (temp[nrr][ncc] != 6 && nrr >= 0 && nrr < N && ncc >= 0 && ncc < M) {
                        temp[nrr][ncc] = 7;
                        ncc++;
                    }
                }
                break;
            }
        }
        int cnt = 0;
        for(int r = 0; r < N; r ++) {
            for(int c = 0; c < M; c ++) {
                if(temp[r][c] == 0) {
                    cnt ++;
                }
            }
        }
        ans = min(ans, cnt);
        return;
    }

    for(int i = 0; i < 4; i ++) {
        dir[num] = i;
        dfs(num + 1);
        dir[num] = -1;
    }
}

int main() {
    cin >> N >> M;
    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {
            cin >> map[r][c];
            if(map[r][c] != 6 && map[r][c] != 0) {
                v.push_back({r, c, map[r][c]});
            }
            else if(map[r][c] == 6) {
                barrier.push_back({r, c, 0});
            }
        }
    }

    dfs(0);
    cout << ans;
    return 0;
}