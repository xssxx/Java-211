import java.util.LinkedList;
import java.util.Queue;
import java.util.Vector;

public class Graph {
    private int size;
    private Vector<Vector<Integer>> adj;
    private Vector<Boolean> visited;
    private Vector<Integer> layer;

    public Graph(int size) {
        this.size = size;
        this.adj = new Vector<>(size);
        this.visited = new Vector<>(size);
        this.layer = new Vector<>(size);

        // adj : initialize vector inside adj vector
        // visited : initialize all element to false
        // layer : initialize all element to -1
        for (int i = 0; i < size; i++) {
            adj.add(new Vector<>());
            visited.add(false);
            layer.add(-1);
        }
    }

    public void addEdge(int u, int v) {
        adj.get(u).add(v);
        adj.get(v).add(u);
    }

    public void dfs(int start) {
        visited.set(start, true);

        System.out.print(start + " ");
        for (int item : adj.get(start)) {
            if (!visited.get(item)) {
                dfs(item);
            }
        }
    }

    public void bfs(int start) {
        layer.set(start, 0);
        for (int i = 0; i < this.size; i++) {
            layer.add(-1);
        }

        Queue<Integer> Q = new LinkedList<>();
        Q.offer(start);

        while (!Q.isEmpty()) {
            int u = Q.poll();
            visited.set(u, true);
            System.out.print(u + " ");

            for (int item: adj.get(u)) {
                if (layer.get(item) == -1) {
                    layer.set(item, layer.get(u) + 1);
                    Q.offer(item);
                }
            }
        }
    }
}
