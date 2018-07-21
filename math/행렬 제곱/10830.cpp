#include <iostream>
#include <vector>

using namespace std;

int N;
long long B;
int arr[6][6];

vector<vector<int>> mul(long long sq) {
    vector<vector<int>> ans(N, vector<int>(N));
    vector<vector<int>> c(N, vector<int>(N));

    if(sq == 1) {
        for(int i = 0; i < N; i ++) {
            for(int j = 0; j < N; j ++) {
                c[i][j] = arr[i][j] % 1000;
            }
        }

        return c;
    } else if(sq%2 == 0) {
        c = mul(sq/2);

        for(int i = 0; i < N; i ++) {
            for(int j = 0; j < N; j ++) {

                for (int k = 0; k < N; k ++) {
                    ans[i][j] += c[i][k] * c[k][j];
                }
                ans[i][j] %= 1000;
            }
        }

        return ans;
    } else {
        c = mul(sq-1);

        for (int i = 0; i < N; i ++) {
            for (int j = 0; j < N; j ++) {

                for (int k = 0; k < N; k ++) {
                    ans[i][j] += c[i][k] * arr[k][j];
                }
                ans[i][j] %= 1000;
            }
        }
        return ans;
    }
}

int main() {
    cin >> N >> B;

    vector<vector<int>> ans(N, vector<int>(N));

    for(int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cin >> arr[i][j];
        }
    }

    ans = mul(B);

    for(int i = 0; i < N; i ++) {
        for (int j = 0; j < N; j ++) {
            cout << ans[i][j] << ' ';
        }
        cout << '\n';
    }

    return 0;
}
