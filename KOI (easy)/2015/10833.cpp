#include <iostream>

using namespace std;

int N;
int arr[101][2];
int sum = 0;

int main() {

    cin >> N;

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < 2; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < N; i++) {
        sum += arr[i][1]%arr[i][0];
    }

    cout << sum;

    return 0;
}