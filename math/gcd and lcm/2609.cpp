#include <iostream>

using namespace std;

int N, M;
int gcd, lcm;

int getGCD(int a, int b) {
    return b ? getGCD(b, a%b) : a;
}

int main() {

    cin >> N >> M;

    gcd = getGCD(N, M);
    lcm = (N * M) / gcd;

    cout << gcd << endl;
    cout << lcm << endl;
    return 0;
}