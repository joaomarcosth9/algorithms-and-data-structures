#include <bits/stdc++.h>

using namespace std;

struct fenwick {
    vector<int> bit;
    int n;
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
};


int main(){
    int n; cin >> n;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    fenwick ft(v);
    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        cout << ft.sum(l,r) << endl;

    }
    return 0;
}
