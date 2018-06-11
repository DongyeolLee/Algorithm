#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n, k;
int dp[10001];
int money[101];

int dfs(int sum) {
    if(sum > k) {
        return 987654321;
    }
    if(dp[sum] != -1) {
        return dp[sum];
    }
    if(sum == k) {
        return 0;
    }

    int ans = 987654321;

    for(int i = 0; i < n; i ++) {
        ans = min(ans, dfs(sum+money[i])+1);
    }
    dp[sum] = ans;
    return dp[sum];
}

int main() {
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i ++) {
        scanf("%d", &money[i]);
    }
    memset(dp, -1, sizeof(dp));
    int ans = dfs(0, 0);
    printf("%d", ans == 987654321? -1 : ans);
    return 0;
}
