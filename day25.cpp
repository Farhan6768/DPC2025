#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int shortestPath(int V, vector< pair<int,int> > &edges, int start, int end) {
    vector< vector<int> > graph(V);
    for (int i = 0; i < edges.size(); i++) {
        int u = edges[i].first;
        int v = edges[i].second;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    vector<bool> visited(V, false);
    vector<int> dist(V, -1);

    queue<int> q;
    visited[start] = true;
    dist[start] = 0;
    q.push(start);

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        if (node == end) return dist[node];

        for (int j = 0; j < graph[node].size(); j++) {
            int neighbor = graph[node][j];
            if (!visited[neighbor]) {
                visited[neighbor] = true;
                dist[neighbor] = dist[node] + 1;
                q.push(neighbor);
            }
        }
    }
    return -1;
}

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    vector< pair<int,int> > edges;
    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        edges.push_back(make_pair(u, v));  
    }

    int start, end;
    cout << "Enter start and end node: ";
    cin >> start >> end;

    int result = shortestPath(V, edges, start, end);

    if (result != -1)
        cout << "Shortest path length: " << result << endl;
    else
        cout << "No path exists." << endl;

    return 0;
}
/*
Enter number of vertices: 5
Enter number of edges: 5
Enter edges (u v):
0 1
0 2
1 3
2 3
3 4
Enter start and end node: 0 4
Shortest path length: 3
  */

