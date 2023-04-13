public class Stack<T> {
    // fields / attributes 
    private int top;
    private final int size;
    private final T[] stack;

    // constructor
    public Stack(int size) {
        this.size = size;
        this.stack = (T[]) new Object[size];
        this.top = -1;
    }

    // methods
    public void push(T item) {
        if (isFull()) {
            System.out.println("Stack is full, You can't add more");
            return;
        }
        top++;
        stack[top] = item;
    }

    public T pop() {
        if (isEmpty()) {
            System.out.println("Stack is empty, You can't pop");
            return null;
        }
        T item = stack[top];
        stack[top] = null;
        top--;
        return item;
    }

    public T peek() {
        if (isEmpty()) {
            System.out.println("Stack is empty, You can't peek");
            return null;
        }
        return stack[top];
    }

    public boolean isEmpty() {
        return top == -1;
    }

    public boolean isFull() {
        return top == size - 1;
    }

    public void display() {
        for (T element : stack) {
            System.out.print(element + " ");
        }
        System.out.print("| ");
    }
}
