#include <iostream>
#include <cstring>
#include <vector>

#define RED 1
#define BLUE 2

using namespace std;

int testCase, node, edge;
vector<int> map[20001];
int visited[20001];

int dfs(int Enode, int color) {

    visited[Enode] = color;
    for(int i = 0; i < map[Enode].size(); i ++) {
        int next = map[Enode][i];
        if(!visited[next]) {
            dfs(next, 3 - color);
        }
    }

    return 0;
}

int main() {

    cin >> testCase;

//    cout << sizeof(map) << endl;
    while(testCase --) {
        memset(map, 0, sizeof(map));
        memset(visited, 0, sizeof(visited));
        cin >> node >> edge;

        for(int i = 0; i < edge; i ++) {
            int x, y;
            cin >> x >> y;

//            map[x][y] = map[y][x] = 1;
            map[x].push_back(y);
            map[y].push_back(x);
        }

        for(int i = 1; i <= node; i ++) {
            if(!visited[i])
                dfs(i, RED);
        }

        bool ok = true;
        for (int i = 1; i <= node; i++) {
            for (int k = 0; k < map[i].size(); k++) {
                int j = map[i][k];
                if (visited[i] == visited[j]) {
                    ok = false;
                }
            }
        }

        printf("%s\n", ok ? "YES" : "NO");
    }

    return 0;
}
