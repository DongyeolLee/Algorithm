#include <iostream>
#include <algorithm>

using namespace std;

int N, M;
int map[1000][1000];
int dp[1000][1000];

int main() {

    cin >> N >> M;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j ++) {
            cin >> map[i][j];
        }
    }

    dp[0][0] = map[0][0];
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < M; j ++) {
            if(i == 0 && j - 1 >= 0) {
                dp[i][j] = map[i][j] + dp[i][j-1];
            }
            if(j == 0 && i - 1 >= 0) {
                dp[i][j] = map[i][j] + dp[i-1][j];
            }
            if(i != 0 && j != 0) {
                dp[i][j] = map[i][j] + max(dp[i-1][j], max(dp[i][j-1], dp[i-1][j-1]));
            }
        }
    }

    cout << dp[N-1][M-1];
    return 0;
}