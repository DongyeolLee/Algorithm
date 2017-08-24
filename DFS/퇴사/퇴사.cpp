#include <iostream>

using namespace std;

int N;
int arr[20][2];

int dfs(int day, int money) {

    if (day - 1 == N) {
        return money;
    }

    if (day - 1 > N) {
        return 0;
    }

    int val = dfs(day + 1, money);
    val = max(dfs(day + arr[day][0], money + arr[day][1]), val);

    return val;
}

int main() {

    cin >> N;

    for(int i = 1; i <= N; i++) {
        for(int j = 0; j <= 1; j ++) {
            cin >> arr[i][j];
        }
    }


   cout <<  dfs(1, 0);

    return 0;
}

