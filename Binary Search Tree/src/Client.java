/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.add(140);
        tree.add(40);
        tree.add(60);
        tree.add(54);

        int numNodeInTree = tree.traverse(tree.getRootNode(), 0, null);
        System.out.println(numNodeInTree);

    }
}
