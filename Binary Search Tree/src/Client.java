/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.add(8);
        tree.add(9);
        tree.add(10);
        tree.add(6);
        tree.add(4);
        tree.add(5);
        tree.add(1);
        tree.add(14);

        System.out.println(tree.getPredecessor(6).getValue());
        // output : 5
    }
}
