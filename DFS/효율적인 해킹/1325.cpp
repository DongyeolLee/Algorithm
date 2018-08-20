#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, cnt;
int ans[10001];
int hacked[10001];
vector<vector<int>> rel(10001);

void dfs(int com) {
    if(hacked[com])
        return;

    hacked[com] = 1;
    cnt ++;

    for(int i = 0; i < rel[com].size(); i ++) {
        dfs(rel[com][i]);
    }
}

int main() {
    // 컴퓨터, 연관 관계
    cin >> N >> M;
    for(int i = 0; i < M; i ++) {
        int from, to;
        cin >> from >> to;
        // 해킹되면 피해 받는 컴퓨터 배열
        rel[to].push_back(from);
    }

    // i번째 해킹
    for(int i = 1; i <= N; i ++) {
        cnt = 0;
        memset(hacked, 0, sizeof(hacked));
        dfs(i);
        ans[i] = cnt;
    }

    int max = -1;
    for(int i = 1; i <= N; i ++) {
        if(ans[i] > max) {
            max = ans[i];
        }
    }

    for(int i = 1; i <= N; i ++) {
        if(max == ans[i]) {
            cout << i << " ";
        }
    }

    return 0;
}
