#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int max = -10010, min = 10010;

    for (int i = 0; i < N; i++) {
        int temp;
        cin >> temp;
        
        if (temp > max) 
            max = temp;
    
        if (temp < min)
            min = temp;
    }

    cout << min << endl << max;

    return 0;
}