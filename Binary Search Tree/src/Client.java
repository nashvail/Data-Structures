/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.insert(5);
        tree.insert(8);
        tree.insert(3);
        tree.insert(1);
        tree.insert(14);
        tree.insert(16);

        tree.delete(8);
        int value = tree.getRootNode().getRightChild().getValue(); // 14
        System.out.println(value);
    }
}
