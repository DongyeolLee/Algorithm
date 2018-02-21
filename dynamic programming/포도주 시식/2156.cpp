#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int n;
int a[10001];
int dp[10001][3];

int main() {

    cin >> n;

    memset(dp, 0, sizeof(dp));
    memset(a, 0, sizeof(a));

    for(int i = 1; i <= n; i ++) {
        cin >> a[i];
    }

    dp[1][1] = a[1];

    for(int i = 2; i <= n; i ++) {

        int temp = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][0] = max(temp, dp[i - 1][2]);

        dp[i][1] = dp[i - 1][0] + a[i];

        dp[i][2] = dp[i - 1][1] + a[i];
    }

    int t = max(dp[n][0], dp[n][1]);
    int ans = max(t, dp[n][2]);

    cout << ans;
    return 0;
}
