/*
* Class : Tree<T>
* ------------------------------
* Class representing a tree
*/
public class Tree<T> {
    // There will be a root element for the tree
    public Node<T> rootNode;

    /*
    * Default constructor
    */
    public Tree() {
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
}
