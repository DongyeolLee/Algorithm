#include <iostream>
#include <cstring>
using namespace std;

int N;
int arr[15][15];
int visited[15];
int minVal = 0;
int first;

int dfs(int node, int sum, int cnt) {

    if (!visited[node]) {
        visited[node] = 1;
        cnt++;
        for (int i = 0; i < N; i ++) {
            if (arr[node][i] != 0)
                dfs(i, sum+arr[node][i], cnt);
        }
        visited[node] = 0;
    }

    if (cnt == N && first == node) {
        minVal = (minVal == 0) ? sum : min(sum, minVal);
    }
}

int main() {

    cin >> N;
    memset(visited, 0, sizeof(visited));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        first = i;
        dfs(i, 0, 0);
        memset(visited, 0, sizeof(visited));
    }

    cout << minVal;
    return 0;
}