#include <iostream>

using namespace std;

int N;
int box[2001][2001];
int dp[2001][2001];
int sum = 0;

int dfs(int leftCard, int rightCard, int num) {
    if (leftCard >= N + 1 || rightCard >= N + 1) {
        return num;
    }

    if (dp[leftCard][rightCard] != -1)
        return dp[leftCard][rightCard] + num;

    int ret;
    if (rightCard < N + 1 && leftCard < N + 1) {
        ret = dfs(leftCard + 1, rightCard, num);
        ret = max(ret, dfs(leftCard + 1, rightCard + 1, num));
    }

    if (box[0][leftCard] > box[1][rightCard] && rightCard < N + 1 && leftCard < N + 1) {
        ret = max(ret, dfs(leftCard, rightCard + 1, num + box[1][rightCard]));
    }

    dp[leftCard][rightCard] = ret - num;
    return ret;

}

int main () {

    cin >> N;

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < N; j++) {

            cin >> box[i][j];
        }
    }
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            dp[i][j] = -1;
        }
    }
    cout << dfs(0, 0, 0);

    return 0;
}

