#include <iostream>
#include <set>
#include <map>
using namespace std;

int main() {
    int N;
    cin >> N;
    int left[N], right[N];
    int index[N];
    int maxSetLength = 0;
    
    map<int, set<int> > mapOfSet;

    for (int i = 0; i < N; i++) {
        index[i] = i + 1;
        cin >> left[i] >> right[i];
    }

    for (int i = 0; i < N; i++) {
        int indexToPush = index[i];

        mapOfSet[indexToPush].insert(indexToPush);
        if (left[i] > 0) {
            mapOfSet[indexToPush].insert(left[i]);
            index[left[i] - 1] = indexToPush;
        }
        if (right[i] > 0) {
            mapOfSet[indexToPush].insert(right[i]);
            index[right[i] - 1] = indexToPush;
        }

        int setLength = mapOfSet[indexToPush].size();
        maxSetLength = max(maxSetLength, setLength);
    }

    cout << maxSetLength;

    return 0;
}