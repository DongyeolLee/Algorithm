#include <iostream>

using namespace std;

long long N;
long long dp[1500010];

int main() {
    cin >> N;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    if(N <= 2) {
        cout << dp[N];
        return 0;
    }
    for(int i = 3; i <= 1500000; i ++) {
        dp[i] = (dp[i - 1] + dp[i - 2]) % 1000000;
    }

    cout << dp[N % 1500000];
    return 0;
}