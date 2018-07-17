#include <iostream>

using namespace std;

int N, M;
int arr[101][101];
int arr2[101][101];

int main() {
    cin >> N >> M;
    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {
            cin >> arr[r][c];
        }
    }
    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {
            cin >> arr2[r][c];
        }
    }
    for(int r = 0; r < N; r ++) {
        for(int c = 0; c < M; c ++) {
            cout << arr[r][c] + arr2[r][c] << ' ';
        }
        cout << '\n';
    }
    return 0;
}