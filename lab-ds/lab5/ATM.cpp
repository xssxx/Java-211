#include <iostream>
#include <utility>
#include <queue>

using namespace std;

int main() {
    int count, max;
    cin >> count >> max;
    queue<pair<int, int> > q; // index, amount

    for (int i = 1; i <= count; i++) {
        int amount;
        cin >> amount;
        q.push(make_pair(i, amount));
    }

    while (!q.empty()) {
        int index = q.front().first;
        int amount = q.front().second;
        if (amount - max <= 0) {
            cout << index << " ";
            q.pop();
        } else {
            amount -= max;
            q.pop();
            q.push(make_pair(index, amount));
        }
    }

    return 0;
}