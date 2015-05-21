/*
* Author : Nash Vail
*/
public class Client {
    public static void main(String[] args) {
        BST<Integer> tree = new BST<Integer>();
        tree.addNode(new Node<Integer>(20));
        tree.addNode(new Node<Integer>(8));
        tree.addNode(new Node<Integer>(22));
        tree.addNode(new Node<Integer>(4));
        tree.addNode(new Node<Integer>(12));
        tree.addNode(new Node<Integer>(10));
        tree.addNode(new Node<Integer>(14));

        Node<Integer> commonAncestor = tree.getLowestCommonAncestor(tree.getNode(4), tree.getNode(14));
        System.out.println(commonAncestor.getValue());
    }
}
