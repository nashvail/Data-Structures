/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.addNode(new Node<Integer>(4));
        tree.addNode(new Node<Integer>(3));
        tree.addNode(new Node<Integer>(5));
        System.out.println("Root " + tree.getRootNode().getNodeData());
        System.out.println("Left Child " + tree.getRootNode().getLeftChild().getNodeData());
        System.out.println("Right Child " + tree.getRootNode().getRightChild().getNodeData());
    }
}
