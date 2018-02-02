#include <iostream>
#include <utility>
#include <cstring>
#include <algorithm>
#include <vector>

using namespace std;

int N, M;
int student[100001];
int stdArr[100001];
vector<int> card;
pair<int, int> arr[1000001];

int check() {

    for(int i = 1; i <= M; i ++) {
        int x = arr[i].first;
        int y = arr[i].second;

        if(student[x] < student[y]) {
            return -1;
        }
    }

    return 1;
}

int main() {

    cin >> N >> M;

    memset(stdArr, 0, sizeof(stdArr));

    for(int i = 1; i <= N; i ++) {
        card.push_back(i);
    }

    for(int i = 1; i <= M; i ++) {
        int a, b;

        cin >> a >> b;

        // 여기가 좀 핵심!
        stdArr[a]++;
        // 추후 테스트를 위해 저장
        arr[i].first = a;
        arr[i].second = b;
    }

    if(N == 1) {
        cout << 1;
        return 0;
    }

    for(int i = 1; i <= N; i ++) {
        int cardT = stdArr[i];

        student[i] = card[cardT];
        card.erase(card.begin() + cardT);
    }

    int chk = check();

    if(chk == 1) {
        for(int i = 1; i <= N; i ++) {
            cout << student[i] << " ";
        }
    } else {
        cout << -1 << endl;
    }

    return 0;
}
