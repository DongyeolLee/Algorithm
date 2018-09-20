#include <iostream>
#include <vector>

using namespace std;

int K;
int ans[6];
vector<int> v;

void dfs(int depth, int num) {
    if(depth == 6) {
        for(int i = 0; i < 6; i ++) {
            cout << ans[i] <<  " ";
        }
        cout << '\n';
        return;
    }

    for(int start = num; start < K; start ++) {
        ans[depth] = v[start];
        dfs(depth + 1, start + 1);
        ans[depth] = -1;
    }
}

int main() {

    while(1) {
        cin >> K;
        v.clear();

        if(K == 0)
            break;

        for(int i = 0; i < K ; i ++) {
            int num;
            cin >> num;
            v.push_back(num);
        }

        dfs(0, 0);
        cout << '\n';
    }
    return 0;
}
