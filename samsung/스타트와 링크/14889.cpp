#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int N;
int s[21][21];
vector<int> a;
vector<int> b;
int ans = 123456789;

int dfs(int idx) {
    if(idx >= N) {
        if(a.size() == b.size()) {
            int aSum = 0;
            int bSum = 0;

            for(int i = 0; i < a.size(); i ++) {
                for(int j = i + 1; j < a.size(); j ++) {
                    aSum += s[a[i]][a[j]] + s[a[j]][a[i]];
                }
            }
            for(int i = 0; i < b.size(); i ++) {
                for(int j = i + 1; j < b.size(); j ++) {

                    bSum += s[b[i]][b[j]] + s[b[j]][b[i]];
                }
            }

            ans = min(ans, abs(aSum-bSum));
        }
        return 0;
    }

    a.push_back(idx);
    dfs(idx + 1);
    a.pop_back();

    b.push_back(idx);
    dfs(idx + 1);
    b.pop_back();
    return 0;
}

int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            cin >> s[i][j];
        }
    }
    dfs(0);
    cout << ans;
    return 0;
}
