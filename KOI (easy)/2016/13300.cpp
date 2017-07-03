#include <iostream>
#include <cstring>
#include <math.h>

using namespace std;

int K; // 방의 최대 인원 수
int N; // 학생 수
int S; // 성별
int Y; // 학년
int cnt; // 방의 수
int arr[2][6]; // 학년 별 인원

int main() {

    cin >> N;
    cin >> K;

    cnt = 0;
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < N; i++) {
        cin >> S;
        cin >> Y;

        arr[S][Y-1]++;

    }

    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 6; j++){
            double temp;

            temp = arr[i][j] / (double)K;
            cnt += ceil(temp);
        }
    }

    cout << cnt;

    return 0;
}