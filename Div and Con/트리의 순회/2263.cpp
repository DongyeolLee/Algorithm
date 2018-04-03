#include <iostream>

using namespace std;

int N;
int inO[100000];
int postO[100000];
int position[100001];

void solve(int in_start, int in_end, int post_start, int post_end) {
    if (in_start > in_end || post_start > post_end) return;
    int root = postO[post_end];
    cout << root << " ";
    int p = position[root];
    int left = p-in_start;

    // left
    solve(in_start, p-1, post_start, post_start + left - 1);
    // right
    solve(p+1, in_end, post_start+left, post_end-1);
}

int main() {

    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> inO[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> postO[i];
    }
    for (int i = 0; i < N; i++) {
        position[inO[i]] = i;
    }

    solve(0, N-1, 0, N-1);
    return 0;
}