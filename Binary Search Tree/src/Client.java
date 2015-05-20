/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.addNode(new Node<Integer>(4));
        tree.addNode(new Node<Integer>(3));
        tree.addNode(new Node<Integer>(2));

        System.out.println(tree.getTreeHeight());

    }
}
