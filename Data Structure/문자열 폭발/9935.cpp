#include <iostream>
#include <string>

using namespace std;

int m, n;
char ans[1000001];
string s, ex;

bool isMatching(int s) {
    for (int i = s ; i < s + m ; ++i) {
        if (ans[i] != ex[i - s]) {
            return false;
        }
    }
    return true;
}

int main() {

    cin >> s >> ex;

    n = s.length();
    m = ex.length();

    int pos = 0;
    for (int i = 0 ; i < n ; ++i) {
        ans[pos] = s[i];
        pos++;
        if (pos - m >= 0 && isMatching(pos - m)) {
            pos -= m;
        }
    }

    ans[pos] = '\0';

    if(!pos)
        printf("FRULA");

    cout << ans;
    return 0;
}
