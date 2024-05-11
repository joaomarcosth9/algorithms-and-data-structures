#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL_DEBUG
#include "debug.h"
#else
#define db(x...)
#endif

const int MAXN = 3e5 + 5;

vector<int> adjList[MAXN], revAdjList[MAXN], ts;
bool vis[MAXN], edge_in[MAXN], edge_out[MAXN];
int comp[MAXN], head[MAXN], parent = 0, numSCC;

void revdfs(int u) {
    vis[u] = true;
    for (int i = 0, v; i < (int)revAdjList[u].size(); i++) {
        v = revAdjList[u][i];
        if (!vis[v]) revdfs(v);
    }
    ts.push_back(u);
}

void dfs(int u) {
    vis[u] = true;
    comp[u] = parent;
    for (int i = 0, v; i < (int)adjList[u].size(); i++) {
        v = adjList[u][i];
        if (!vis[v]) dfs(v);
    }
}

void kosaraju(int n) {
    memset(&vis, false, sizeof vis);
    for (int i = 0; i < n; i++) {
        if (!vis[i]) revdfs(i);
    }
    memset(&vis, false, sizeof vis);
    numSCC = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (!vis[ts[i]]) {
            parent = ts[i];
            head[parent] = ts[i];
            dfs(ts[i]);
            numSCC++;
        }
    }
}

void solve() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) {
        int u;
        cin >> u;
        u--;
        adjList[i].push_back(u);
        revAdjList[u].push_back(i);
    }
    kosaraju(n);
    if (numSCC == 1) {
        cout << 0 << endl;
        return;
    }
    vector<int> sinks, sources;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < (int)adjList[i].size(); j++) {
            edge_out[comp[i]] = edge_in[comp[adjList[i][j]]] = 1;
        }
    }
    for (int i = 0; i < numSCC; i++) {
        if (!edge_out[i]) sinks.push_back(head[i]);
    }
    for (int i = 0; i < numSCC; i++) {
        if (!edge_in[i]) sources.push_back(head[i]);
    }
    db(sources, sinks);
    cout << max(sources.size(), sinks.size()) << endl;
    vector<pair<int, int>> res;
    if (sources.size() > sinks.size()) {
        // mais sources que sinks
        int ssz = sinks.size();
        for (int i = 0, j = 1 % ssz; i < (int)sources.size(); i++, j = (j + 1) % ssz) {
            res.emplace_back(sinks[j], sources[i]);
        }
    } else {
        // mais sinks que sources
        int ssz = sources.size();
        for (int i = 0, j = 1 % ssz; i < (int)sinks.size(); i++, j = (j + 1) % ssz) {
            res.emplace_back(sinks[i], sources[j]);
        }
    }
    for (auto [u, v] : res) {
        cout << u << " " << v << endl;
    }
}

int main() {
    solve();
    return 0;
}
