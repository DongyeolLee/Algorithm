#include <iostream>
#include <algorithm>

using namespace std;

int N;
int num[13];
// + - * /
int op[4];
int maxN = -1000000005;
int minN = 1000000005;

int dfs(int idx, int amount) {
    if(idx == N) {
        maxN = max(maxN, amount);
        minN = min(minN, amount);
        return 0;
    }

    if(op[0] > 0) {
        op[0] --;
        dfs(idx + 1, amount + num[idx]);
        op[0] ++;
    }
    if(op[1] > 0) {
        op[1] --;
        dfs(idx + 1, amount - num[idx]);
        op[1] ++;
    }
    if(op[2] > 0) {
        op[2] --;
        dfs(idx + 1, amount * num[idx]);
        op[2] ++;
    }
    if(op[3] > 0) {
        op[3] --;
        dfs(idx + 1, amount / num[idx]);
        op[3] ++;
    }
    return 0;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        cin >> num[i];
    }
    for(int i = 0; i < 4; i ++) {
        cin >> op[i];
    }

    dfs(1, num[0]);
    cout << maxN << "\n";
    cout << minN << "\n";
    return 0;
}