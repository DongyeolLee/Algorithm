#include <iostream>
#include <cstring>

using namespace std;

int N;
int arr[10001];

int main() {

    cin >> N;

    memset(arr, 0, sizeof(arr));

    int num = 0;
    for(int i = 0; i < N; i ++) {
        cin >> num ;
        arr[num] += 1;
    }

    for(int i = 1; i <= 10000; i ++) {
        if(arr[i] > 0) {
            for(int j = 0; j < arr[i]; j ++) {
                cout << i << '\n';
            }
        }
    }

    return 0;
}

