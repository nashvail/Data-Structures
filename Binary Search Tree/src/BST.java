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
        if(numNodes == 0) {
            root = newNode;
            numNodes++;
        } else {
            insertNode(root, newNode);
            numNodes++;
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
            if(currentParent.getLeftChild() == null)
                currentParent.setLeftChild(newNode);
            else
                insertNode(currentParent.getLeftChild(), newNode);

        } else if(newNode.getNodeData() > currentParent.getNodeData()){
            if(currentParent.getRightChild() == null)
                currentParent.setRightChild(newNode);
            else
                insertNode(currentParent.getRightChild(), newNode);
        } else {
            // Avoid duplicate entries : ignore the input here
        }
    }

}
