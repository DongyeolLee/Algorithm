#include <iostream>
#include <queue>
#include <cstring>
#include <utility>

using namespace std;

int N, K;
int dp[100001];

queue<pair<int, int>> q;
bool visited[100001];

int main() {

    cin >> N >> K;

    memset(dp, 0, sizeof(dp));
    memset(visited, 0, sizeof(visited));

    q.push(make_pair(N, 0));

    while (!q.empty()) {
        int cur = q.front().first;
        int cnt = q.front().second;
        q.pop();

        if (cur < 0 || cur > 100000) continue;
        if (visited[cur]) continue;

        visited[cur] = true;

        if (cur == K){
            cout << cnt;
            return 0;
        }

        q.push({ cur * 2, cnt + 1 });
        q.push({ cur + 1, cnt + 1 });
        q.push({ cur - 1, cnt + 1 });
    }

    return 0;
}