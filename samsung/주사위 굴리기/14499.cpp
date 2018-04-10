#include <iostream>

using namespace std;

int N, M, x, y, K;
int map[21][21];
int order[1001];
int dice[6];

void right() {
    int temp[6];
    for(int i = 0; i < 6; i ++){
        temp[i] = dice[i];
    }

    dice[0] = temp[5];
    dice[1] = temp[1];
    dice[2] = temp[4];
    dice[3] = temp[3];
    dice[4] = temp[0];
    dice[5] = temp[2];
}

void left() {
    int temp[6];
    for(int i = 0; i < 6; i ++){
        temp[i] = dice[i];
    }

    dice[0] = temp[4];
    dice[1] = temp[1];
    dice[2] = temp[5];
    dice[3] = temp[3];
    dice[4] = temp[2];
    dice[5] = temp[0];
}

void up() {
    int temp[6];
    for(int i = 0; i < 6; i ++){
        temp[i] = dice[i];
    }

    dice[0] = temp[1];
    dice[1] = temp[2];
    dice[2] = temp[3];
    dice[3] = temp[0];
    dice[4] = temp[4];
    dice[5] = temp[5];
}

void down() {
    int temp[6];
    for(int i = 0; i < 6; i ++){
        temp[i] = dice[i];
    }

    dice[0] = temp[3];
    dice[1] = temp[0];
    dice[2] = temp[1];
    dice[3] = temp[2];
    dice[4] = temp[4];
    dice[5] = temp[5];
}

int main() {
    cin >> N >> M >> x >> y >> K;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j ++) {
            cin >> map[i][j];
        }
    }
    for(int i = 0; i < K; i ++) {
        cin >> order[i];
    }
    for(int i = 0; i < K; i ++) {
        int dir = order[i];

        if(dir == 1) {
            if(y+1 == M) {
                continue;
            }
            y ++;
            right();
            cout << dice[2] << "\n";
            if(map[x][y] == 0) {
                map[x][y] = dice[0];
            } else {
                dice[0] = map[x][y];
                map[x][y] = 0;
            }
        }else if(dir == 2) {
            if(y-1 < 0) {
                continue;
            }
            y --;
            left();
            cout << dice[2] << "\n";
            if(map[x][y] == 0) {
                map[x][y] = dice[0];
            } else {
                dice[0] = map[x][y];
                map[x][y] = 0;
            }
        }else if(dir == 3) {
            if(x-1 < 0) {
                continue;
            }
            x --;
            up();

            cout << dice[2] << "\n";
            if(map[x][y] == 0) {
                map[x][y] = dice[0];
            } else {
                dice[0] = map[x][y];
                map[x][y] = 0;
            }
        } else {
            if(x+1 == N) {
                continue;
            }
            x ++;
            down();

            cout << dice[2] << "\n";

            if(map[x][y] == 0) {
                map[x][y] = dice[0];
            } else {
                dice[0] = map[x][y];
                map[x][y] = 0;
            }
        }

    }
    return 0;
}