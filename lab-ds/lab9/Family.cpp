#include <iostream>
#include <vector>

using namespace std;

#define MAX_N 200000

struct Node {
    int data;
    Node* parent;
    vector<Node*> children;
};

vector<Node*> tree(MAX_N);
vector<int> descendants(MAX_N, 0);

void initTree(int n) {
    for (int i = 0; i < n; i++) {
        tree[i] = new Node{ i + 1, nullptr, {} };
    }
}

void addEdge(int parent, int child) {
    tree[child - 1]->parent = tree[parent - 1];
    tree[parent - 1]->children.push_back(tree[child - 1]);
}

void calculateDescendants(Node* node) {
    for (Node* child : node->children) {
        calculateDescendants(child);
        descendants[node->data - 1] += 1 + descendants[child->data - 1];
    }
}

int main() {
    int n;
    cin >> n;

    initTree(n);

    for (int i = 2; i <= n; i++) {
        int parent;
        cin >> parent;
        addEdge(parent, i);
    }

    calculateDescendants(tree[0]);

    for (int i = 0; i < n; i++) {
        cout << descendants[i] << ' ';
        delete tree[i];
    }

    return 0;
}
