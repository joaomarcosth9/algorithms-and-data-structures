#include <bits/stdc++.h>

using namespace std;

const int maxn = 2e5 + 5;
int arr[maxn];
int t[maxn * 2];

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) t[i + n] = arr[i];
    for (int i = n - 1; i; i--) t[i] = t[i << 1] + t[i << 1 | 1];
    for (int i = 0; i < 2 * n; i++) {
        cout << t[i] << " ";
    }
    cout << endl;
    while (1) {
        char op;
        /* cin >> op; */
        if (1 || op == 'q') {
            int res = 0;
            int l, r;
            cin >> l >> r;
            for (l += n, r += n + 1; l < r; l >>= 1, r >>= 1) {
                if (l & 1) res += t[l++];
                if (r & 1) res += t[--r];
            }
            cout << res << endl;
        }
    }
}

int main() {
    solve();
    return 0;
}
