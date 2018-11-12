#include <iostream>
#include <vector>
#include <utility>
#include <queue>
#include <cstring>
using namespace std;

int N, M, source, destination, dis[1001];
vector<vector<pair<int, int>>> graph;
priority_queue<pair<int, int>> pq;

int main() {
    cin >> N;
    cin >> M;
    graph.resize(N+1);
    for(int i = 0; i < M; i ++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        graph[from].push_back(make_pair(to, cost));
    }
    cin >> source >> destination;
    pq.push({0, source});
    memset(dis, -1, sizeof(dis));
    while(!pq.empty()) {
        int cost = -pq.top().first;
        int location = pq.top().second;
        pq.pop();

        if(dis[location] != -1) {
            continue;
        }

        dis[location] = cost;

        for(int i = 0; i < graph[location].size(); i ++) {
            int n_location = graph[location][i].first;
            int n_cost = -graph[location][i].second - cost;

            if(dis[n_location] != -1) {
                continue;
            }

            pq.push({n_cost, n_location});
        }

    }
    cout << dis[destination];
    return 0;
}