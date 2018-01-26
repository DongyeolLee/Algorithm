#include <iostream>
#include <cstring>


using namespace std;

#define IMPOSSIBLE (-987654321)

int N, K;
int arr[101][5];
int memo[101][100001];

int dfs(int cnt, int money ,int time) {
    if(time > K) {
        return IMPOSSIBLE;
    }

    if(memo[cnt][time] == IMPOSSIBLE) {
        return IMPOSSIBLE;
    }

    if(cnt == N && time <= K) {
        return money;
    }

    if(memo[cnt][time] != -1) {
        return memo[cnt][time] + money;
    }


    int val = IMPOSSIBLE;
    val = max(val, dfs(cnt + 1, money + arr[cnt + 1][2], time + arr[cnt + 1][1]));
    val = max(val, dfs(cnt + 1, money + arr[cnt + 1][4], time + arr[cnt + 1][3]));

    if(val == IMPOSSIBLE) {
        memo[cnt][time] = IMPOSSIBLE;
    } else {
        memo[cnt][time] = val - money;
    }

    return val;
}

int main() {

    cin >> N >> K;

    memset(memo, -1, sizeof(memo));

    // 시간, 모금액, 자전거 시간, 자전거 모금액
    for(int i = 1; i <= N; i ++) {
        cin >> arr[i][1] >> arr[i][2] >> arr[i][3] >> arr[i][4];
    }

    int ans = dfs(1, arr[1][2], arr[1][1]);
    ans = max(ans, dfs(1, arr[1][4], arr[1][3]));

    cout << ans << endl;
    return 0;
}
