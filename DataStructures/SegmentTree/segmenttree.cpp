#include <iostream>
#include <vector>
#include <climits>

using namespace std;
const int MAX = 1e5;

int segtree[MAX];

int lc (int n){ return 2*n+1; }
int rc (int n){ return 2*n+2; }

namespace seg {
    int s;
    void build(int n, int lef, int rig, vector<int>& V){
        if(lef == rig){
            segtree[n] = V[lef];
            return;
        }
        int mid = (lef+rig)/2;
        build(lc(n), lef, mid, V);
        build(rc(n), mid+1, rig, V);
        segtree[n] = segtree[lc(n)] + segtree[rc(n)];
    }
    void build(vector<int>& V){ build(0, 0, s-1, V); }

    int query(int n, int l, int r, int ll, int rr){
        if(l >= ll && r <= rr){
            return segtree[n];
        } else if (r < ll || l > rr){
            return 0;
        } else {
            int mid = (l+r)/2;
            return query(lc(n), l, mid, ll, rr) + query(rc(n), mid+1, r, ll, rr);
        }
    }
    int query(int ll, int rr){ return query(0, 0, s-1, ll, rr); }

    void update(int n, int l, int r, int id, int v){
        if(l == r && l == id){
            segtree[n] = v;
            return;
        } else if (r < id || l > id){
            return;
        } else {
            int mid = (l+r)/2;
            update(lc(n), l, mid, id, v);
            update(rc(n), mid+1, r, id, v);
        }
        segtree[n] = segtree[lc(n)] + segtree[rc(n)];
    }
    void update(int id, int v){ update(0, 0, s-1, id, v); }
}

int main(){
    cout << "Input 2 values, n (array size) and q (number of queries): ";
    int n, q; cin >> n >> q;
    seg::s = n;
    cout << "Input " << n << " integer numbers: ";
    vector<int> V(n);
    for(int i = 0; i < n; i++) cin >> V[i];
    seg::build(V);
    cout << endl;
    cout << "Seg Tree: ";
    for(int i = 0; i < 4*n; i++){
        cout << segtree[i] << ' ';
    }
    cout << endl << endl;
    while(q--){
        cout << "Input a range of the array to query the sum (-1 for update): ";
        int ll, rr; cin >> ll >> rr;
        if(ll < 0 || rr < 0){
            cout << "Input a index and the new value: ";
            int id, v; cin >> id >> v;
            seg::update(id-1, v);
            V[id-1] = v;
            cout << "Array: ";
            for(int i = 0; i < n; i++) cout << V[i] << ' ';
            cout << endl;
            cout << "Seg Tree: ";
            for(int i = 0; i < 4*n; i++){
                cout << segtree[i] << ' ';
            }
            cout << endl;
        } else {
            int res = seg::query(ll-1, rr-1);
            cout << "Sum in range " << ll << " to " << rr << ": " << res << endl;
        }
    }
    return 0;
}
