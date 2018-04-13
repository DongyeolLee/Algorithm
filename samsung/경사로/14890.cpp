#include <iostream>
#include <cstring>

using namespace std;

int N, L;
int chk[101][101];
int arr_copy[101][101];

bool checkR(int r, int c, int cnt) {
    int start = arr_copy[r][c];
    for(int i = c; i < c+cnt; i ++) {
        if(start != arr_copy[r][i] || chk[r][i] == 1){
            return false;
        }
    }
    return true;
}

bool checkC(int r, int c, int cnt) {
    int start = arr_copy[r][c];
    for(int i = r; i < r+cnt; i ++) {
        if(start != arr_copy[i][c] || chk[i][c] == 1){
            return false;
        }
    }
    return true;
}

void establishRow(int r, int c, int cnt) {
    for(int i = c; i < c+cnt; i ++) {
        chk[r][i] = 1;
    }
}

void establishColumn(int r, int c, int cnt) {
    for(int i = r; i < r+cnt; i ++) {
        chk[i][c] = 1;
    }
}

int main() {
    cin >> N >> L;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            cin >> arr_copy[i][j];
        }
    }

    int cnt = 0;
    for(int r = 0; r < N; r ++) {
        if(checkR(r, 0, N)) {
            cnt++;
        } else {
            int startHeight = arr_copy[r][0];
            for(int c = 0; c < N; c ++) {
                if(startHeight != arr_copy[r][c]) {
                    if(startHeight - arr_copy[r][c] == 1) {
                        // 내리막 길이 체크
                        if(checkR(r, c, L)) {
                            establishRow(r, c, L);
                            c += L - 1;
                            startHeight --;
                        } else {
                            break;
                        }
                    } else if(startHeight - arr_copy[r][c] == -1) {
                        if(checkR(r, c - L, L)) {
                            startHeight ++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if(startHeight == arr_copy[r][c] && c == N - 1) {
                    cnt ++;
                }
            }
        }
    }

    memset(chk, 0, sizeof(chk));

    for(int c = 0; c < N; c ++) {
        if(checkC(0, c, N)) {
            cnt++;
        } else {
            int startHeight = arr_copy[0][c];
            for(int r = 0; r < N; r ++) {

                if(startHeight != arr_copy[r][c]) {
                    if(startHeight - arr_copy[r][c] == 1) {
                        // 내리막 길이 체크
                        if(checkC(r, c, L)) {
                            establishColumn(r, c, L);
                            r += L - 1;
                            startHeight --;
                        } else {
                            break;
                        }
                    } else if(startHeight - arr_copy[r][c] == -1) {
                        if(checkC(r - L, c, L)) {
                            startHeight ++;
                        } else {
                            break;
                        }
                    } else {
                        break;
                    }
                }
                if(startHeight == arr_copy[r][c] && r == N - 1) {
                    cnt ++;
                }
            }
        }
    }
    cout << cnt;
    return 0;
}
