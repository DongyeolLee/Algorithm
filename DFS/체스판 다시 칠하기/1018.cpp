#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[51][51];
int map_copied[51][51];
int check[51][51];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
int sr, sc;
int cnt, ans = 987654321;

void brute(int r, int c, int num) {
    if(map_copied[r][c] != num) {
        map_copied[r][c] = num;
        cnt ++;
    }

    check[r][c] = 1;

    for(int i = 0; i < 4; i ++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];

        if(nextR >= sr && nextC >= sc && nextC < sc + 8 && nextR < sr + 8){
            if(!check[nextR][nextC]) {
                brute(nextR, nextC, -num);
            }
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            char temp;
            scanf(" %c", &temp);

            if(temp == 'W') {
                map[i][j] = 1;
            } else {
                map[i][j] = -1;
            }
        }
    }

    for(int i = 0; i < N - 7; i ++) {
        for(int j = 0; j < M - 7; j ++) {
            memcpy(map_copied, map, sizeof(map));
            memset(check, 0, sizeof(check));
            sr = i, sc = j, cnt = 0;
            brute(i, j, -1);
            ans = min(ans, cnt);

            memcpy(map_copied, map, sizeof(map));
            memset(check, 0, sizeof(check));
            cnt = 0;
            brute(i, j, 1);
            ans = min(ans, cnt);
        }
    }

    cout << ans;
    return 0;
}