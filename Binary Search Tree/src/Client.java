/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.addNode(new Node<Integer>(100));
        tree.addNode(new Node<Integer>(50));
        tree.addNode(new Node<Integer>(150));
        tree.addNode(new Node<Integer>(25));
        tree.addNode(new Node<Integer>(75));
        tree.addNode(new Node<Integer>(125));
        tree.addNode(new Node<Integer>(175));
        tree.addNode(new Node<Integer>(110));


        tree.preorderTraversal();
    }
}
