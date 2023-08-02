#include <iostream>
#include <queue>

using namespace std;

int main() {
    int n;
    cin >> n;
    string output;
    queue<int> q;

    for (int i = 0; i < n; i++) {
        int op, num;
        cin >> op;

        if (op == 1) {
            cin >> num;
            q.push(num);
        } else if (op == 2 && !q.empty()) {
            q.pop();
        } else if (op == 3) {
            output += q.empty() ? "EMPTY\n" : to_string(q.front()) + '\n';
        } else if (op == 4) {
            output += to_string(q.size()) + '\n';
        }
    }

    cout << output;

    return 0;
}