#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int I, T;
int map[301][301];
int visited[301][301];
int dr[8] = {-1, -2, -2, -1, 1, 2, 2, 1};
int dc[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

struct location {
    int cr;
    int cc;
    int cnt;
};

queue<location> q;

int main() {
    cin >> T;
    while(T--) {
        int desR, desC, r, c;
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        while(!q.empty()){
            q.pop();
        }
        cin >> I;
        cin >> r >> c >> desR >> desC;
        location loc;
        loc.cr = r;
        loc.cc = c;
        loc.cnt = 0;
        visited[r][c] = 1;
        q.push(loc);
        while(!q.empty()) {
            int r = q.front().cr;
            int c = q.front().cc;
            int cnt = q.front().cnt;
            q.pop();
            if(r == desR && c == desC) {
                cout << cnt << endl;
                break;
            }
            for(int i = 0; i < 8; i ++) {
                int nextR = r + dr[i];
                int nextC = c + dc[i];
                if(nextC >= 0 && nextR >= 0 && nextC < I && nextR < I) {
                    if(!visited[nextR][nextC]) {
                        visited[nextR][nextC] = 1;
                        q.push({nextR, nextC, cnt + 1});
                    }
                }
            }
        }
    }
    return 0;
}