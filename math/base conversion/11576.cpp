#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

int A, B, m;
vector<int > v;

int main() {

    cin >> A >> B;
    cin >> m;

    int temp;
    int decimal = 0;
    for(int i = 0; i < m; i++) {
        cin >> temp;
        decimal += temp * pow(A, m - i - 1);
    }

    while(decimal) {
        v.push_back(decimal % B);
        decimal /= B;
    }

    reverse(v.begin(), v.end());

    long size = v.size();
    for(int i = 0; i < size; i ++) {
        cout << v[i] << ' ';
    }

    return 0;
}
