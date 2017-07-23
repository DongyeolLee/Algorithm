#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int arr[150][150];
int visted[150][150];
const int dx[]={-1,1,0,0};
const int dy[]={0,0,1,-1};
pair<int, int> p1;
queue<pair <int, int>> q;


int main () {

    cin >> N >> M;

    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < M; j++) {
            scanf("%1d", &arr[i][j]);
        }
    }


    p1 = make_pair(0,0);
    q.push(p1);
    visted[0][0]=1;

    while (!q.empty()) {

        int x = q.front().first;
        int y = q.front().second;

        q.pop();

        for(int k = 0 ; k < 4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];

            if(nx < 0 || nx > N-1 || ny < 0 || ny > M-1) continue;

            if(arr[nx][ny] == 1 && !visted[nx][ny]){
                q.push(make_pair(nx,ny));

                visted[nx][ny] = visted[x][y]+1;
            }
        }
    }

    cout << visted[N-1][M-1];
    return 0;
}