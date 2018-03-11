#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N;
int ans = 987654321;
int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};
vector<vector<int>> map;
vector<vector<int>> visited;
queue<pair<int, int>> q;


int copy() {
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            map[i][j] = visited[i][j];
        }
    }

    return 0;
}

int queueClear() {
    while(!q.empty()) {
        q.pop();
    }
    return 0;
};

int main() {

    cin >> N;

    map.assign(100, vector<int>(100, 0));
    visited.assign(100, vector<int>(100, 0));

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            cin >> map[i][j];
        }
    }

    // 구역 나누기
    int cnt = 1;
    for(int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j++) {
            if(map[i][j] == 1 && !visited[i][j]) {
                q.push(make_pair(i, j));
                visited[i][j] = cnt;
                while(!q.empty()) {
                    int r = q.front().first;
                    int c = q.front().second;
                    q.pop();

//                    visited[nextR][nextC] = cnt;
//                    cout << q.size() << '\n';

                    for(int i = 0; i < 4; i ++){
                        int nextR = r + dr[i];
                        int nextC = c + dc[i];

                        if(nextC >= 0 && nextR >= 0 && nextC < N && nextR < N) {
                            if(map[nextR][nextC] && !visited[nextR][nextC]) {
                                visited[nextR][nextC] = cnt;
                                q.push(make_pair(nextR, nextC));
                            }
                        }
                    }
                }
                cnt ++;
            }
        }
    }

    cnt --;
    int check = 1;
    int finish;
    while(cnt --) {
        copy();
        queueClear();

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                if (map[i][j] == check) {
                    q.push(make_pair(i, j));
                }
            }
        }

        int temp_ans = 0;
        finish = 0;
        while(!q.empty()) {
            if(finish) {
                break;
            }

            long long loop = q.size();
            temp_ans ++;
            while(loop --){
                if(finish) {
                    break;
                }

                int r = q.front().first;
                int c = q.front().second;
                q.pop();

                for(int i = 0; i < 4; i ++){
                    int nextR = r + dr[i];
                    int nextC = c + dc[i];

                    if(nextC >= 0 && nextR >= 0 && nextC < N && nextR < N) {
                        if(!map[nextR][nextC]) {
                            map[nextR][nextC] = check;
                            q.push(make_pair(nextR, nextC));
                        } else if(map[nextR][nextC] != check) {
                            ans = (ans > temp_ans)? temp_ans : ans;
                            finish = 1;
                            break;
                        }
                    }
                }
            }
        }
        check ++;
    }

    cout << ans - 1;
    return 0;
}
