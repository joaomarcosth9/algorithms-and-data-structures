#include <bits/stdc++.h>
using namespace std;

int temtestcase = 0;
const int INF = 1.05e9;
const long long LINF = 4.5e18;
using ll = long long;
using vi = vector<int>;
using ii = pair<int, int>;
using vii = vector<ii>;
template <typename T> using pql = priority_queue<T>;
template <typename T> using pqg = priority_queue<T, vector<T>, greater<T>>;
#define mp make_pair
#define fst first
#define snd second
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define sor(x) sort(all(x))
#define rsor(x) sort(rall(x))
#define pb push_back
#define eb emplace_back
#define FOR(i, x, y) for (int i = x; i < y; i++)
#define ROF(i, x, y) for (int i = x - 1; i >= y; i--)
#define FO(x) FOR(i, 0, x)
#define OF(x) ROF(i, x, 0)
#define endl '\n'
#define ever (;;)

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &a : v) cin >> a;
    int len = ceil(sqrt((double)n));
    vi b(len);
    for (int i = 0; i < n; i++) {
        b[i / len] += v[i];
    }
    cout << "Array:\n";
    for (auto a : v) {
        cout << a << ' ';
    }
    cout << endl;
    cout << "Sqrt:\n";
    for (auto a : b) {
        cout << a << ' ';
    }
    cout << endl;
    for
        ever {
            int sum = 0, sumn = 0, nop = 0;
            int l, r;
            cin >> l >> r;
            int nopn = r - l + 1;
            for (int i = l; i <= r; i++) sumn += v[i];
            int l_block = l / len, r_block = r / len;
            if (l_block == r_block) {
                for (; l <= r; l++, nop++) sum += v[l];
            } else {
                cout << " ---- 1 ----\n";
                for (int i = l, end = (l_block + 1) * len - 1; i <= end && (i % len != 0); i++) {
                    cout << i << endl;
                    sum += v[i];
                    nop++;
                }
                cout << " ---- 2 ----\n";
                for (int i = l_block + (l % len != 0); i <= r_block - (r != n - 1 && (r + 1) % len != 0); i++) {
                    cout << i << endl;
                    sum += b[i];
                    nop++;
                }
                cout << " ---- 3 ----\n";
                for (int i = r_block * len; i <= r && (r != n - 1 && (r + 1) % len != 0); i++) {
                    cout << i << endl;
                    sum += v[i];
                    nop++;
                }
            }
            cout << "---------------" << endl;
            if (sum == sumn) {
                cout << "OK " << sum << " (" << nop << " vs " << nopn << ")" << endl;
            } else {
                cout << "DEU RUIM " << sumn << ' ' << sum << endl;
            }
        }
}

int main() {
#ifndef LOCAL_DEBUG
    ios_base::sync_with_stdio(0);
    cin.tie(0);
#endif
    int tsts = 1;
    if (temtestcase) cin >> tsts;
    for (int Testcase = 1; Testcase <= tsts; Testcase++) {
        /* clog << db(Testcase) << endl; */
        solve();
    }
    return 0;
}
