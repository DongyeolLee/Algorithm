#include <iostream>

using namespace std;

int N, M;
int dp[2001][2001];
int arr[2001];

int main() {
    cin >> N;

    for(int i = 1; i <= N; i ++)
        scanf("%d", &arr[i]);

    for(int i = 1; i <= N; i ++)
        dp[i][i] = 1;

    for(int i = 1; i <= N-1; i ++) {
        if(arr[i] == arr[i+1])
            dp[i][i+1] = 1;
    }

    // 길이가 3이상
    for(int k = 3; k <= N; k ++) {
        for(int i = 1; i <= N-k+1; i ++) {
            int j = i+k-1;
            if(arr[i] == arr[j] && dp[i+1][j-1] == 1)
                dp[i][j] = 1;
        }
    }

    cin >> M;
    for(int i = 0; i < M; i ++) {
        int from, to;
        scanf("%d %d", &from, &to);
        printf("%d\n", dp[from][to] );
    }
    return 0;
}