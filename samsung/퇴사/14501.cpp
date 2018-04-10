#include <iostream>
#include <algorithm>

using namespace std;

int N, ans = 0;
int day[16];
int price[16];

void dfs(int date, int cost) {
    if(date > N) {
        return;
    }
    if(date == N) {
        ans = max(ans, cost);
        return;
    }
    dfs(date + 1, cost);
    dfs(date + day[date], cost+price[date]);
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        cin >> day[i];
        cin >> price[i];
    }

    dfs(1, 0);
    dfs(day[0], price[0]);

    cout << ans;
    return 0;
}
