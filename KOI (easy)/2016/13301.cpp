#include <iostream>

using namespace std;

int N; // 타일의 수
long long temp; // 임시 박스
long long arr[80][4]; // 4변의 길이 저장
long long shLine; // 짧은 변
long long loLine; // 긴 변

int main() {

    cin >> N;

    arr[0][0] = 1;
    arr[0][1] = 1;
    arr[0][2] = 1;
    arr[0][3] = 1;

    shLine = arr[0][0];
    loLine = arr[0][1] + arr [0][0];

    for (int i = 1; i < N; i++) {
        for (int j = 0; j < 4; j++) {
            j % 2 == 0 ? arr[i][j] = shLine : arr[i][j] = loLine;
        }

        temp = shLine;
        shLine = loLine;
        loLine = shLine + temp;
    }

    cout << 2*(arr[N-1][0]+arr[N-1][1]);

    return 0;
}