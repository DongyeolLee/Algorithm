#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct location {
    int r;
    int c;
    int cnt;
};

int r, c, ans = -1;
char arr[51][51];
int visited[51][51];
int dr[4] = {-1 , 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
queue<location> q;

int main() {

    scanf("%d %d\n", &r, &c);

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            scanf("%c", &arr[i][j]);
        }
        getchar();
    }

    for(int i = 0; i < r; i ++) {
        for(int j = 0; j < c; j ++) {
            if(arr[i][j] == 'L') {
                memset(visited, 0, sizeof(visited));
                visited[i][j] = 1;
                q.push({i, j, 0});

                while(!q.empty()) {
                    int rr = q.front().r;
                    int cc = q.front().c;
                    int cnt = q.front().cnt;
                    ans = max(ans, cnt);
                    q.pop();

                    for(int a = 0; a < 4; a ++) {
                        int nextR = rr + dr[a];
                        int nextC = cc + dc[a];

                        if(nextC >= 0 && nextR >= 0 && nextC < c && nextR < r) {
                            if(arr[nextR][nextC] == 'L' && visited[nextR][nextC] != 1) {
                                visited[nextR][nextC] = 1;
                                q.push({nextR, nextC, cnt + 1});
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}
