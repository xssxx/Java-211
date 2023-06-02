// <T> คือ generic types ใส่ type เอง
public class Queue<T> {
    // fields
    private int front;
    private int rear;
    private int size;
    private T[] queue;

    // constructor
    public Queue(int size) {
        this.size = size;
        this.queue = (T[]) new Object[size];
        this.front = 0;
        this.rear = 0;
    }

    // methods

    public void enqueue(T item) {
        if (isFull()) {
            System.out.println("Queue is full");
            return;
        }
        queue[rear] = item;
        rear++;
    }

    public T dequeue() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return null;
        }
        T item = queue[front];
        for (int i = 0; i < queue.length - 1; i++) {
            queue[i] = queue[i + 1];
        }
        rear--;
        queue[rear] = null;
        return item;
    }

    public T front() {
        if (isEmpty()) {
            System.out.println("Queue is empty");
            return null;
        }
        return queue[front];
    }

    public boolean isFull() {
        return rear == size;
    }

    public boolean isEmpty() {
        return front == -1;
    }

    public void display() {
        for (T element : queue) {
            System.out.print(element + " ");
        }
        System.out.println("");
    }
}
