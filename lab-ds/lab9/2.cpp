#include <iostream>
#include <vector>

using namespace std;

class Graph {
private:
    int size;
    vector<vector<int>> adj;
    bool *visited;

    bool isCycle(int v, bool visited[], int parent) {
        visited[v] = true;

        for (auto i = adj[v].begin(); i != adj[v].end(); ++i) {
            if (!visited[*i]) {
                if (isCycle(*i, visited, v)) {
                    return true;
                }
            } else if (*i != parent) {
                return true;
            }
        }

        return false;
    }

public:
    Graph(int size) {
        this->size = size;
        adj.resize(size + 1);
        visited = new bool[size]();
    }

    void addEdge(int u, int v) {
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    bool isTree() {
        if (isCycle(0, visited, -1))
            return false;
        
        for (int u = 0; u < size; u++)
            if (!visited[u])
                return false;

        return true;
    }
};

int main() {
    int v, e;
    cin >> v >> e;

    Graph g(v);

    for (int i = 0; i < e; ++i) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }

    cout << (g.isTree() ? "YES" : "NO");

    return 0;
}