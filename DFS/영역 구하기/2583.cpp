#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

struct Point {
    int x, y, x2, y2;
};

int M, N, K, t;
int map[101][101];
int rr[4] = {1, 0, -1, 0};
int cc[4] = {0, 1, 0, -1};
vector<Point> arr;
vector<int> ans;

int dfs(int r, int c) {
    for(int i = 0; i < 4; i ++) {
        int nextR = r + rr[i];
        int nextC = c + cc[i];
        if(map[nextR][nextC] == 0 && nextR < M && nextC < N && nextC >= 0 && nextR >= 0) {
            map[nextR][nextC] = 2;
            t ++;
            dfs(nextR, nextC);
        }
    }
    return 0;
}

int main() {
    cin >> M >> N >> K;

    for(int i = 0; i < K; i ++) {
        Point p;
        cin >> p.x >> p.y >> p.x2 >> p.y2;
        arr.push_back(p);
    }

    for(int cnt = 0; cnt < arr.size(); cnt ++) {
        for(int r = arr[cnt].y; r < arr[cnt].y2; r ++) {
            for(int c = arr[cnt].x; c < arr[cnt].x2; c ++) {
                map[r][c] = -1;
            }
        }
    }

    for(int r = 0; r < M; r ++) {
        for(int c = 0; c < N; c ++) {
            if(map[r][c] == 0) {
                t = 1;
                map[r][c] = 2;
                dfs(r, c);
                ans.push_back(t);
            }
        }
    }

    sort(ans.begin(), ans.end());

    cout << ans.size() << endl;
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << " ";
    }

    return 0;
}
