#include <iostream>
#include <vector>
#include <set>
#include <cmath>
#include <algorithm>

using namespace std;

int N, ans = 0;
vector<int> v;
vector<char> t;
vector<string> st;
set<char> s;
int arr[150];

// A == 65
int main() {
    cin >> N;
    for(int i = 0; i < N; i ++) {
        string temp;
        cin >> temp;
        st.push_back(temp);
        for(int j = 0; j < temp.size(); j ++) {
            s.insert(temp[j]);
        }
    }

    for(auto i = s.begin(); i != s.end(); i ++) {
        char c = *i;
        t.push_back(c);
    }

    sort(t.begin(), t.end());

    do {
        // 앞에서부터 하나씩 선택
        for(int i = 0, j = 9; i < t.size(); i ++, j --) {
            arr[t[i] - '0'] = j;
        }

        int sum = 0, tmp = 0;
        for(int i = 0; i < N; i ++, tmp = 0) {
            for(int j = 0; j < st[i].size(); j ++, tmp *= 10) {
                tmp += arr[st[i][j] - '0'];
            }
            sum += (tmp/10);
        }
        ans = max(ans, sum);
    } while(next_permutation(t.begin(), t.end()));

    cout << ans;
    return 0;
}
