#include <iostream>
#include <algorithm>

using namespace std;

int binary_search(int arr[], int target, int size, int& count) {
    int left = 0, right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        count++;

        if (arr[mid] == target) return mid;

        if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

int main() {
    int arr[] = {1, 15, 5, 7, 10, 9, 10, 3, 45, 155, 56, 18, 88, 23, 99, 111, 100};
    int n = sizeof(arr) / sizeof(int);

    sort(arr, arr + n);

    cout << "sorted array" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;

    int count1 = 0, count2 = 0;

    int res1 = binary_search(arr, 5, n, count1);
    int res2 = binary_search(arr, 90, n, count2);

    cout << "binary search result" << endl;

    if (res1 != -1)
        cout << "result 1: Found at index " << res1 << ", Search steps = " << count1 << endl;
    else
        cout << "result 2: Not found, binary search steps = " << count1 << endl;

    if (res2 != -1)
        cout << "result 2: Found at index " << res2 << ", Search steps = " << count2 << endl;
    else
        cout << "result 2: Not found, Search steps = " << count2 << endl;

    return 0;
}