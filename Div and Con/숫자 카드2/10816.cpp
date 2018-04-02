#include <iostream>
#include <cstring>

using namespace std;

int N, M;
int arr[20000001];
int ans[500000];

int main() {

    cin >> N;
    memset(arr, 0, sizeof(arr));
    for(int i = 0; i < N; i ++) {
        int idx;
        cin >> idx;
        if(idx < 0) {
            idx *= -1;
            idx += 10000000;
        }

        arr[idx] ++;
    }

    cin >> M;
    for(int i = 0; i < M; i++) {
        int temp;
        cin >> temp;
        if(temp < 0){
            temp *= -1;
            temp += 10000000;
        }

        ans[i] = temp;
    }

    for(int i = 0; i < M; i++) {
        int idx = ans[i];
        cout << arr[idx] <<" ";
    }

    return 0;
}