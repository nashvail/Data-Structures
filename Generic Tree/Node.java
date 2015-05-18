import java.util.ArrayList;
import java.util.List;

/*
* Class : Node
* ------------------------------------------------------------
* Represents a single Node of a tree, holds in data of type T.
*/
public class Node<T> {
    // Data for the node
    private T data;
    // A single node also has references to all its children
    public List<Node<T>> children;


    /*
    * Default constructor
    */
    public Node() {
        children = new ArrayList<Node<T>>();
    }

    /*
    * Convenience constructor
    */
    public Node(T data) {
        setData(data);
        children = new ArrayList<Node<T>>();
    }

    /*
    * Function : setData()
    * ------------------------
    */
    public void setData(T data) {
        this.data = data;
    }

    /*
    * Function : getData()
    * ------------------------
    */
    public T getData() {
        return this.data;
    }

    /*
    * Function : getChildren()
    * -------------------------------------------------------
    * Return the children of the current Node<T>. A Tree<T>
    * is represented by a single root Node<T> and its children
    * these children in turn can have children of their own.
    * The getChildren() method will return the children of Node<T>
    */
    public List<Node<T>> getChildren() {
        return this.children;
    }

    /*
    * Function : setChildren()
    * --------------------------------------------------------
    * Sets the children of the current node to the list of nodes
    * that is supplied as the argument.
     */
    public void setChildren(List<Node<T>> children) {
        this.children = children;
    }

    /*
    * Function : addChild()
    * ----------------------------------------------------------
    * Adds a new child to the collection(List<Node<T>>) of children
    * of the current node.
    */
    public void addChild(Node<T> newChild) {
        children.add(newChild);
    }

    /*
    * Function : numChildren()
    * -----------------------------------------------------------
    * Returns the number of children current node has.
     */
    public int numChildren() {
       return children.size();
    }
}
