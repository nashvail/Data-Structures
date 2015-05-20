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
    * Function : getTreeHeight()
    * ---------------------------------------------------
    * Wrapper function. Returns the height of tree by
    * calling the recursive method calculateTreeHeight().
    */
    public int getTreeHeight() {
        return calculateTreeHeight(root);
    }

    /*
    * Function : calculateTreeHeight(Node<Integer>)
    * ----------------------------------------------------
    * Recursive method to calculate the Tree's height. Height
    * of a tree is defined as the maximum distance between the
    * root node and any one of the leaf nodes.
    * Recursively : Height of the tree is equal to, 1 + height
    * of the tallest subtree.
     */
    private int calculateTreeHeight(Node<Integer> currentNode) {
        if(currentNode == null) return 0;
        return (1 + Math.max(calculateTreeHeight(currentNode.getLeftChild()),
                        calculateTreeHeight(currentNode.getRightChild()))
               );
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
