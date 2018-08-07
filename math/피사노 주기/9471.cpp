#include<iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int T, m, m1, m2, period;

    while (n--) {
        cin >> T >> m;

        m1 = 0;
        m2 = 1;
        period = 0;

        while(1) {
            if(m1 == 0 && m2 == 1 && period != 0) {
                break;
            }
            int temp = m1;
            m1 = m2;
            m2 = (temp + m1) % m;
            period ++;
        }

        cout << T << ' ' << period << endl;
    }
    return 0;
}