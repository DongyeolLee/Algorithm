#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

int N, M, person = 101, ans = 987654321;
int cnt[101];
vector<vector<int>> relation(101);

void dfs(int diff, int num) {
    if(cnt[num] != 0) {
        cnt[num] = min(diff, cnt[num]);
    } else {
        cnt[num] = diff;
    }

    for(int j = 0; j < relation[num].size(); j ++) {
        int next = relation[num][j];
        if(cnt[next] == 0 || cnt[next] > diff + 1 ) {
            dfs(diff + 1, next);
        }
    }
}

int main() {
    cin >> N >> M;
    for(int i = 0; i < M; i ++) {
        int from, to;
        cin >> from >> to;
        relation[from].push_back(to);
        relation[to].push_back(from);
    }

    for(int i = 1; i <= N; i ++) {
        memset(cnt, 0, sizeof(cnt));
        for(int j = 0; j < relation[i].size(); j ++) {
            dfs(1, relation[i][j]);
        }

        int temp = 0;
        for(int j = 1; j <= N; j ++) {
            if(j == i) {
                continue;
            }
            temp += cnt[j];
        }

        if(ans > temp) {
            ans = temp;
            person = i;
        }
        else if(ans == temp) {
            person = min(person, i);
        }
    }

    cout << person;
    return 0;
}