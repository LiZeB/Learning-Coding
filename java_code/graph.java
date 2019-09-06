import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class graph {
    private HashMap<Integer, graph_node> nodes;//用字典存储节点，保证
    private HashSet<edge> edges;

    public graph(){
        nodes = new HashMap<>();
        edges = new HashSet<>();
    }
}

//边类
class edge{
    private int weight;
    private graph_node start;
    private graph_node end;

    public edge(int weights, graph_node start, graph_node end){
        this.weight = weights;
        this.start = start;
        this.end = end;
    }
}

//节点类
class graph_node{
    private int value;
    private ArrayList<graph_node> nexts;
    private ArrayList<edge> edges;

    public graph_node(int value){
        this.value = value;
        this.nexts = new ArrayList<>();
        this.edges = new ArrayList<>();
    }
}