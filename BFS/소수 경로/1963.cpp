#include <iostream>
#include <cstring>
#include <string>
#include <queue>

using namespace std;

int T, st, fin;

int primeNum[10001];
int v[10001];
int chk[10001];
int num[4];

queue<pair<int, int>> q;

int prime() {
    for(int i=2; i<=10000; i++){
        if(primeNum[i] == false){
            if(i > 1000)
                v[i] = 1;
            for(int j=i+i; j<=10000; j+=i){
                primeNum[j]=true;
            }
        }
    }
    return 0;
}

int main() {

    cin >> T;

    memset(v, 0, sizeof(v));
    memset(primeNum, 0, sizeof(primeNum));
    prime();

    while(T--) {
        memset(chk, 0, sizeof(chk));
        bool flag = false;

        while(!q.empty()) {
            q.pop();
        }

        cin >> st >> fin;
        chk[st] = 1;
        q.push({st, 0});

        while(!q.empty()) {
            int n = q.front().first;
            int time = q.front().second;
            q.pop();

            if (n == fin) {
                flag = true;
                cout << time << endl;
                break;
            }

            num[0] = n / 1000;
            n %= 1000;
            num[1] = n / 100;
            n %= 100;
            num[2] = n / 10;
            n %= 10;
            num[3] = n;

            for(int x = 0; x < 4; x++) {
                int temp = num[x];

                for (int i = 0; i < 10; i++) {
                    num[x] = i;
                    string s = "";
                    s = (num[0] + '0');
                    s += (num[1] + '0');
                    s += (num[2] + '0');
                    s += (num[3] + '0');
                    int p = stoi(s);
                    if (p >= 1000 && p <= 10000 && v[p] && !chk[p]) {
                        chk[p] = 1;
                        q.push({p, time + 1});
                    }
                }

                num[x] = temp;
            }
        }

        if(!flag) {
            cout << "Impossible" << endl;
        }

    }
    return 0;
}
