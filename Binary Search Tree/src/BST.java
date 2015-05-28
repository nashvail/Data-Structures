import java.util.Comparator;
import java.util.Stack;
import java.util.Arrays;

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

    public Node<Integer> getRootNode() {
        return root;
    }

    ///////////////////// PUBLIC METHODS


    /*
    * Function : addNode(Node to be added to the tree)
    * --------------------------------------------------
    * Takes in a Node<Integer> as argument, adds that node
    * to the tree.
    */
    public void addNode(Node<Integer> newNode) {
        if(root == null) {
            root = newNode;
        } else {
            insertNode(root, newNode);
        }
    }


    /*
    * Function : add(Value that is to be added)
    * ----------------------------------------------
    * Creates a new node implicitly with value equal
    * to what is passed as the argument.
    * Adds the newly created node to the tree.
     */
    public void add(int value) {
        addNode(new Node<Integer>(value));
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
    * Function : convertToHeap()
    * ---------------------------------------------------
    * Converts the Binary Search Tree into Min Heap tree.
    * Only rearranges the current tree to resemble a Heap
    * tree.
    * Goes through pouring data in and out of array in doing
    * so.
    * Tree can be reordered into Heap without going through
    * an array in the middle, we will create a function to do
    * that later.
    */
    public void convertToHeap() {
        // Count the number of nodes in the tree
        // to create a static array of that size
        int numNodes = traverse(root, 0, null);
        Node[] nodeArray = new Node[numNodes];
        // Put all the nodes into the array created above
        traverse(root, 0, nodeArray);

        // Sort the array based on the value of node
        // since we're creating Min Heap the array will be sorted in ascending order
        Arrays.sort(nodeArray, new Comparator<Node>() {
            @Override
            public int compare(Node m, Node n) {
                int mValue = m.getValue();
                int nValue = n.getValue();
                return (mValue < nValue ? -1 : (mValue == nValue) ? 0 : 1);
            }
        });

        // Reassigning positions in the tree so as to create a Min Heap
        for(int i = 0 ;i < numNodes ; i++) {
            int leftChildIndex = 2 * i;
            int rightChildIndex = leftChildIndex + 1;
            nodeArray[i].setLeftChild(leftChildIndex >= numNodes ? null : nodeArray[leftChildIndex]);
            nodeArray[i].setRightChild(rightChildIndex >= numNodes ? null : nodeArray[rightChildIndex]);
        }
    }

    private int traverse(Node node, int count, Node[] arr) {
        if(node == null)
            return count;
        if(arr != null)
            arr[count] = node;
        count++;
        count = traverse(node.getLeftChild(), count, arr);
        // Note that though the value of count is reassigned it is also passed as the
        // argument for traverse in the line below, so no data is lost
        count = traverse(node.getRightChild(), count, arr);
        return count;
    }


    /*
    * Function : getSuccessor(value of the node whose successor is to be found)
    * -------------------------------------------------------------------------------------------
    * Successor of a node is a node whose value is consecutively greater than the concerned node
    * and is present in the tree.
    * This function returns such Node<Integer> if found null otherwise.
     */
    public Node<Integer> getSuccessor(int nodeValue) {
        // Find the node with the given value
        // check if the found node has a right child, if it has then that is where we will find the successor
        // if not then we will have to do something else

        return null;
    }

    //////////////////////// PRIVATE METHODS

    private void recPreorderTraversal(Node<Integer> currentNode) {
        if(currentNode == null) return;

        System.out.println(currentNode.getValue());
        recPreorderTraversal(currentNode.getLeftChild());
        recPreorderTraversal(currentNode.getRightChild());
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
    private void insertNode(Node<Integer> currentParent, Node<Integer> newNode) {
        if (newNode.getValue() < currentParent.getValue()) {
            if(currentParent.getLeftChild() == null) {
                currentParent.setLeftChild(newNode);
                newNode.setParent(currentParent);
            } else {
                insertNode(currentParent.getLeftChild(), newNode);
            }

        } else if(newNode.getValue() > currentParent.getValue()){
            if(currentParent.getRightChild() == null) {
                currentParent.setRightChild(newNode);
                newNode.setParent(currentParent);
            } else {
                insertNode(currentParent.getRightChild(), newNode);
            }
        } else {
            // Avoid duplicate entries : ignore the input
        }
    }

}
