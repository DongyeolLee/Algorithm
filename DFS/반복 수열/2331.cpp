#include <iostream>
#include <cmath>
#include <cstring>
#include <vector>

using namespace std;

string A;
int P, E;
vector<int> visited;
int D[600000];


int dfs(string num) {

    int temp = 0;
    for(int i = 0; i < num.length(); i ++) {
        temp += pow(num[i] - '0', P);
    }

    int cnt = 0;
    if(D[temp]) {
        E = temp;
        for(int i = 0; i < 600000; i ++) {
            if(D[i]) {
                cnt ++;
            }
        }
        return cnt;
    } else {
        D[temp] = 1;
        visited.push_back(temp);
        return dfs(to_string(temp));
    }
};

int main() {

    cin >> A >> P;

    memset(D, 0, sizeof(D));

    int index = stoi(A);
    D[index] = 1;
    visited.push_back(index);
    dfs(A);

    int cnt = 0;
    for(int i = 0; i < visited.size(); i ++) {
        if(visited[i] == E){
            cout << cnt;
        } else {
            cnt ++;
        }
    }

    return 0;
}
