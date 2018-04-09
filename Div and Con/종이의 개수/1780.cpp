#include <iostream>
#include <cstring>

using namespace std;

int N;
int map[2200][2200];
int ans[3];

bool check(int r, int c, int num) {
    int test = map[r][c];
    for(int i = r; i < r + num; i ++) {
        for(int j = c; j < c + num; j ++) {
            if(test != map[i][j])
                return false;
        }
    }
    return true;
}

int divide(int r, int c, int num) {
    if(check(r, c, num)) {
        ans[map[r][c]] += 1;
    } else {
        int newsize = num / 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                divide(r + newsize*i, c + newsize*j, newsize);
            }
        }
    }
    return 0;
}

int main() {
    cin >> N;
    memset(ans, 0, sizeof(ans));
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            int num;
            cin >> num;
            num ++;
            map[i][j] = num;
        }
    }

    divide(0, 0, N);

    cout << ans[0] << endl;
    cout << ans[1] << endl;
    cout << ans[2] << endl;
    return 0;
}