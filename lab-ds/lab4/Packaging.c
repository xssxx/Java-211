#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10010

typedef struct stack {
    int top;
    int* data;
} Stack;   

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int data) {
    stack->top++;
    stack->data[stack->top] = data;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        exit(1);
    }

    int data = stack->data[stack->top];
    stack->top--;
    return data;
}

int peek(Stack* stack) {
    if (isEmpty(stack)) {
        exit(1);
    }

    return stack->data[stack->top];
}

int calculatePackingCost(int a, int b, int c, char items[MAX_SIZE]) {
    Stack* stack = (Stack *)malloc(sizeof(stack));
    stack->top = -1;
    stack->data = (int *)calloc(MAX_SIZE, sizeof(int));
    
    // calculate inside bracket
    for (size_t i = 0; items[i] != '\0'; i++) {
        char ch = items[i];

        if (ch == '[' || ch == '(' || ch == '{') {
            push(stack, -1);
        } else if (ch == ']' || ch == ')' || ch == '}') {
            int groupCost = 0;
            while (peek(stack) != -1) {
                groupCost += pop(stack);
            }
            pop(stack);

            char openingBracket = (ch == ']') ? '[' : (ch == ')') ? '(' : '{';
            if (openingBracket == '[')
                groupCost = groupCost + (groupCost * 0.1);
            else if (openingBracket == '(')
                groupCost = groupCost + (groupCost * 0.07);
            else if (openingBracket == '{')
                groupCost = groupCost + (groupCost * 0.05);

            push(stack, groupCost);
        } else {
            if (ch == 'A') push(stack, a);
            else if (ch == 'B') push(stack, b);
            else if (ch == 'C') push(stack, c);
        }
    }

    // calculate outside bracket
    int totalCost = 0;
    while (!isEmpty(stack)) {
        totalCost += pop(stack);
    }
    free(stack->data);
    free(stack);

    return totalCost;
}

int main() {
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);

    char items[MAX_SIZE];
    scanf("%s", items);

    int totalCost = calculatePackingCost(a, b, c, items);
    printf("%d", totalCost);

    return 0;
}