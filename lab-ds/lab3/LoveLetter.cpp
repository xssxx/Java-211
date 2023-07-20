#include <iostream>
using namespace std;

int main() {
    string letter, ans;

    getline(cin, letter);

    int i = 0;
    char curr;

    while (i < letter.size()) {
        curr = letter[i];
        ans += curr;
        if (curr == 'a' || curr == 'e' || curr == 'i' || curr == 'o' || curr == 'u') {
            i += 3;
        } else {
            i++;
        }
    }
    
    cout << ans;

    return 0; 
}