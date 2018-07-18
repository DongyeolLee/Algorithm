#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<long long> arr;
int temp, minA = 987654321, minB = 987654321;
long long ans = 3000000000;

bool compare(long long a, long long b) {
    return abs(a) < abs(b);
}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }

    sort(arr.begin(), arr.end(), compare);

    for (int i = 0; i < N - 1; i++) {

        if (abs(arr[i] + arr[i + 1]) < ans) {
            ans = abs(arr[i] + arr[i + 1]);
            minA = arr[i];
            minB = arr[i + 1];
        }
    }

    if (minA < minB)
        cout << minA << " " << minB;
    else
        cout << minB << " " << minA;

    return 0;
}
