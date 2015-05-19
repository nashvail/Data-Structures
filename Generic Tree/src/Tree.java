import java.util.ArrayList;

/*
* Class : Tree<T>
* ------------------------------
* Class representing a tree
*/
public class Tree<T> {
    // There will be a root element for the tree
    private Node<T> rootNode;
    // Stores references to all the nodes that are present in the tree for easy access
    private ArrayList<Node<T>> nodes;
    // Number of nodes in the tree
    private int numNodes;

    /*
    * Default constructor
    */
    public Tree() {
        numNodes = 0;
    }

    /*
    * Function : getRootNode();
    * --------------------------------------------
    * Returns the Node<T> that represents the root
    * of the current tree.
     */
    public Node<T> getRootNode() {
        return this.rootNode;
    }

    /*
    * Function : setRootNode(Node<T>)
    * -------------------------------------------
    * Sets the root node of the current tree
    * to the one that is supplied in the argument
    */
    public void setRootNode(Node<T> rootNode) {
        this.rootNode = rootNode;
    }


    /*
    * Function : getNumNodes()
    * ---------------------------------------------
    * Returns the total number of nodes present in
    * the tree.
    */
    public int getNumNodes() {
        return numNodes;
    }
}
