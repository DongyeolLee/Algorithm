#include <iostream>

int main() {

    int start, finish, max, temp = 0, count = 1;

    while (std::cin >> start >> finish) {

        int tempStart = start;
        int tempFinish = finish;

        if(tempStart > tempFinish) {
            int ch = tempFinish;
            tempFinish = tempStart;
            tempStart = ch;
        }

        max = 0;
        for (int i = tempStart; i <= tempFinish; i++) {


            temp = i;
            count = 1;
            while (temp != 1) {

                if (temp % 2 == 0) {
                    temp = temp / 2;
                    count++;
                } else {
                    temp = (temp * 3) + 1;
                    count++;
                }

            }
            if (max < count) {
                max = count;
            }
        }

        std::cout << start  << " " << finish << " " << max << std::endl;
    };
    return 0;
}