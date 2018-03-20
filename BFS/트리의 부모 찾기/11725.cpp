#include <iostream>
#include <queue>

using namespace std;

int N;
int parents[100001];
int visited[100001];

vector<vector<int>> tree(100001);
queue<int> q;

int main() {

    cin >> N;

    int i, j;

    // 양방향을 고려해 입력
    for(int x = 0; x < N-1; x ++) {
        cin >> i >> j;
        tree[i].push_back(j);
        tree[j].push_back(i);
    }

    // 루트 노드는 부모가 없으므로 처리하고 큐에 저장
    parents[1] = 0;
    q.push(1);
    visited[1] = 1;

    while(!q.empty()) {
        int a = q.front();
        q.pop();
        // 연결된 노드에 접근한 적이 없다면 접근하고 방문처리 및 부모 설정
        for(int b : tree[a]){
            if(!visited[b]) {
                visited[b] = 1;
                parents[b] = a;
                q.push(b);
            }
        }
    }

    // 출력
    for(int i = 2; i <= N; i++) {
        cout<< parents[i] << '\n';
    }

    return 0;
}
