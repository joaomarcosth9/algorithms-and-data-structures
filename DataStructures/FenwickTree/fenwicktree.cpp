#include <bits/stdc++.h>

using namespace std;

class fenwick {
private:
    vector<int> bit;
    int n;
public:
    fenwick (int inp){
        n = inp;
        bit.assign(n, 0);
    }
    fenwick (vector<int> a) : fenwick(a.size()) {
        for(int i = 0; i < (int)a.size(); i++) add(i, a[i]);
    }
    int sum(int r){
        int res = 0;
        while(r >= 0){
            res += bit[r];
            r = (r & (r + 1)) - 1;
        }
        return res;
    }
    int sum(int l, int r){
        return sum(r) - sum(l-1);
    }
    void add(int i, int d){
        while(i < n){
            bit[i] += d;
            i = (i | (i + 1));
        }
    }
    void printbit(){
        for(auto a : bit){
            cout << a << ' ';
        }
        cout << endl;
    }
};


int main(){
    cout << "n (array size): ";
    int n; cin >> n;
    vector<int> v(n);
    cout << "n values for the array: ";
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    fenwick ft(v);
    cout << "q (number of queries): ";
    int q; cin >> q;
    while(q--){
        cout << "l,r to query sum (-1 to update): ";
        int l,r; cin >> l >> r;
        if(l == -1 || r == -1){
            cout << "index to update and value: ";
            ft.printbit();
            int a,b; cin >> a >> b;
            ft.add(a,b);
            ft.printbit();
        } else {
            cout << ft.sum(l,r) << endl;
        }

    }
    return 0;
}
