#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>

using namespace std;

int N, M, Z, size = 0;
int ans = 987654321;
int minN = 987654321;
int num[10];
vector<int> remote;

int dfs() {
    if(size - 1 > 0 && remote.size() == size - 1) {
        string n = "";
        for(int i = 0; i < remote.size(); i ++) {
            n += remote[i] + '0';
        }
        int nn = stoi(n);
        int tt = N - nn;
        tt = abs(tt);
        ans = min(ans, size - 1 + tt);
    }
    if(remote.size() == size) {
        string n = "";
        for(int i = 0; i < remote.size(); i ++) {
            n += remote[i] + '0';
        }
        int nn = stoi(n);
        int tt = N - nn;
        tt = abs(tt);
        ans = min(ans, size + tt);
    }

    if(remote.size() == size + 1) {
        string n = "";
        for(int i = 0; i < remote.size(); i ++) {
            n += remote[i] + '0';
        }
        int nn = stoi(n);
        int tt = N - nn;
        tt = abs(tt);
        ans = min(ans, size + 1 + tt);
        return 0;
    }

    for(int i = 0; i < 10; i ++) {
        if(num[i] != 1) {
            remote.push_back(i);
            dfs();
            remote.pop_back();
        }
    }

    return 0;
}

int main() {

    scanf("%d", &N);
    scanf("%d", &M);

    memset(num, 0, sizeof(num));

    int t = N;

    while(1) {
        t /= 10;
        size ++;
        if(t < 1) {
            break;
        }
    }

    for(int i = 0; i < M; i ++) {
        int temp;
        cin >> temp;
        num[temp] = 1;
    }

    if(N == 100) {
        cout << 0;
        return 0;
    }

    dfs();

    ans = min(ans, abs(N - 100));
    printf("%d", ans);
    
    return 0;
}
