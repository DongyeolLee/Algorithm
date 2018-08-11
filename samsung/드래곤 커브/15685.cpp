#include <iostream>
#include <vector>

using namespace std;

int map[101][101];
int N, x, y, d, g;
vector<int> directions;

int getDir(int dir) {
    if(dir == 0) {
        return 1;
    }
    else if(dir == 1) {
        return 2;
    }
    else if(dir == 2) {
        return 3;
    }
    else {
        return 0;
    }
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        cin >> x >> y >> d >> g;
        directions.clear();
        directions.push_back(d);
        while(g--) {
            for(int a = directions.size() - 1; a >= 0; a --) {
                int dir = directions[a];
                directions.push_back(getDir(dir));
            }
        }
        map[x][y] = 1;
        for(int j = 0; j < directions.size(); j ++) {
            int dir = directions[j];
            if(dir == 0) {
                x++;
            }
            else if(dir == 1) {
                y--;
            }
            else if(dir == 2) {
                x--;
            }
            else {
                y++;
            }
            map[x][y] = 1;
        }
    }

    int result = 0;
    for (int i = 0; i < 100; i++) {
        for (int j = 0; j < 100; j++) {
            if (map[i][j] && map[i][j + 1] && map[i + 1][j] && map[i + 1][j + 1]) {
                result++;
            }
        }
    }

    cout << result;
    return 0;
}