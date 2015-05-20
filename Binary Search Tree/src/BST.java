import java.util.ArrayList;

/*
 * Created by Nash on 19/05/15.
 *
 * File : BST.java/(Binary Search Tree)
 * -------------------------------------
 */
public class BST<Integer> {
    private Node<Integer> root;

    /*
    * Default constructor
    */
    public BST() {
        root = null;
    }

    public void addNode(Node<Integer> newNode) {
        if(root == null) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    }

    public Node<Integer> getRootNode() {
        return root;
    }


    /*
    * Function : insertNode(Parent under consideration, Node to be inserted)
    * ----------------------------------------------------------------------
    * Recursively inserts a new node at its proper place in the tree.
    */
    public void insertNode(Node<Integer> currentParent, Node<Integer> newNode) {
        if (newNode.getNodeData() < currentParent.getNodeData()) {
            if(currentParent.getLeftChild() == null) {
                currentParent.setLeftChild(newNode);
            } else {
                insertNode(currentParent.getLeftChild(), newNode);
            }

        } else if(newNode.getNodeData() > currentParent.getNodeData()){
            if(currentParent.getRightChild() == null) {
                currentParent.setRightChild(newNode);
            } else {
                insertNode(currentParent.getRightChild(), newNode);
            }
        } else {
            // Avoid duplicate entries : ignore the input
        }
    }

}
