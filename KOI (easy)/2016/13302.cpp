#include <iostream>
#include <cstring>

#define MIN(a,b) ((a)<(b)? (a):(b))
#define IMPOSSIBLE  (100000000)

using namespace std;

int N, M;
int cant[101];
int memo[101][101];

int dfs(int day, int coupon, int price) {
    if(N < day) {
        return price;
    }

    if(memo[day][coupon]) {
        return memo[day][coupon] + price;
    }

    if(cant[day]) {
        return dfs(day + 1, coupon, price);
    }

    int ans = IMPOSSIBLE;

    ans = MIN(ans, dfs(day + 1, coupon, price + 10000));
    ans = MIN(ans, dfs(day + 3, coupon + 1, price + 25000));
    ans = MIN(ans, dfs(day + 5, coupon + 2, price + 37000));

    if(coupon >= 3) {
        ans = MIN(ans, dfs(day + 1, coupon - 3, price));
    }

    memo[day][coupon] = ans - price;

    return ans;
}

int main() {

    cin >> N >> M;

    memset(cant, 0, sizeof(cant));
    memset(memo, 0, sizeof(memo));

    int temp;

    if(M)
        for(int i = 1; i <= M; i ++) {
            cin >> temp;

            cant[temp] = 1;
        }

    cout << dfs(1, 0, 0) << endl;

    return 0;
}
