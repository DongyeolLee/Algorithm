#include <iostream>
#include <queue>
#include <vector>
using namespace std;

struct info {
    int rel_cnt;
    int my_num;
};

int n, r1, r2, cnt;
vector<vector<int>> rel(101);
int visited[101];

queue<info> q;

int main() {
    cin >> n;
    cin >> r1 >> r2;
    cin >> cnt;

    for(int i = 0; i < cnt; i ++) {
        int x, y;
        cin >> x >> y;

        rel[x].push_back(y);
        rel[y].push_back(x);
    }

    q.push({0, r1});
    visited[r1] = 1;

    while(!q.empty()) {
        int rel_cnt = q.front().rel_cnt;
        int my_num = q.front().my_num;
        q.pop();

        if(my_num == r2) {
            cout << rel_cnt;
            return 0;
        }

        for(int i = 0; i < rel[my_num].size(); i ++) {
            int next_rel = rel[my_num][i];

            if(visited[next_rel] != 1) {
                visited[next_rel] = 1;
                q.push({rel_cnt + 1, next_rel});
            }
        }
    }

    cout << -1;
    return 0;
}