#include <iostream>
#include <string>
#include <cstring>


using namespace std;

int s, n;

int counttt = 0;

string number;

char num[10][100][100];

void getHorizontal(int stA, int stB) {

    for (int i = 0; i < s; i++) {
        num[counttt][stA][stB + i] = '-';
    }

    return;
}

void getVertical(int stA, int stB) {

    for (int i = 0; i < s; i++) {
        num[counttt][stA + i][stB] = '|';
    }

    return;
}

void draw() {
    for (int i = 0; i < (2 * s + 3); i++) {
        for (int k = 0; k < number.length(); k++) {
            for (int j = 0; j < s + 2; j++) {
                printf("%c", num[k][i][j]);
            }
            if (k == number.length() - 1) {
            } else {
                printf(" ");

            }
        }
        cout << endl;
    }

    return;
}

int main() {

    while (1) {
        cin >> s >> number;


        if (s == 0 && number[0] - '0' == 0) {
            break;
        }

        memset(num, ' ', sizeof(num));
        counttt = 0;
        for (int i = 0; i < number.length(); i++) {
            n = number[i] - '0';

            switch (n) {
                case 1:
                    getVertical(1, s + 1);
                    getVertical(s + 2, s + 1);
                    break;

                case 2:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, 0);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 3:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 4:
                    getVertical(1, 0);
                    getVertical(1, s + 1);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    break;

                case 5:
                    getHorizontal(0, 1);
                    getVertical(1, 0);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 6:
                    getHorizontal(0, 1);
                    getVertical(1, 0);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    getVertical(s + 2, 0);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 7:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getVertical(s + 2, s + 1);
                    break;

                case 8:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getVertical(1, 0);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    getVertical(s + 2, 0);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 9:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getVertical(1, 0);
                    getHorizontal(s + 1, 1);
                    getVertical(s + 2, s + 1);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;

                case 0:
                    getHorizontal(0, 1);
                    getVertical(1, s + 1);
                    getVertical(1, 0);
                    getVertical(s + 2, s + 1);
                    getVertical(s + 2, 0);
                    getHorizontal((2 * s + 3) - 1, 1);
                    break;
            }
            counttt++;


        }
        draw();
        cout << endl;
    }

    return 0;
}