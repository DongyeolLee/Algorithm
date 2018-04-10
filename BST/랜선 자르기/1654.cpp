#include <iostream>

using namespace std;

int K, N;
int lan[10000];

int main() {

    cin >> K >> N;

    long long start = 1;
    long long end = 0;
    for(int i = 0; i < K; i ++) {
        cin >> lan[i];
        if(end < lan[i])
            end = lan[i];
    }

    long long ans = 0;
    long long mid;
    while(start <= end) {
        int temp = 0;
        mid = (start + end)/2;
        for(int i = 0; i < K; i ++) {
            temp += lan[i] / mid;
        }

        if(temp >= N) {
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
