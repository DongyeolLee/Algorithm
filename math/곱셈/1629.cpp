#include <iostream>

using namespace std;

long long A, B, C;

long long cal(long long A, long long B) {
    if(B == 0) return 1;
    if(B == 1) return A % C;
    if(B % 2 == 0) {
        long long temp = cal(A, B / 2);
        return (temp * temp) % C;
    } else {
        return (A * cal(A, B - 1) % C);
    }
}

int main() {
    cin >> A >> B >> C;
    cout << cal(A, B) << endl;
    return 0;
}