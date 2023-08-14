#include <iostream>
#include <queue>
#include <vector>
using namespace std;

#define MAX 20010
#define INF 987654321

vector<pair<int, int>> adj[MAX];
int Dist[MAX];
int V, E, V1, V2;

void input() {
    cin >> V >> E;
    for (int i = 0; i < E; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(b, c));
        adj[b].push_back(make_pair(a, c));
    }
}

int dijkstra(int S, int D) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> PQ;
    for (int i = 1; i <= V; i++) 
    {
        Dist[i] = INF;
    }

    Dist[S] = 0;
    PQ.push(make_pair(Dist[S], S));

    while (!PQ.empty()) {
        int cost = PQ.top().first;
        int curr = PQ.top().second;
        PQ.pop();

        for (int i = 0; i < adj[curr].size(); i++) {
            int D = adj[curr][i].first;
            int D_cost = adj[curr][i].second;

            if (Dist[D] > cost + D_cost) {
                Dist[D] = cost + D_cost;
                PQ.push(make_pair(Dist[D], D));
            }
        }
    }
    return Dist[D];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    input();
    cin >> V1 >> V2;

    // Calculate shortest paths
    int ans = INF;
    ans = min(ans, dijkstra(1, V1) + dijkstra(V1, V2) + dijkstra(V2, V));
    ans = min(ans, dijkstra(1, V2) + dijkstra(V2, V1) + dijkstra(V1, V));

    if (ans >= INF || dijkstra(V1, V2) == INF)
        cout << -1;
    else
        cout << ans;
    return 0;
}
