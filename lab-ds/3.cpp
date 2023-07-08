#include <iostream>
using namespace std;

int countWire(int poleCount, int poleHeights[]) {
    int wire = 0;

    for (int i = 0; i < poleCount - 1; i++) {
        for (int j = i + 1; j < poleCount; j++) {

            bool canConnect = true;

            for (int k = i + 1; k < j; k++) {
                if (poleHeights[k] >= min(poleHeights[i], poleHeights[j])) {     
                    canConnect = false;
                    break;
                }
            }

            if (canConnect) {
                wire++;
            }
        }
    }

    return wire;
}

int main() {
    int poleCount;
    cin >> poleCount;
    int poleHeights[poleCount];
    
    for (int i = 0; i < poleCount; i++)
        cin >> poleHeights[i];
    
    int result = countWire(poleCount, poleHeights);
    cout << result;

    return 0;
}
