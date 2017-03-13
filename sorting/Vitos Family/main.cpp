#include <iostream>

using namespace std;

int test, r, sum;
int arr[30000];
int ca[30000];
int p, dis;

void findHose() {

    for (int i = 0; i < r; i++) {
        sum = 0;
        p = 0;
        for (int j = 0; j < r; j++) {
            arr[j] - arr[i] > 0 ? p = arr[j] - arr[i] : p = -(arr[j] - arr[i]);
            sum += p;
        }
        ca[i] = sum;
    }

    return;
}

int main() {

    cin >> test;

    for (int i = 0; i < test; i++) {
        cin >> r;
        for (int j = 0; j < r; j++) {
            cin >> arr[j];
        }
        findHose();

        dis = ca[0];
        for (int j = 0; j < r; j++) {

            if (ca[j] < dis) {
                dis = ca[j];
            }
        }
        cout << dis << endl;

    }

    return 0;
}