#include <iostream>

#define mod 1000000000

using namespace std;

int N;
long long dp[101][10];

int main() {

    cin >> N;

    dp[1][0] = 0;
    for(int i = 1; i <= 9; i ++) {
        dp[1][i] = 1;
    }

    for(int i = 2; i <= N; i ++) {
        for(int j = 0; j <= 9; j ++) {
            dp[i][j] = 0;

            if(j == 0) {
                dp[i][j] = dp[i - 1][1];
            } else if(j == 9) {
                dp[i][j] = dp[i - 1][8];
            } else {
                dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j + 1];
            }

            // 숫자가 너무 커서 오버플로우, 미리 나눈값 저장.
            dp[i][j] %= mod;
        }
    }

    long long ans = 0;
    for(int i = 0; i <= 9; i ++) ans += dp[N][i];

    cout << ans % mod << endl;
    return 0;
}
