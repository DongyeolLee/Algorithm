#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

int n;
vector<string> arr;
set<string> st;

int main() {
    cin >> n;

    for(int i = 0; i < n; i ++) {
        string s, v;
        cin >> s >> v;

        if(v == "enter") {
            st.insert(s);
        } else {
            st.erase(s);
        }
    }

    for (auto it = st.begin(); it != st.end(); ++it) {
        arr.push_back(*it);
    }

    reverse(arr.begin(), arr.end());

    for(int i = 0; i < arr.size(); i ++) {
        cout << arr[i] << "\n";
    }

    return 0;
}
