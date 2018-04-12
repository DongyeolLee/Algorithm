#include <iostream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>

using namespace std;

queue<pair<int, int>> q;
vector<string> wheels;
int chk[4];
int rotation[4];
int K;

void rotateWheel() {
    for(int i = 0; i < 4; i ++) {
        if(rotation[i] == 1) {
            char temp = wheels[i][7];
            wheels[i].pop_back();
            wheels[i].insert(wheels[i].begin(), temp);
        } else if(rotation[i] == -1) {
            char temp = wheels[i][0];
            wheels[i].erase(wheels[i].begin());
            wheels[i].insert(wheels[i].end(), temp);
        }
    }
}

int main() {
    for(int i = 0; i < 4; i ++) {
        string a;
        cin >> a;
        wheels.push_back(a);
    }

    cin >> K;
    int w, dir;
    while(K --) {
        memset(chk, 0, sizeof(chk));
        memset(rotation, 0, sizeof(rotation));
        cin >> w >> dir;
        w --;
        chk[w] = 1;
        rotation[w] = dir;
        q.push(make_pair(w, dir));
        while(!q.empty()) {
            int wh = q.front().first;
            int whDir = q.front().second;
            q.pop();

            if(wh >= 0 && wh < 4) {
                if(wh != 0 && chk[wh-1] == 0 && wheels[wh-1][2] - '0'!= wheels[wh][6] - '0') {
                    chk[wh-1] = 1;
                    rotation[wh-1] = -whDir;
                    q.push(make_pair(wh-1, -whDir));
                }
                if(wh != 3 && chk[wh+1] == 0 && wheels[wh][2] - '0' != wheels[wh+1][6] - '0') {
                    chk[wh+1] = 1;
                    rotation[wh+1] = -whDir;
                    q.push(make_pair(wh+1, -whDir));
                }
            }

        }

        rotateWheel();
    }

    int ans = 0;
    for(int i = 0; i < 4; i ++) {
        int cnt = wheels[i][0] - '0';
        if(cnt == 1) {
            if(i == 0) {
                ans += 1;
            } else if(i == 1) {
                ans += 2;
            } else if(i == 2) {
                ans += 4;
            } else {
                ans += 8;
            }
        }
    }
    cout << ans;
    return 0;
}
