/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.insert(7);
        tree.insert(8);
        tree.insert(12);
        tree.insert(13);
        tree.insert(9);
        tree.insert(3);
        tree.insert(2);
        tree.insert(6);
        tree.insert(5);

        tree.delete(3);
        System.out.println(tree.getRootNode().getLeftChild().getRightChild().getValue());
    }
}
