import java.util.ArrayList;

/*
 * Created by Nash on 19/05/15.
 *
 * File : BST.java/(Binary Search Tree)
 * -------------------------------------
 */
public class BST<Integer> {
    private Node<Integer> root;
    private int numNodes;

    /*
    * Default constructor
    */
    public BST() {
        root = null;
        numNodes = 0;
    }

    public void addNode(Node<Integer> newNode) {
        if(numNodes == 0)
            root = newNode;
        else
           insertNode(root, newNode);
    }


    public void insertNode(Node<Integer> currentParent, Node<Integer> newNode) {
        if (newNode.getNodeData() < currentParent.getNodeData()) {
            if(currentParent.getLeftChild() == null) {
                currentParent.setLeftChild(newNode);
                return;
            } else {
                insertNode(currentParent.getLeftChild(), newNode);
            }
        } else {
            if(currentParent.getRightChild() == null) {
                currentParent.setRightChild(newNode);
                return;
            } else {
                insertNode(currentParent.getRightChild(), newNode);
            }
        }
    }

}
