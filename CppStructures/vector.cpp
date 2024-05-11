#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> A;

vector<int> B(10, 5);

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int s;
        cin >> s;
        vector<int> Vei(s);
        for (int j = 0; j < s; j++) {
            cin >> Vei[j];
        }
        A.push_back(Vei);
    }

    cout << endl << "Printando vectors: " << endl;

    for (auto a : A) {
        for (auto b : a) {
            cout << b << ' ';
        }
        cout << endl;
    }
    return 0;
}
