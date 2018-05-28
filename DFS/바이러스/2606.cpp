#include <iostream>
#include <vector>

using namespace std;

int computer, con;
vector<vector<int>> v(101);
int chk[101];

int dfs(int idx) {
    chk[idx] = 1;
    for(int i = 0; i < v[idx].size(); i ++) {
        if(chk[v[idx][i]] != 1) {
            dfs(v[idx][i]);
        }
    }
    return 0;
}

int main() {

    cin >> computer >> con;
    for(int i = 0; i < con; i ++) {
        int num, num2;
        cin >> num >> num2;
        v[num].push_back(num2);
        v[num2].push_back(num);
    }

    chk[1] = 1;
    for(int i = 0; i < v[1].size(); i ++) {
        if(chk[v[1][i]] != 1) {
            dfs(v[1][i]);
        }
    }
    int ans = 0;
    for(int i = 0; i < 101; i ++) {
        if(chk[i] == 1)
            ans ++;
    }
    cout << ans - 1;
    return 0;
}
