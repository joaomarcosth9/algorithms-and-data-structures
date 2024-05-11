#include <bits/stdc++.h>

using namespace std;

int main() {
    set<char> s = {'a', 'b', 'c', 'd'};
    char key = 'd';

    s.erase(key);

    for (auto a : s) {
        cout << a << ' ';
    }

    return 0;
}
