#include <iostream>
#include <cstring>
using namespace std;

int main() {
    int row, col;
    cin >> row >> col;

    int matrix[row][col];

    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            cin >> matrix[i][j];
        }
    }

    for (int i = 1; i < row; i++) {
        int temp[col];
        for (int j = 0; j < col; j++) {
            int prev = matrix[i-1][j]; // ค่าของ row ก่อนหน้า
            temp[j] = matrix[i][prev-1]; // [prev-1] เพราะ โจทย์นับจาก 1 แต่โปรแกรมนับจาก 0
        }
        // memcpy(matrix[i], temp, col * sizeof(int));
        memmove(matrix[i], temp, col * sizeof(int));
    }

    for (int i = 0; i < col; i++) {
        cout << matrix[row-1][i] << " ";
    }
}