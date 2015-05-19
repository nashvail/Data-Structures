/*
 * Created by Nash on 19/05/15.
 *
 * File : Node.java
 * --------------------------------------
 * Represents a single node in the Binary
 * Search Tree.
 */
public class Node<T> {
    T nodeData;

    /*
    * Default constructor
    */
    public Node() {}

    /*
    * Convenience constructor
    */
    public Node(T data) {
        nodeData = data;
    }

}
