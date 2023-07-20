#include <iostream>
#include <climits>

using namespace std;

void kadane(int* array, int& maxSum, int size) {
    int currentSum = array[0] >= 0 ? array[0] : 0;
    maxSum = currentSum;

    for (int i = 1; i < size; i++) {
        if (currentSum <= 0) {
            currentSum = array[i];
        } else {
            currentSum += array[i];
        }

        if (currentSum > maxSum) 
            maxSum = currentSum;
    }
}

int findMaxSum(int** matrix, int size) {
    int maxSum = INT_MIN;

    for (int left = 0; left < size; left++) {
        int* temp = new int[size]();

        for (int right = left; right < size; right++) {
            for (int i = 0; i < size; i++) {
                temp[i] += matrix[i][right];
            }

            int currentSum;
            kadane(temp, currentSum, size);

            if (currentSum > maxSum) {
                maxSum = currentSum;
            }
        }

        delete[] temp; 
    }

    return maxSum;
}

int main() {
    int N;
    cin >> N;
    int** matrix = new int*[N];

    for (int i = 0; i < N; i++) {
        matrix[i] = new int[N];
        for (int j = 0; j < N; j++) {
            cin >> matrix[i][j];
        }
    }

    int result = findMaxSum(matrix, N);

    cout << result;

    for (int i = 0; i < N; i++)
        delete[] matrix[i];

    delete[] matrix;

    return 0;
}
