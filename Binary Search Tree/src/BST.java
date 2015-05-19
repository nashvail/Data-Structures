import java.util.ArrayList;

/*
 * Created by Nash on 19/05/15.
 *
 * File : BST.java/(Binary Search Tree)
 * -------------------------------------
 */
public class BST<T>{
    ArrayList<T> allNodes;

    /*
    * Default constructor
    */
    public BST() {
        allNodes = new ArrayList<T>();
    }

    public void addNode() {

    }


    ///// Private method declarations

    /*
    * Function : toSimpleIndex(int actualIndex)
    * -----------------------------------------------
    * To represent a simple binary search tree we are
    * using a flat ArrayList to properly deal with the
    * storage overhead of storing pointers to children.
    *
    * In a Binary Search Tree the numbering of Nodes
    * starts with 1 rather than 0 as in an ArrayList,
    * This method adds 1 to actualIndex that is passed
    * in as the parameter, that is all it does.
    *
    * If 0(actualIndex) is passed it returns (0 + 1) i.e. 1(simpleIndex)
    * If 1 is passed it returns (1 + 1) i.e. 2
    */

    private int toSimpleIndex(int actualIndex) {
        return actualIndex + 1;
    }

    private int getParentIndex(int childNodeIndex) {
        return  childNodeIndex/2;
    }




}
