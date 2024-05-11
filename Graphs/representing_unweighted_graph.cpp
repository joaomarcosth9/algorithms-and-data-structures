#include <bits/stdc++.h>

using namespace std;

// forma de representar o grafo do problema das ilhas

void build_graph(int nodes, int edges, vector<set<int>> &Graph) {
    for (int i = 0; i < edges; i++) {
        int a, b;
        cin >> a >> b;
        Graph[a].insert(b);
        Graph[b].insert(a);
    }
}

void print_graph(int n, vector<set<int>> &Graph) {
    for (int i = 1; i <= n; i++) {
        cout << i << ": ";
        for (auto a : Graph[i]) {
            cout << a << ' ';
        }
        cout << endl;
    }
}

int main() {
    int n, m;
    cout << "Insert nodes and edges numbers: ";
    cin >> n >> m;
    vector<set<int>> V(n + 1);
    cout << "BUILDING GRAPH" << endl;
    build_graph(n, m, V);
    cout << "PRINTING GRAPH" << endl;
    print_graph(n, V);
    return 0;
}
