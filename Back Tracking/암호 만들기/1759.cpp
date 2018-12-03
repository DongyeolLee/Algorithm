#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <set>
using namespace std;

int L, C;

vector<char> c_arr;
set<string> se;

void back_tracking(int idx, int cnt, string s) {
    if(cnt == L) {
        int chk1 = 0, chk2 = 0;
        int visited[27] = {0, };

        for(int i = 0; i < s.length(); i ++) {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
                chk1 ++;
            }

            else {
                if(!visited[s[i]-'0'-48])
                    chk2 ++;
            }
        }

        if(chk1 >= 1 && chk2 >= 2)
            se.insert(s);
        return;
    }

    for(int i = idx; i < C; i ++) {
        back_tracking(i + 1, cnt + 1, s + c_arr[i]);
        back_tracking(i + 1, cnt, s);
    }
}

int main() {
    cin >> L >> C;

    for(int i = 0; i < C; i ++) {
        char c;
        cin >> c;
        c_arr.push_back(c);
    }

    sort(c_arr.begin(), c_arr.end());

    back_tracking(0, 0, "");

    for(auto it = se.begin(); it != se.end(); it++) {
        cout<< *it << endl;
    }
    return 0;
}
