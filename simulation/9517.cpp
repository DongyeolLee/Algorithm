#include <iostream>
#include <vector>

using namespace std;

int K, N, T, remain_time = 210;
char Z;
vector<pair<int, char>> arr;

int main() {
    cin >> K >> N;
    for(int i = 0; i < N; i ++) {
        cin >> T >> Z;
        arr.push_back({ T, Z });
    }

    for(int i = 0; i < arr.size(); i ++) {
        int time = arr[i].first;
        char ans = arr[i].second;

        if(ans == 'T') {
            remain_time -= time;
            if(remain_time < 0) {
                int num =  K % 8 == 0? 8 : K % 8;
                cout << num;
                return 0;
            }
            else {
                K ++;
            }
        } else {
            remain_time -= time;
            if(remain_time < 0) {
                int num =  K % 8 == 0? 8 : K % 8;
                cout << num;
                return 0;
            }
        }
    }
}
