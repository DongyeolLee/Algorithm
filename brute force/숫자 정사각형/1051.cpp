#include <iostream>
#include <algorithm>

using namespace std;

int N, M, ans = 0;
char map[51][51];

int main() {
    cin >> N >> M;
    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {
            scanf(" %c", &map[r][c]);
        }
    }

    int num = min(N, M);

    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {

            for(int len = 0; len < num; len ++) {
                if(r + len < N && c + len < M) {
                    char s1 = map[r][c];
                    char s2 = map[r + len][c];
                    char s3 = map[r][c + len];
                    char s4 = map[r + len][c + len];

                    if((s1 == s2) && (s3 == s4) && (s1 == s3) && (s1 == s4) && (s2 == s3) && (s2 == s4) && (s3 == s4)) {
                        ans = max(ans, (len + 1) * (len + 1));
                    }
                }
            }
        }
    }

    cout << ans;
    return 0;
}