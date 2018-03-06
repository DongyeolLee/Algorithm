#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int map[1001][1001];
int visited[1001];
int cnt;

int dfs(int node) {

    visited[node] = 1;

    for(int i = 1; i <= N; i++) {
        if(map[node][i] && !visited[i]) {
            dfs(i);
        }
    }

    return 0;
}

int main() {

    cin >> N >> M;

    memset(map, 0, sizeof(map));
    memset(visited, 0, sizeof(visited));

    int r, c;
    for(int i = 0; i < M; i ++) {

        cin >> r >> c;

        map[r][c] = map[c][r] = 1;
    }

    for(int i = 1; i <= N; i ++) {
        if(!visited[i]){
            dfs(i);
            cnt++;
        }

    }

    cout << cnt;
    return 0;
}
