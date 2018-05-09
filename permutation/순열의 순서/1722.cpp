#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>

using namespace std;

int N, in;
long long cnt;
long long ans = 0;
long long factorial[21];
int use[21];
vector<int> v(N);

int main() {
    cin >> N;
    cin >> in;

    memset(use, 0 , sizeof(use));

    factorial[0] = 1;
    for(int i = 1; i < 21; i ++) {
        factorial[i] = factorial[i - 1] * i;
    }

    switch (in) {
        case 1:
            cin >> cnt;
            for(int i = 0; i < N; i ++) {
                for(int f = 1; f <= N; f ++) {
                    if(use[f] == 1)
                        continue;
                    if(factorial[N - i - 1] < cnt) {
                        cnt -= factorial[N - i - 1];
                    } else {
                        v.push_back(f);
                        use[f] = 1;
                        break;
                    }
                }
            }

            for(int i = 0; i < N; i ++) {
                cout << v[i] << " ";
            }
            break;

        case 2:
            for(int i = 0; i < N; i ++) {
                int t;
                cin >> t;
                v.push_back(t);
            }

            for (int ii = 0; ii < N; ii++) {
                for (int j = 1; j < v[ii]; j++) {
                    if (use[j] == 0) {
                        ans += factorial[N - ii - 1];
                    }
                }

                use[v[ii]] = 1;
            }

            cout << ans + 1 << '\n';
            break;
    }
    return 0;
}
