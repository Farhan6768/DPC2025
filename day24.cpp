#include <iostream>
#include <vector>
using namespace std;

class Graph {
    int V;
    vector< vector<int> > adj;  

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u); 
    }

    bool dfs(int node, int parent, vector<bool> &visited) {
        visited[node] = true;

        for (size_t i = 0; i < adj[node].size(); i++) {
            int neighbor = adj[node][i];

            if (!visited[neighbor]) {
                if (dfs(neighbor, node, visited))
                    return true;
            }
            else if (neighbor != parent) {
                return true; 
            }
        }
        return false;
    }

    bool hasCycle() {
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, visited))
                    return true;
            }
        }
        return false;
    }
};

int main() {
    int V, E;
    cout << "Enter number of vertices: ";
    cin >> V;
    cout << "Enter number of edges: ";
    cin >> E;

    Graph g(V);

    cout << "Enter edges (u v):\n";
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    if (g.hasCycle())
        cout << "Graph contains a cycle\n";
    else
        cout << "Graph does not contain a cycle\n";

    return 0;
}
/*
Enter number of vertices: 5
Enter number of edges: 5
Enter edges (u v):
0 1
1 2
2 3
3 4
4 0
Graph contains a cycle
*/
  
