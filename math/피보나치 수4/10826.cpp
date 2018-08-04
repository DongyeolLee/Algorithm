#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

string dp[10001];
int n;

string calc(string s, string s2) {
    string ret;
    int len, len2;
    int a, b, carry_before, carry_now;

    len = s.length();
    len2 = s2.length();

    carry_now = 0;

    if (len < len2) {

        for (int i = 0; i < len2 - len; i++) {

            s.insert(s.begin(), '0');
        }

        len = len2;
    } else if (len2 < len) {

        for (int i = 0; i < len - len2; i++) {

            s2.insert(s2.begin(), '0');
        }
    }

    for (int i = len - 1; 0 <= i; i--) {

        a = s[i] - '0';
        b = s2[i] - '0';

        carry_before = carry_now;

        if (a + b + carry_before < 10) {

            carry_now = 0;
            ret += (a + b + carry_before) + '0';
        }

        else {

            carry_now = 1;
            ret += (a + b + carry_before - 10) + '0';

            if (i == 0 && carry_now == 1) ret += '1';
        }
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main() {
    cin >> n;
    dp[0] = '0';
    dp[1] = '1';
    for (int i = 2; i <= n; i++) {
        dp[i] = calc(dp[i - 1], dp[i - 2]);
    }

    cout << dp[n];
    return 0;
}
