#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adj;
    vector<bool> visited;    

public:
    Graph(int size) {
        this->size = size;
        this->adj.resize(size + 1);
        this->visited.resize(size + 1, false); 
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    void dfs(int start) {
        visited[start] = true;  

        for (int item : adj[start]) {
            if (!visited[item]) {
                dfs(item);
            }
        }
    }

    int findMinConnectAll() {
        int count = 0;

        for (int i = 1; i <= size; ++i) {
            if (!visited[i]) {
                dfs(i);
                count++;
            }
        }

        return count - 1;
    }
};

int main() {    
    int n, m; // towns, roads
    cin >> n >> m;

    Graph g(n);

    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        g.addEdge(a, b);
    }

    int minEdges = g.findMinConnectAll();
    cout << minEdges;

    return 0;
}
