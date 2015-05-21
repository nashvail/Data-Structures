import java.util.Stack;

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
    * Function : getLowestCommonAncestor(First Node, Second Node)
    * -----------------------------------------------------------------------------
    * Returns lowest common ancestor for any two supplied nodes that exist in the
    * Tree.
    * Lowest, in Lowest Common Ancestor doesn't mean "lowest" value. It describes
    * the position of the ancestor, the one that is lowest in the tree.
    * Is non-recursive, avoids call stack memory overhead
    */
    public Node<Integer> getLowestCommonAncestor(Node<Integer> n1, Node<Integer> n2) {
        if(n1 == null || n2 == null) return null;

        int firstNodeValue = n1.getValue();
        int secondNodeValue = n2.getValue();

        Node<Integer> currentNode = root;

        while(currentNode != null) {
            int currentNodeValue = currentNode.getValue();
            if(firstNodeValue < currentNodeValue && secondNodeValue < currentNodeValue) {
                currentNode = currentNode.getLeftChild();
            } else if(firstNodeValue > currentNodeValue && secondNodeValue > currentNodeValue) {
                currentNode = currentNode.getRightChild();
            } else {
                // if the value is somewhere in between
                return currentNode;
            }
        }

        return null;
    }

    /*
    * Function : getNode(Value of the node that is to be found)
    * ---------------------------------------------------------
    * Returns Node<Integer> which holds value equal to the one
    * that is supplied in the argument.
    * Returns null if no such node is found.
    * Is non-recursive, avoids call stack memory overhead
    */
    public Node<Integer> getNode(int searchValue) {
        Node<Integer> currentNode = root;
        while(currentNode != null) {
            int currentNodeValue = currentNode.getValue();
            if(currentNodeValue == searchValue)
                return currentNode;
            else if(searchValue < currentNodeValue)
                currentNode = currentNode.getLeftChild();
            else
                currentNode = currentNode.getRightChild();
        }

        // if no node with given value is found
        return null;
    }

    /*
    * Function : nonRecursivePreorderTraversal()
    * ------------------------------------------------------------
    * Non recursive pre order traversal using Stack class.
    */
    public void nonRecursivePreorderTraversal() {
        Stack<Node<Integer>> nodeStack = new Stack<Node<Integer>>();
        nodeStack.push(root);

        while(!nodeStack.empty()){
            Node<Integer> currentNode = nodeStack.pop();
            System.out.println(currentNode.getValue());

            Node<Integer> currentNodeRightChild = currentNode.getRightChild();
            Node<Integer> currentNodeLeftChild = currentNode.getLeftChild();

            if(currentNodeRightChild != null) nodeStack.push(currentNodeRightChild);
            if(currentNodeLeftChild != null) nodeStack.push(currentNodeLeftChild);
        }

    }

    /*
    * Function : preorderTraversal()
    * -------------------------------------------------------
    * Wrapper Function for recPreorderTraversal(Node<Integer>)
    * Performs and prints the tree following Pre Order route
    */
    public void preorderTraversal() {
        recPreorderTraversal(root);
    }

    private void recPreorderTraversal(Node<Integer> currentNode) {
        if(currentNode == null) return;

        System.out.println(currentNode.getValue());
        recPreorderTraversal(currentNode.getLeftChild());
        recPreorderTraversal(currentNode.getRightChild());
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
        if (newNode.getValue() < currentParent.getValue()) {
            if(currentParent.getLeftChild() == null) {
                currentParent.setLeftChild(newNode);
            } else {
                insertNode(currentParent.getLeftChild(), newNode);
            }

        } else if(newNode.getValue() > currentParent.getValue()){
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
