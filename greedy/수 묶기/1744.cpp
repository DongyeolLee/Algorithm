#include <iostream>
#include <algorithm>
#include <functional>
#include <vector>

using namespace std;

int N, zero, one;
vector<int> positive;
vector<int> negative;

int cal(vector<int> arr) {
    int ans = 0;
    auto size = (int)arr.size();
    int loop = size/2;
    for(int i = 0, idx = 0; i < loop; i ++, idx = idx + 2){
        ans += (arr[idx] * arr[idx + 1]);
    }
    if(size % 2 == 1){
        if(zero > 0 && arr.back() < 0) {

        } else {
            ans += arr.back();
        }
    }
    return ans;
}

int main() {

    cin >> N;

    int num;
    one = 0;
    zero = 0;
    for(int i = 0; i < N; i ++) {
        cin >> num;
        if(num == 1) {
            one++;
        } else if(num > 0) {
            positive.push_back(num);
        } else if(num < 0) {
            negative.push_back(num);
        } else {
            zero ++;
        }
    }

    sort(positive.begin(), positive.end(), greater<int>());
    sort(negative.begin(), negative.end());

    // 1을 따로 처리해줘야 추후 1, 2 가 입력됐을때 2가 아니라 3이 출력되야 함
    int ans = one;
    int negative_max = 0, positive_max = 0;

    if(negative.size() > 1) {
        negative_max = cal(negative);
    } else if(negative.size() == 1) {
        if(zero) {
            negative_max = 0;
        } else
            negative_max = negative[0];
    }

    if(positive.size() > 1) {
        positive_max = cal(positive);
    } else if(positive.size() == 1) {
        positive_max = positive[0];
    }

    ans += positive_max + negative_max;
    cout << ans << '\n';
    return 0;
}
