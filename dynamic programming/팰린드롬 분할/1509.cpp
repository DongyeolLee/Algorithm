#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
char s[2501];
int dp[2501];
int chk[2501][2501];

int main() {
    s[0] = 1;
    scanf("%s", &s[1]);
    n = strlen(s);

    for(int i = 1; i <= n; i ++) {
        chk[i][i] = 1;
    }

    for(int i = 1; i <= n-1; i ++) {
        if(s[i] == s[i+1]) {
            chk[i][i+1] = 1;
        }
    }

    for(int i = 3; i <= n; i ++) {
        for(int j = 0; j <= n-i+1; j++) {
            int x = i+j-1;
            if(s[j] == s[x] && chk[j+1][x-1] == 1)
                chk[j][x] = 1;
        }
    }

    n--;
    dp[0] = 0;
    for(int i = 1; i <= n; i ++) {
        dp[i] = -1;
        for(int j = 1; j <= i; j ++) {
            if(chk[j][i]) {
                if(dp[i] == -1 || dp[i] > dp[j-1] + 1) {
                    dp[i] = dp[j-1] + 1;
                }
            }
        }
    }

    cout << dp[n];
    return 0;
}
