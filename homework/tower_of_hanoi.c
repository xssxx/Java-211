#include <stdio.h>

#define MAX_SIZE 10

int towers[3][MAX_SIZE];
int top[3] = {-1, -1, -1};
int moveCount = 1;

void push(int towerIdx, int value) {
    if (top[towerIdx] >= MAX_SIZE - 1) return;
    towers[towerIdx][++top[towerIdx]] = value;
}

int pop(int towerIdx) {
    if (top[towerIdx] < 0) return -1;
    return towers[towerIdx][top[towerIdx]--];
}

void printTowers() {
    char towerNames[] = {'A', 'B', 'C'};
    for (int i = 0; i < 3; i++) {
        printf("tower %c:", towerNames[i]);
        for (int j = 0; j <= top[i]; j++) 
            printf(" %d", towers[i][j] - 1);
        printf("\n");
    }
}

void move(char source, char destination, int sourceIdx, int destIdx) {
    int disk = pop(sourceIdx);
    push(destIdx, disk);
    printf("Move #%d: move(1,%c,%c)\n", moveCount++, source, destination);
    printTowers();
}

void towerOfHanoi(int n, char source, char auxiliary, char destination, int sourceIdx, int auxIdx, int destIdx) {
    if (n == 1) {
        move(source, destination, sourceIdx, destIdx);
        return;
    }
    
    towerOfHanoi(n - 1, source, destination, auxiliary, sourceIdx, destIdx, auxIdx);
    move(source, destination, sourceIdx, destIdx);
    towerOfHanoi(n - 1, auxiliary, source, destination, auxIdx, sourceIdx, destIdx);
}

int main() {
    int n = 3;

    for (int i = n; i > 0; i--) {
        push(0, i);
    }

    printf("Start\n");
    printTowers();

    towerOfHanoi(n, 'A', 'B', 'C', 0, 1, 2);

    return 0;
}
