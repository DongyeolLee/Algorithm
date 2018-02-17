#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[701][701];
int leftAndTop[1500];

int main() {

    cin >> M >> N;

    memset(map, 0, sizeof(map));

    for(int i = 0; i < 2*M - 1; i ++) {
        leftAndTop[i] = 1;
    }

    for(int i = 0; i < N; i ++) {
        int zero, one, two;

        cin >> zero >> one >> two;

        for(int j = zero; j < zero + one; j ++) {
            leftAndTop[j] += 1;
        }

        for(int j = zero + one; j < 2*M - 1; j ++) {
            leftAndTop[j] += 2;
        }
    }

    int r = M - 1;
    int c = 0;
    for(int i = 0; i < 2*M - 1; i ++) {

        if(r == 0) {
            map[r][c] = leftAndTop[i];
            c++;
        } else {
            map[r][c] = leftAndTop[i];
            r--;
        }
    }

    for(int i = 1; i < M; i ++) {
        int temp = map[0][i];

        for(int j = 1; j < M; j ++) {
            map[j][i] = temp;
        }
    }

    for(int i = 0; i < M; i++) {
        for(int j = 0; j < M; j ++) {
            cout << map[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
