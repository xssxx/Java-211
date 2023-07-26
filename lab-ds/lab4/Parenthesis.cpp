#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string parenthesis;
    cin >> parenthesis;
    stack<char> st;

    for (size_t i = 0; i < parenthesis.size(); i++) {
        if (parenthesis[i] == '(')
            st.push('(');
        else if (parenthesis[i] == ')') {
            if (!st.empty())
                st.pop();
            else {
                cout << "NO";
                return 0;
            }
        }
    }

    if (st.empty()) {
        cout << "YES";
    } else {
        cout << "NO";
    }

    return 0;
}
