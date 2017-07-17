#include <iostream>

using namespace std;

int M;
int arr[1001][3];
int sum = 1;
int vec = 0;

int main() {

    cin >> M;

    for (int i = 0; i < M; i ++) {
        for (int j = 0; j < 3; j ++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < M; i ++) {
        sum  = sum * arr[i][1] / arr[i][0];
//        sum *= arr[i][1] / arr[i][0];
        vec += arr[i][2];
    }

    cout << vec%2 <<' '<<sum;

    return 0;
}