#include <iostream>
#include <stack>

using namespace std;

int calculatePackingCost(int a, int b, int c, const string& items) {
    stack<int> costStack;

    // calculate inside bracket
    for (char ch : items) {
        if (ch == '[' || ch == '(' || ch == '{') {
            costStack.push(-1); 
        } else if (ch == ']' || ch == ')' || ch == '}') {
            int groupCost = 0;
            while (costStack.top() != -1) {
                groupCost += costStack.top();
                costStack.pop();
            }
            costStack.pop(); 

            char openingBracket = (ch == ']') ? '[' : (ch == ')') ? '(' : '{';
            if (openingBracket == '[')
                groupCost = groupCost + (groupCost * 0.1);
            else if (openingBracket == '(')
                groupCost = groupCost + (groupCost * 0.07);
            else if (openingBracket == '{')
                groupCost = groupCost + (groupCost * 0.05);

            costStack.push(groupCost); 
        } else {
            if (ch == 'A') costStack.push(a);
            else if (ch == 'B') costStack.push(b);
            else if (ch == 'C') costStack.push(c);
        }
    }

    // calculate outside bracket
    int totalCost = 0;
    while (!costStack.empty()) {
        totalCost += costStack.top();
        costStack.pop();
    }

    return totalCost;
}

int main() {
    int a, b, c;
    string items;
    cin >> a >> b >> c >> items;

    int totalCost = calculatePackingCost(a, b, c, items);
    cout << totalCost;

    return 0;
}
