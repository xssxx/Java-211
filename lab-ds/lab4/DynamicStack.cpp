#include <iostream>
#include <stack>
using namespace std;

int main() {
    int N;
    cin >> N;
    string output;
    stack<int> st;

    for (int i = 0; i < N; i++) {
        int op, num;
        cin >> op;

        if (op == 1) {
            cin >> num;
            st.push(num);
        } else if (op == 2 && !st.empty()) {
            st.pop();
        } else if (op == 3) {
            output += st.empty() ? "EMPTY\n" : to_string(st.top()) + '\n';
        } else if (op == 4) {
            output += to_string(st.size()) + '\n';
        }
    }

    cout << output;

    return 0;
}
