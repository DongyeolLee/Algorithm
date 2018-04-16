#include <iostream>
#include <vector>
#include <cmath>
#include <utility>
#include <cstring>

using namespace std;

int N, M, ans;
vector<pair<int, int>> applicant;
vector<pair<int, int>> place;
int chk[50];
int map[51][51];

int dfs(int idx, int cnt) {
    if(idx > place.size()) {
        return 0;
    }

    if(cnt == M) {
        int temp = 0;
        for(int i = 0; i < applicant.size(); i ++) {
            int dist = 987654321;
            for(int j = 0; -1 != chk[j]; j ++) {
                int appR = applicant[i].first;
                int appC = applicant[i].second;
                int plR = place[chk[j]].first;
                int plC = place[chk[j]].second;

                dist = min(dist, abs(appR - plR) + abs(appC - plC));
            }
            temp += dist;
        }
        ans = min(ans, temp);
        return 0;
    }

    chk[cnt] = idx;
    dfs(idx + 1, cnt + 1);
    chk[cnt] = -1;

    dfs(idx + 1, cnt);
    return 0;
}

int main() {

    cin >> N >> M;
    memset(chk, -1, sizeof(chk));
    for(int i = 0; i < N; i ++) {
        for(int j = 0; j < N; j ++) {
            cin >> map[i][j];

            if(map[i][j] == 1) {
                applicant.push_back(make_pair(i, j));
            } else if(map[i][j] == 2) {
                place.push_back(make_pair(i, j));
            }
        }
    }

    ans = 987654321;
    dfs(0 , 0);

    cout << ans;
    return 0;
}
