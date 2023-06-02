public class Main {
    public static void main(String[] args) {
        // integer queue
        Queue<Integer> q = new Queue<>(5);
        q.enqueue(10);
        q.enqueue(20);
        q.enqueue(30);
        q.enqueue(40);
        q.enqueue(50);
        q.display();

        q.dequeue();
        q.display();

        System.out.println("front is: " + q.front());

        System.out.println("----------------");

        // character queue
        Queue<Character> q2 = new Queue<>(5);
        q2.enqueue('a');
        q2.enqueue('b');
        q2.enqueue('c');
        q2.enqueue('d');
        q2.enqueue('e');
        q2.display();

        q2.dequeue();
        q2.display();

        q2.dequeue();
        q2.display();
    }
}

