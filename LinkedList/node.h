/*
* Class : Node 
* ----------------------------------------
* Defines a single node in the Linked List
*/

#ifndef NODE_H
#define NODE_H

template <typename ElemType>
class Node { 
	public : 
		Node(ElemType data, Node * nextNode = NULL);
		// Default constructor
		Node();
		/*
		* Function : getNodeData()
		* ---------------------------------
		* Returns the data of ElemeType that 
		* is contained in the node 
		*/
		ElemType getNodeData();
		/*
		* Function : setData(Data for the node to store)
		* -----------------------------------------------
		* Sets the data for the current Node 
		* to what is supplied in the argument
		*/
		void setData(ElemType data);
		/*
		* Function : getNext()
		* ------------------------------------
		* Returns the pointer to the next node
		* that the current node is connected to 
		*/
		Node * getNext();
	private : 
		Node * next;
		ElemType nodeData;
};

#endif

// Public routine implementations

/*
* Constructor for the Node class
*/
template <typename ElemType>
Node<ElemType>::Node(ElemType data, Node * nextNode) {
	nodeData = data;
	next = nextNode;
}

template <typename ElemType>
Node<ElemType>::Node() {
	nodeData = NULL;
	next = NULL;
}

template <typename ElemType>
ElemType Node<ElemType>::getNodeData() {
	return nodeData;
}

template <typename ElemType>
void Node<ElemType>::setData(ElemType data) {
	nodeData = 	data;
}

template <typename ElemType>
Node<ElemType>* Node<ElemType>::getNext() {
	return next;
}
