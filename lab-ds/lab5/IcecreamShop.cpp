#include <iostream>
#include <queue>
using namespace std;

int main() {
    int count, closed;
    cin >> count >> closed;

    priority_queue<int, vector<int>, greater<int>> waitQueue; // Min-Heap

    for (int i = 0; i < count; i++) {
        int wait;
        cin >> wait;
        waitQueue.push(wait);
    }

    int sell = 0;

    while (!waitQueue.empty() && closed > 0) {
        int wait = waitQueue.top();
        waitQueue.pop();

        if (wait <= 0) {
            continue;
        } else {
            sell++;
            closed--;

            priority_queue<int, vector<int>, greater<int>> tempQueue;
            while (!waitQueue.empty()) {
                int currWait = waitQueue.top();
                waitQueue.pop();
                if (currWait > 1) {
                    tempQueue.push(currWait - 1);
                }
            }

            waitQueue = tempQueue;
        }
    }

    cout << sell;

    return 0;
}
