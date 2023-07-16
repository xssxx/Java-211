#include <iostream>
#include <algorithm>

#define MAX_SIZE 100000

int main() {
    int arr[MAX_SIZE];
    int i = 0;
    int temp;

    while (true) {
        std::cin >> temp;
        if (temp == -1) break;
        arr[i] = temp;
        i++;
    }
    
    std::sort(arr, arr + i);

    for (int j = 0; j < i; j++) {
        std::cout << arr[j] << '\n';
    }
    
    return 0;
}