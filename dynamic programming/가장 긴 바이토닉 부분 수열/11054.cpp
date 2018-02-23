#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[1001];
int dp[1001];
int dp2[1001];

int main() {

    cin >> N;

    memset(arr, 0, sizeof(arr));
    memset(dp, 0, sizeof(dp));
    memset(dp2, 0, sizeof(dp2));

    for(int i = 1; i <= N; i++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i ++) {
        dp[i] = 1;
        for(int j = 1; j < i; j ++) {
            if(arr[j] < arr[i] && dp[i] < dp[j] + 1) {
                dp[i] = dp[j] + 1;
            }
        }
    }

    for(int i = N; i >= 1; i--) {
        dp2[i] = 1;
        for(int j = i+1; j <= N; j++) {
            if(arr[i] > arr[j] && dp2[j]+1 > dp2[i]) {
                dp2[i] = dp2[j]+1;
            }
        }
    }

    int ans = 0;
    for(int i = 0; i <= N; i++) {
        if(ans < dp[i] + dp2[i]-1) {
            ans = dp[i] + dp2[i]-1;
        }
    }

    cout << ans;
    return 0;
}
