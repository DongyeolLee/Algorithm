#include <iostream>

using namespace std;

int T,n;
int cnt = 0;

int dfs(int sum) {

    if (sum == n) {
        cnt++;
    }

    if(sum < n) {
        for (int i = 1; i <= 3; i++) {
            dfs(sum+i);
        }
    }
}

int main() {

    cin >> T;
    for (int j = 0; j<T; j++) {
        cin >> n;

        for (int i = 1; i <= 3; i++) {
            dfs(i);
        }

        cout << cnt << endl;
        cnt =0;
    }
    return 0;
}
