#include <iostream>
#include <vector>

using namespace std;

int N, S, ans = 0;
vector<int> arr;

int dfs(int cnt, int sum, int length) {
    if(cnt == N) {
        if(sum == S && length != 0) {
            ans ++;
        }
        return 0;
    }

    dfs(cnt + 1, sum + arr[cnt], length + 1);
    dfs(cnt + 1, sum, length);
    return 0;
}

int main() {

    cin >> N >> S;

    for(int i = 0; i < N; i ++) {
        int temp;
        cin >> temp;
        arr.push_back(temp);
    }

    dfs(0, 0, 0);

    cout << ans;
    return 0;
}