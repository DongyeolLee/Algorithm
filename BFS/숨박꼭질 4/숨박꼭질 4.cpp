#include <iostream>
#include <queue>

using namespace std;

int N, M;
queue<int> q;
int visited[400001];
int arr[400001];
int temp[100000];

int main() {

    cin >> N >> M;

    for(int i = 0; i < 200001; i++) {
        visited[i] = -1;
    }

    q.push (N);
    visited[N] = 0;

    while(!q.empty()) {
        int location;
        location = q.front();


        if(location == M) {
            cout << visited[location] << endl;

            if ( N == M) {
                cout << N;
                break;
            }

            int j = 0;

            for(int i = arr[location]; i != N; i = arr[i]) {
                temp[j] = i;
                j++;
            }

            cout << N << " ";
            for(int i = j-1; i > -1; i--) {
                cout << temp[i] << " ";
            }
            cout << M;

            break;
        }

        q.pop();

        int next;
        next = location - 1;
        if(visited[next] == -1 && next <= 400001 && next >= 0) {

            arr[next] = location;
            visited[next] = visited[location] + 1;
            q.push(next);

        }

        next = location + 1;
        if(visited[next] == -1 && next <= 400001 && next >= 0) {

            arr[next] = location;
            visited[next] = visited[location] + 1;
            q.push(next);
        }

        next = (location*2);
        if(visited[next] == -1 && next <= 400001 && next >= 0) {

            arr[next] = location;
            visited[next] = visited[location] + 1;
            q.push(next);

        }

    }

    return 0;
}