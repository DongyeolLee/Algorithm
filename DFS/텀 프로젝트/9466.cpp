#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int T, n, cnt;
int students[100001];
int visited[100001];
int cycle[100001];

vector<int> v;

void dfs(int node) {

    int next = students[node];
    if(!visited[next]) {
        visited[next] = 1;
        cycle[next] = 1;
        dfs(next);
        cycle[next] = 0;
    } else if(cycle[next] == 1) {
        v.push_back(next);
        cycle[next] = 0;
    }
}

void dfs2(int node) {

    int next = students[node];
    students[node] = -1;
    if(students[next] != -1)
        dfs2(next);
}

int main() {

    cin >> T;

    while(T--) {
        cin >> n;

        cnt = 0;
        v.clear();
        memset(visited, 0, sizeof(visited));
        memset(students, 0, sizeof(students));

        for(int i = 1; i <= n; i ++) {
            cin >> students[i];
        }

        for(int i = 1; i <= n; i ++) {
            if(!visited[i]) {
                visited[i] = 1;
                cycle[i] = 1;
                dfs(i);
                cycle[i] = 0;
            }
        }

        auto size = static_cast<int>(v.size());

        for(int i = 0; i < size; i ++) {
            int node = v[i];

            dfs2(node);
        }

        for(int i = 1; i <= n; i ++) {
            if(students[i] != -1)
                cnt ++;
        }

        cout << cnt << '\n';
    }

    return 0;
}
