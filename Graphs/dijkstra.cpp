#include <climits>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;
typedef pair<int, int> ii;

const int MAX = 1e5;

int dist[MAX];
vector<ii> Adj[MAX];

void dijkstra(int a) {
    priority_queue<ii, vector<ii>, greater<ii>> pq;
    pq.push({0, a});
    while (!pq.empty()) {
        auto [w, s] = pq.top();
        pq.pop();
        if (dist[s] > w) {
            dist[s] = w;
            for (int i = 0; i < Adj[s].size(); i++) {
                pq.push({w + Adj[s][i].first, Adj[s][i].second});
            }
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    for (int i = 0; i < e; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        Adj[a].push_back({c, b});
        Adj[b].push_back({c, a});
    }
    int node;
    cin >> node;
    for (int i = 1; i <= n; i++) {
        dist[i] = INT_MAX;
    }
    dijkstra(node);
    for (int i = 1; i <= n; i++) {
        cout << "Node " << i << ": " << dist[i] << endl;
    }
    return 0;
}
