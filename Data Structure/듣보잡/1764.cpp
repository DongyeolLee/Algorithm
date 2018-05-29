#include <iostream>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

int n, m;
set<string> hear;
vector<string> ans;

int main() {
    cin >> n >> m;

    for(int i = 0; i < n; i ++) {
        string h;
        cin >> h;
        hear.insert(h);
    }

    for(int i = 0; i < m; i ++) {
        string s;
        cin >> s;
        auto it = hear.find(s);
        if(it != hear.end()) {
            ans.push_back(*it);
        }
    }

    cout << ans.size() << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < ans.size(); i ++) {
        cout << ans[i] << "\n";
    }
    return 0;
}
