#include <iostream>
#include <algorithm>
#include <vector>   

using namespace std;

int hitCount(vector<int> &healths, int damage) {
    vector<int>::iterator it = upper_bound(healths.begin(), healths.end(), damage);
    return distance(healths.begin(), it);
}

int main() {
    int n;
    cin >> n;
    vector<int> healths(n);

    for (int &health : healths) {
        cin >> health;
    }

    sort(healths.begin(), healths.end());

    int m;
    cin >> m;
    vector<int> hits(m);

    for (int i = 0; i < m; i++) {
        int damage;
        cin >> damage;
        hits[i] = hitCount(healths, damage);
    }

    for (int i = 0; i < m; i++) {
        cout << hits[i] << endl;
    }

    return 0;
}
