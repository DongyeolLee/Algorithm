#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, cnt;
int apartments[26][26];
int visited[26][26];
int dr[4] = {-1, 0, 1, 0};
int dc[4] = {0, 1, 0, -1};
vector<int> arr;

int dfs(int r, int c) {
    for(int i = 0; i < 4; i ++) {
        int nextR = r + dr[i];
        int nextC = c + dc[i];
        if(nextR >= 0 && nextC >= 0 && nextC < N && nextR < N && !visited[nextR][nextC] && apartments[nextR][nextC] == 1) {
            visited[nextR][nextC] = 1;
            cnt ++;
            dfs(nextR, nextC);
        }
    }
    return 0;
}

int main() {
    cin >> N;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            scanf("%1d", &apartments[i][j]);

        }
    }
    int ans = 0;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            if(!visited[i][j] && apartments[i][j] == 1) {
                visited[i][j] = 1;
                ans ++;
                cnt ++;
                dfs(i, j);
                arr.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(arr.begin(), arr.end());
    cout << ans;
    for(int i = 0; i < arr.size(); i ++) {
        cout << arr[i] << endl;
    }
    return 0;
}