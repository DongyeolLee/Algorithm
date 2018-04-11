#include <iostream>
#include <cstring>

using namespace std;

int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int map[51][51];
int r, c, dir, nextR, nextC;
int N, M;
int clean, cnt;

int change_dir(int now) {
    if (now == 0) {
        return 3;
    }
    else if (now == 1) {
        return 0;
    }
    else if (now == 2) {
        return 1;
    }
    else {
        return 2;
    }
}

int main() {
    cin >> N >> M;
    cin >> r >> c >> dir;
    memset(map, 0, sizeof(map));
    for (int i = 0; i < N; i++){
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }
    cnt++;
    map[r][c] = 2;
    while (1) {
        int tdir = dir;
        for (int i = 0; i < 4; i++) {
            clean = 0;
            tdir = change_dir(tdir);
            nextR = r + dr[tdir];
            nextC = c + dc[tdir];

            if (nextC >= 0 && nextC < M && nextR >= 0 && nextR < N && map[nextR][nextC] == 0) {
                cnt += 1;
                dir = tdir;
                r = nextR;
                c = nextC;
                map[r][c] = 2;
                clean = 1;
                break;
            }
        }

        if (clean == 0) {
            if (dir == 0) {
                r++;
            }
            else if (dir == 1) {
                c--;
            }
            else if (dir == 2) {
                r--;
            }
            else if (dir == 3) {
                c++;
            }

            if (map[r][c] == 1) {
                break;
            }
        }
    }

    cout << cnt;
    return 0;
}
