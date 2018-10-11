#include <iostream>
#include <vector>
#include <utility>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;

int T, N;
string ans;
vector<pair<int, int>> dist;
int visited[105];

bool get_distance(int x1, int y1, int x2, int y2) {
    int diff = abs(x1 - x2) + abs(y1 - y2);
    return (diff <= 1000)? true : false;
}

void dfs(int idx) {
    if(idx == N + 1) {
        ans = "happy";
        return;
    }

    for(int i = 1; i < N + 2; i ++) {
        if(!visited[i]) {
            if(get_distance(dist[idx].first, dist[idx].second, dist[i].first, dist[i].second)) {
                visited[i] = 1;
                dfs(i);
            }
        }
    }
}

int main() {
    cin >> T;
    for(int t = 1; t <= T; t ++) {
        cin >> N;
        ans = "sad";
        dist.clear();
        memset(visited, 0, sizeof(visited));

        for(int i = 0; i < N + 2; i ++) {
            int num1, num2;
            cin >> num1 >> num2;
            dist.push_back({num1, num2});
        }
        dfs(0);
        cout << ans << endl;
    }
    return 0;
}
