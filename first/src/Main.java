public class Main {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack(5);
        s.push(1);
        s.push(2);
        s.push(3);
        s.push(4);
        s.push(5);
        s.display();
        s.pop();
        s.display();
    }
}

