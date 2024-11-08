#include <bits/stdc++.h>

using namespace std;

class lazy_segtree {
    const int neutral = 0;
#define comp(a, b) ((a) + (b))
  private:
    int nodes;
    vector<int> tree;
    vector<int> lazy;
    int le(int n) { return 2 * n + 1; }
    int ri(int n) { return 2 * n + 2; }
    void build(int n, int esq, int dir, int *st) {
        if (esq == dir)
            tree[n] = st[esq];
        else {
            int mid = (esq + dir) / 2;
            build(le(n), esq, mid, st);
            build(ri(n), mid + 1, dir, st);
            tree[n] = comp(tree[le(n)], tree[ri(n)]);
        }
    }
    int query(int n, int esq, int dir, int l, int r) {
        if (esq > r || dir < l) return neutral;
        if (l <= esq && dir <= r) return tree[n];
        int mid = (esq + dir) / 2;
        return comp(query(le(n), esq, mid, l, r), query(ri(n), mid + 1, dir, l, r));
    }
    void update(int n, int esq, int dir, int x, int v) {
        if (esq > x || dir < x) return;
        if (esq == dir)
            tree[n] = v;
        else {
            int mid = (esq + dir) / 2;
            if (x <= mid)
                update(le(n), esq, mid, x, v);
            else
                update(ri(n), mid + 1, dir, x, v);
            tree[n] = comp(tree[le(n)], tree[ri(n)]);
        }
    }

  public:
    lazy_segtree(int *st, int *en) {
        nodes = int(en - st);
        tree.assign(4 * nodes, neutral);
        lazy.assign(4 * nodes, neutral);
        build(0, 0, nodes - 1, st);
    }
    int query(int l, int r) { return query(0, 0, nodes - 1, l, r); }
    void update(int x, int v) { update(0, 0, nodes - 1, x, v); }
};

int main() { return 0; }
