#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <utility>
#include <cstring>
using namespace std;

int N, M, X, ans = -1, dis_go[1001], dis_come[1001];
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;

int main() {
    // 학생, 도로 숫자, 도착 마을
    cin >> N >> M >> X;

    graph.resize(M+1);

    for(int i = 0; i < M; i ++) {
        int from, to, time;
        cin >> from >> to >> time;
        graph[from].push_back({to, time});
    }

    for(int i = 1; i <= N; i ++) {
        int source = i;
        pq.push({0, source});
        memset(dis_go, -1, sizeof(dis_go));

        while(!pq.empty()) {
            int here = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if(dis_go[here] != -1) {
                continue;
            }

            dis_go[here] = cost;
            for(int n = 0; n < graph[here].size(); n ++) {
                int next = graph[here][n].first;
                int n_cost = -graph[here][n].second - cost;
                if(dis_go[next] != -1) {
                    continue;
                }
                pq.push({n_cost, next});
            }
        }

        pq.push({0, X});
        memset(dis_come, -1, sizeof(dis_come));
        while(!pq.empty()) {
            int here = pq.top().second;
            int cost = -pq.top().first;
            pq.pop();

            if(dis_come[here] != -1) {
                continue;
            }
            dis_come[here] = cost;
            for(int n = 0; n < graph[here].size(); n ++) {
                int next = graph[here][n].first;
                int n_cost = -graph[here][n].second - cost;
                if(dis_come[next] != -1) {
                    continue;
                }
                pq.push({n_cost, next});
            }
        }

        ans = max(ans, dis_go[X] + dis_come[source]);
    }

    cout << ans;
    return 0;
}