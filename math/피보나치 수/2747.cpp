#include <iostream>

using namespace std;

int N;
int dp[46];
int main() {
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    if(N <= 2) {
        cout << dp[N];
        return 0;
    }
    for(int i = 3; i <= N; i ++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    cout << dp[N];
    return 0;
}