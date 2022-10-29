#include <bits/stdc++.h>
#include <iostream>

using namespace std;

// -------------------- NODE --------------------
class Node {
	public:
		// Constructors
		Node(); // Empty constructor
		Node(int);
		Node(int, Node*);
		Node(Node*); // Copy constructor
		// Functions
		int setValue(int);
		int setNext(int);
		int setNext(Node*);
		int setPrevious(int);
		int setPrevious(Node*);
		int getValue();
		Node* getNext();
		Node* getPrevious();
	private:
		int value;
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
Node::Node(int Value) {
	value = Value;
	next = NULL;
	previous = NULL;
};
Node::Node(int Value, Node* Next) {
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
int Node::setValue(int Value) {
	try {
		value = Value;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int Node::setNext(int Value) {
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
int Node::setNext(Node* node) {
	try {
		Node* temp = new Node(node);
		next = temp;
		temp->previous = this;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int Node::setPrevious(int Value) {
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
int Node::setPrevious(Node* node) {
	try {
		Node* temp = new Node(node);
		previous = temp;
		previous->next = this;
		return 1;
	}
	catch (...) {
		return -1;
	}
};
int Node::getValue() {
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
		LinkedList(int);
		LinkedList(nodePtr);
		LinkedList(LinkedList*); // Copy constructor
		// Functions
		int searchByValue(int); // search by value, return index
		int searchByIndex(int); // search by index, return value
		int insert(int, int);
		int insert(nodePtr, int);
		int append(int); // Append new value
		int append(nodePtr); // Append new node
		int remove(int); // Remove first value found
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
LinkedList::LinkedList(int Value) {
	head = new Node(Value);
	length = 1;
};
LinkedList::LinkedList(nodePtr node) {
	head = new Node(node);
	length = 1;
};
LinkedList::LinkedList(LinkedList* ll) {
	head = ll->head;
	length = 1;
};

// ---------- Functions ----------
int LinkedList::searchByValue(int Value) {
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
int LinkedList::searchByIndex(int Index) {
	try {
		if (Index > length) {
			return -1;
		}
		nodePtr temp = head;
		for (int i=0; i <= Index; i++) {
			if (i == Index) {
				return temp->getValue();
			}
			temp = temp->getNext();
		}
		return -1; // Compiler message: "warning: control reaches end of non-void function [-Wreturn-type]"
	}
	catch (...) {
		return -1;
	}
};
int LinkedList::insert(int Value, int Index) {
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
int LinkedList::insert(nodePtr node, int Index) {
	try {
		if (Index > length) {
			return -1;
		}
		nodePtr temp = head;
		if (length == 0) {
			head = node;
			return 1;
		}
		for (int i=0; i < Index; i++) {
			if (i == (Index-1)) {
				nodePtr next = temp->getNext();
				next->setPrevious(node);
				node->setPrevious(temp);
				node->setNext(next);
				temp->setNext(node);
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
int LinkedList::append(int Value) {
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
int LinkedList::append(nodePtr node) {
	try {
		if (length == 0) {
			head = node;
			return 1;
		}
		nodePtr temp = head;
		while (temp->getNext() != NULL) {
			temp = temp->getNext();
		}
		temp->setNext(node);
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
int LinkedList::remove(int Value) {
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
		Stack(int);
		Stack(nodePtr);
		Stack(Stack*); // Copy constructor
		// Functions
		int Add(int);
		int Add(nodePtr);
		int Pop();
	private:
		LLptr linkedList;
};
typedef Stack* stackPtr;

// ---------- Stack Constructors ----------
Stack::Stack() {
	linkedList = new LinkedList();
};
Stack::Stack(int Value) {
	linkedList = new LinkedList(Value);
};
Stack::Stack(nodePtr node) {
	linkedList = new LinkedList(node);
};
Stack::Stack(Stack* stack) {
	linkedList = stack ->linkedList;
};

// ---------- Stack Functions ----------
int Stack::Add(int Value) {
	try {
		return linkedList->append(Value);
	}
	catch (...) {
		return -1;
	}
};
int Stack::Add(nodePtr node) {
	try {
		return linkedList->append(node);
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

// -------------------- QUEUE --------------------
class Queue {
	public:
		// Constructors
		Queue(); // Empty constructor
		Queue(int);
		Queue(nodePtr);
		Queue(Queue*); // Copy constructor
		// Functions
		int Add(int);
		int Add(nodePtr);
		int Pop();
	private:
		LLptr linkedList;
};
typedef Queue* queuePtr;

// ---------- Queue Constructors ----------
Queue::Queue() {
	linkedList = new LinkedList();
};
Queue::Queue(int Value) {
	linkedList = new LinkedList(Value);
};
Queue::Queue(nodePtr node) {
	linkedList = new LinkedList(node);
};
Queue::Queue(Queue* queue) {
	linkedList = queue ->linkedList;
};

// ---------- Queue Functions ----------
int Queue::Add(int Value) {
	try {
		return linkedList->append(Value);
	}
	catch (...) {
		return -1;
	}
};
int Queue::Add(nodePtr node) {
	try {
		return linkedList->append(node);
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

int main() {
	return 1;
}
