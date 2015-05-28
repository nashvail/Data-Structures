/*
 * Created by Nash on 19/05/15.
 *
 * File : Node.java
 * --------------------------------------
 * Represents a single node in the Binary
 * Search Tree.
 */
public class Node<Integer> {

    int value;
    Node<Integer> parent;
    Node<Integer> leftChild;
    Node<Integer> rightChild;

    /*
    * Default constructor
    */
    public Node() {
        leftChild = null;
        rightChild = null;
    }


    /*
    * Convenience constructor
    */
    public Node(int data) {
        value = data;
        parent = null;
        leftChild = null;
        rightChild = null;
    }

    /*
    * Function : getValue()
    * -------------------------------------
    * Returns the data that the node holds.
    */
    public int getValue() {
        return value;
    }

    /*
    * Function : setValue()
    * -------------------------------------
    */
    public void setValue(int data) {
        value = data;
    }

    /*
    * Function : setLeftChild(Node)
    */
    public void setLeftChild(Node<Integer> childNode) {
        leftChild = childNode;
    }

    /*
    * Function : setRightChild()
    */
    public void setRightChild(Node<Integer> childNode) {
        rightChild = childNode;
    }

    /*
     * Function : getLeftChild()
     * ------------------------------------
     * Returns the left child node of the
     * current node if it exists, returns
     * null otherwise.
     */
    public Node<Integer> getLeftChild() {
        return leftChild;
    }

    /*
    * Function : getRightChild()
    * ------------------------------------
    */
    public Node<Integer> getRightChild() {
        return rightChild;
    }

    /*
    * Function : getParent();
    * ------------------------------------
    */
    public Node<Integer> getParent() {
        return parent;
    }

    /*
    * Function : setParent(Node<Integer> parent node);
    * -----------------------------------------------
    */
    public void setParent(Node<Integer> parentNode){
        parent = parentNode;
    }

}
