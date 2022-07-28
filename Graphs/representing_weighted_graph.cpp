#include <bits/stdc++.h>

using namespace std;

// forma de representar o grafo do problema das ilhas

void build_graph(int nodes, int edges, vector<vector<pair<int, int>>>& Graph){
    for (int i = 0; i < edges; i++){
        int a, b, c;
        cin >> a >> b >> c;
        Graph[a].push_back({b,c});
        Graph[b].push_back({a,c});
    }
}

void print_graph(int n, vector<vector<pair<int, int>>>& Graph){
    for (int i=1; i <= n; i++){
        cout << i << ':';
        for (int j = 0; j < Graph[i].size(); j++){
            cout << '(' << Graph[i][j].first << ',' << Graph[i][j].second << ')' << ' ';
        }
        cout << endl;
    }
}

int main(){
    int n, m;
    cin >> n >> m;
    vector<vector<pair<int,int>>> V(n+1);
    cout << "BUILDING GRAPH" << endl;
    build_graph(n, m, V);
    cout << "PRINTING GRAPH" << endl;
    print_graph(n, V);
    return 0;
}
