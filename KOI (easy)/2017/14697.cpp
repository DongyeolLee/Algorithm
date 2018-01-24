#include <iostream>

using namespace std;

int A, B, C, st, success;
int temp1, temp2, temp3;

int main() {

    cin >> A >> B >> C >> st;


    for(int i = 0; i <= 113; i ++) {
        temp1 = A * i;

        for(int j = 0; j <= 113; j ++) {
            temp2 = B * j;

            for(int z = 0; z <= 113; z ++) {
                temp3 = C * z;

                if(temp1 + temp2 + temp3 == st) {
                    cout << 1 << endl;
                    return 0;
                }
            }
        }
    }

    cout << 0 << endl;

    return 0;
}
