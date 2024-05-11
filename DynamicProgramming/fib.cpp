#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll fib(int n) {
    if (n == 2 || n == 1) return 1;
    return fib(n - 1) + fib(n - 2);
}

ll dp[1000];
ll fibdp(int n) {
    if (dp[n]) return dp[n];
    if (n == 2 || n == 1) {
        dp[n] = 1;
        return dp[n];
    }
    dp[n] = fibdp(n - 1) + fibdp(n - 2);
    return dp[n];
}

int main() {
    int n;
    cin >> n;
    cout << "Fib recursivo com dp: " << fibdp(n) << endl;
    cout << "Fib recursivo normal: " << fib(n) << endl;
}
