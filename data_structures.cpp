#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// -------------------- NODE --------------------
class Node {
	public:
		// Constructors
		Node(); // Empty constructor
		Node(auto);
		Node(auto, Node*);
		Node(Node*); // Copy constructor
		// Functions
		int setValue(auto);
		int setNext(auto);
		int setPrevious(auto);
		auto getValue();
		Node* getNext();
		Node* getPrevious();
	private:
		void *value;
		Node* next;
		Node* previous;
};
typedef Node* nodePtr;

// ---------- Node Counstructors ----------
Node::Node() {
	value = 0;
	next = NULL;
	previous = NULL;
};
Node::Node(auto Value) {
	value = Value;
	next = NULL;
	previous = NULL;
};
Node::Node(auto Value, Node* Next) {
	value = Value;
	next = Next;
	previous = NULL;
};
Node::Node(Node* node) {
	value = node->value;
	next = node->next;
	previous = NULL;
};

// ---------- Node Functions ----------
int Node::setValue(auto Value) {
	try {
		value = Value;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int Node::setNext(auto Value) {
	try {
		Node* temp = new Node(Value);
		next = temp;
		temp->previous = this;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int Node::setPrevious(auto Value) {
	try {
		Node* temp = new Node(Value);
		previous = temp;
		previous->next = this;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
auto Node::getValue() {
	return value;
};
Node* Node::getNext() {
	return next;
};
Node* Node::getPrevious() {
	return previous;
}

// -------------------- LINKED LIST --------------------
class LinkedList {
	public:
		// Constructors
		LinkedList(); // Empty constructor
		LinkedList(auto);
		// Functions
		int searchByValue(auto); // search by value, return index
		auto searchByIndex(int); // search by index, return value
		int insert(auto, int index);
		int append(auto); // Append new value
		int remove(auto); // Remove first value found
		int pop(); // Remove index 0
		int pop(int); // Remove by index
		int getLength();
	private:
		nodePtr head;
		int length;
};
typedef LinkedList* LLptr;

// ---------- Linked List Constructors ----------
LinkedList::LinkedList() {
	head = new Node();
	length = 1;
};
LinkedList::LinkedList(auto Value) {
	head = new Node(Value);
	length = 1;
};

// ---------- Functions ----------
int LinkedList::searchByValue(auto Value) {
	try {
		nodePtr temp = head;
		int index = 0;
		while (temp != NULL) {
			if (temp->getValue() == Value) {
				return index;
			}
			temp = temp->getNext();
			index++;
		}
		return -1;
	}
	catch (...) {
		return -1;
	}
};
auto LinkedList::searchByIndex(int Index) {
	try {
		if (Index > length) {
			return -1;
		}
		nodePtr temp = head;
		for (int i=0; i <= Index; i++) {
			if (i == Index) {
				return static_cast<int>(reinterpret_cast<intptr_t>(temp->getValue()));
			}
			temp = temp->getNext();
		}
		return -1; // Compiler message: "warning: control reaches end of non-void function [-Wreturn-type]"
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::insert(auto Value, int Index) {
	try {
		if (Index > length) {
			return -1;
		}
		nodePtr newNode = new Node(Value);
		nodePtr temp = head;
		if (length == 0) {
			head = newNode;
			return 1;
		}
		for (int i=0; i < Index; i++) {
			if (i == (Index-1)) {
				nodePtr next = temp->getNext();
				next->setPrevious(newNode);
				newNode->setPrevious(temp);
				newNode->setNext(next);
				temp->setNext(newNode);
				length++;
				return 1;
			}
			temp = temp->getNext();
		}
		return -1; // Compiler message: "warning: control reaches end of non-void function [-Wreturn-type]"
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::append(auto Value) {
	try {
		nodePtr temp = head;
		nodePtr newNode = new Node(Value);
		if (length == 0) {
			head = newNode;
			return 1;
		}
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
		temp->setNext(newNode);
		while (temp->getPrevious() != NULL) {
			temp = temp->getPrevious();
		}
		head = temp;
		length++;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::remove(auto Value) {
	try {
		int index = this->searchByValue(Value);
		return this->pop(index);
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::pop() {
	try {
		return this->pop(0);
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::pop(int Index) {
	try {
		nodePtr temp = head;
		for (int i=0; i <= Index; i++) {
			if (i == Index) {
				nodePtr previous = temp->getPrevious();
				nodePtr next = temp->getNext();
				previous->setNext(next);
				next->setPrevious(previous);
				length--;
				temp = previous;
				break;
			}
			temp = temp->getNext();
		}
		while (true) {
			if (temp->getPrevious() == NULL) {
				head = temp;
				break;
			}
			temp = temp->getPrevious();
		}
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::getLength() {
	return length;
}

// -------------------- STACK --------------------
class Stack {
	public:
		// Constructors
		Stack(); // Empty constructor
		Stack(auto);
		// Functions
		int Add(auto);
		int Pop();
		auto Current();
	private:
		LLptr linkedList;
};
typedef Stack* stackPtr;

// ---------- Stack Constructors ----------
Stack::Stack() {
	linkedList = new LinkedList();
};
Stack::Stack(auto Value) {
	linkedList = new LinkedList(Value);
};

// ---------- Stack Functions ----------
int Stack::Add(auto Value) {
	try {
		return linkedList->append(Value);
	}
	catch (...) {
		return -1;
	}
};
int Stack::Pop() {
	try {
		int length = linkedList->getLength();
		return linkedList->pop(length-1);
	}
	catch (...) {
		return -1;
	}
};
auto Stack::Current() {
	try {
		return linkedList->searchByIndex(0);
	}
	catch (...) {
		return -1;
	}
}

// -------------------- QUEUE --------------------
class Queue {
	public:
		// Constructors
		Queue(); // Empty constructor
		Queue(auto);
		Queue(nodePtr);
		Queue(Queue*); // Copy constructor
		// Functions
		int Add(auto);
		int Pop();
		auto FirstItem();
	private:
		LLptr linkedList;
};
typedef Queue* queuePtr;

// ---------- Queue Constructors ----------
Queue::Queue() {
	linkedList = new LinkedList();
};
Queue::Queue(auto Value) {
	linkedList = new LinkedList(Value);
};
Queue::Queue(nodePtr node) {
	linkedList = new LinkedList(node);
};
Queue::Queue(Queue* queue) {
	linkedList = queue ->linkedList;
};

// ---------- Queue Functions ----------
int Queue::Add(auto Value) {
	try {
		return linkedList->append(Value);
	}
	catch (...) {
		return -1;
	}
};
int Queue::Pop() {
	try {
		return linkedList->pop();
	}
	catch (...) {
		return -1;
	}
};
auto Queue::FirstItem() {
	try {
		int length = linkedList->getLength() - 1;
		return linkedList->searchByIndex(length);
	}
	catch (...) {
		return -1;
	}
}

// -------------------- GRAPH (BREADTH FIRST SEARCH) --------------------
class BreadthFirstGraph {
	public:
		// Constructors
		BreadthFirstGraph(); // Empty Constructor
		BreadthFirstGraph(BreadthFirstGraph*); // Copy Constructor
		BreadthFirstGraph(auto);
		BreadthFirstGraph(nodePtr);
		// Functions
		int AddToGraph(auto);
		template <class> auto CurrentValue();
		int RemoveLast();
	private:
		queuePtr queue;
		int length;
};
typedef BreadthFirstGraph* BFSGraph;

// ---------- Graph (Breadth First Search) Constructors ----------
BreadthFirstGraph::BreadthFirstGraph() {
	queue = new Queue();
	length = 1;
};

BreadthFirstGraph::BreadthFirstGraph(BFSGraph graph) {
	queue = graph->queue;
	length = graph->length;
};
BreadthFirstGraph::BreadthFirstGraph(auto root) {
	queue = new Queue(root);
	length = 1;
};
BreadthFirstGraph::BreadthFirstGraph(nodePtr rootNode) {
	queue = new Queue(rootNode);
	length = 1;
};

// ---------- Graph (Breadth First Search) Functions ----------
int BreadthFirstGraph::AddToGraph(auto newValue) {
	try {
		queue->Add(newValue);
		length++;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int BreadthFirstGraph::RemoveLast() {
	try {
		queue->Pop();
		length--;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
template <class> auto BreadthFirstGraph::CurrentValue() {
	try {
		return queue->FirstItem();
	}
	catch (...) {
		return -1;
	}
};

// -------------------- GRAPH (DEPTH FIRST SEARCH) --------------------
class DepthFirstGraph {
	public:
		// Constructors
		DepthFirstGraph();
		DepthFirstGraph(auto);
		// Functions
		int AddToGraph(auto);
		template <class> auto CurrentValue();
		int Remove();
	private:
		int length;
		stackPtr stack;
};
typedef DepthFirstGraph* DFSgraph;

// ---------- Graph (Depth First Search) Constructors ----------
DepthFirstGraph::DepthFirstGraph() {
	stack = new Stack();
	length = 1;
};
DepthFirstGraph::DepthFirstGraph(auto graph) {
	stack = new Stack(graph);
	length = 1;
};

// ---------- Graph (Depth First Search) Functions ----------
int DepthFirstGraph::AddToGraph(auto newValue) {
	try {
		stack->Add(newValue);
		length++;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int DepthFirstGraph::Remove() {
	try {
		stack->Pop();
		length--;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
template <class> auto DepthFirstGraph::CurrentValue() {
	try {
		return stack->Current();
	}
	catch (...) {
		return -1;
	}
};


int main() {
	return 1;
}
