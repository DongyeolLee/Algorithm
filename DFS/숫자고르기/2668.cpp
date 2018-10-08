#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>
#include <set>

using namespace std;

int N;
int arr[101];
int visited[101];
vector<pair<int, int>> temp_arr;
set<int> s_idx;

void dfs(int idx) {
    int next = arr[idx];
    if(visited[next] == 1) {
        for(int i = next; visited[i] != -1; i = arr[i]) {
            temp_arr.push_back({idx, i});
            idx = i;
            visited[i] = -1;
        }
        return;
    }
    else if(visited[next] == -1 || visited[next] == 0) {
        visited[next] = 1;
        dfs(next);
        visited[next] = -1;
    }
}

int main() {
    cin >> N;
    for(int i = 1; i <= N; i ++) {
        cin >> arr[i];
    }

    for(int i = 1; i <= N; i ++) {
        temp_arr.clear();
        visited[i] = 1;

        dfs(i);

        visited[i] = -1;
        for(int t = 0; t < temp_arr.size(); t ++) {
            s_idx.insert(temp_arr[t].first);
        }
    }

    cout << s_idx.size() << endl;
    for (auto s1 = s_idx.begin(); s1 != s_idx.end(); s1++) {
        cout << *s1 << endl;
    }
    return 0;
}