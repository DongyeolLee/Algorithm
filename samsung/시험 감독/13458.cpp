#include <iostream>

using namespace std;

int N;
int studentNum[1000001];
int captain;
int vice;

int main() {

    cin >> N;
    for(int i = 1; i <= N; i ++) {
        cin >> studentNum[i];
    }
    cin >> captain >> vice;

    long long ans = N;
    for(int i = 1; i <= N; i ++) {
        studentNum[i] = studentNum[i] - captain;
        int students = studentNum[i];
        int temp;

        if(students > 0) {
            if(students % vice == 0) {
                temp = students / vice;
            } else {
                temp = (students / vice) + 1;
            }
            ans += temp;
        }
    }
    cout << ans;
    return 0;
}