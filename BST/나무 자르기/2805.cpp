#include <iostream>

using namespace std;

int M, N;
int trees[1000001];

int main() {

    cin >> N >> M;

    long long start = 0;
    long long end = 0;
    for(int i = 0; i < N; i ++) {
        cin >> trees[i];
        if(end < trees[i])
            end = trees[i];
    }

    long long ans = 0;
    long long mid;
    while(start <= end) {
        long temp = 0;
        mid = (start + end)/2;
        for(int i = 0; i < N; i ++) {
            // 음수일때 조심
            if(trees[i] - mid >= 0)
                temp += trees[i] - mid;
        }

        if(temp >= M) {
            start = mid + 1;
            if(mid > ans) {
                ans = mid;
            }
        } else {
            end = mid - 1;
        }
    }
    cout << ans;
    return 0;
}
