#include <iostream>
#include <cstring>

using namespace std;

int N;
char map[100][100];
int visited[100][100];
int hor[4] = {1, -1, 0, 0};
int ver[4] = {0, 0, 1, -1};

int num = 1;
int num2 = 1;

int dfs(int a, int b) {

    for(int i = 0; i < 4; i ++) {
        if(!visited[a + ver[i]][b + hor[i]] && 0 <= a + ver[i] && a + ver[i] < N && 0 <= b + hor[i] && b + hor[i] < N) {
            if (map[a + ver[i]][b + hor[i]] == map[a][b]) {
                visited[a + ver[i]][b + hor[i]] = num;
                dfs(a + ver[i], b + hor[i]);
            }
        }
    }

    return 0;
}

int dfs1(int a, int b) {

    for(int i = 0; i < 4; i ++) {
        if(!visited[a + ver[i]][b + hor[i]] && 0 <= a + ver[i] && a + ver[i] < N && 0 <= b + hor[i] && b + hor[i] < N){
            if(map[a + ver[i]][b + hor[i]] == map[a][b]) {
                visited[a + ver[i]][b + hor[i]] = num;
                dfs1(a + ver[i], b + hor[i]);
            } else if((map[a][b] == 'R' || map[a][b] == 'G') && (map[a + ver[i]][b + hor[i]] == 'R' || map[a + ver[i]][b + hor[i]] == 'G')){
                visited[a + ver[i]][b + hor[i]] = num;
                dfs1(a + ver[i], b + hor[i]);
            }
        }
    }

    return 0;
}

int main() {

    cin >> N;

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j ++) {

            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j ++) {

            if(!visited[i][j]) {
                dfs(i, j);
                num ++;
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j ++) {

            if(!visited[i][j]) {
                dfs1(i, j);
                num2 ++;
            }
        }
    }

    cout << num-1 <<" "<< num2-1;
}