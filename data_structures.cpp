#include <iostream>

// -------------------- NODE --------------------
template <typename T> class Node {
    public:
        // Constructors
        Node(); // Empty Constructor
        Node(T);
        Node(const Node<T>&); // Copy Constructor
        // Functions
        T getValue();
        Node<T>* getNext();
        Node<T>* getPrevious();
        void setValue(T);
        void setNext(Node<T>*);
        void setPrevious(Node<T>*);
    private:
        T Value;
        Node<T>* Next;
        Node<T>* Previous;
};
// ---------- NODE CONSTRUCTORS ----------
template <typename T> Node<T>::Node() {
};
template <typename T> Node<T>::Node(T value) {
    Value = value;
};
template <typename T> Node<T>::Node(const Node<T>& copy) {
    Value = copy->getValue();
    Next = copy->getNext();
    Previous = copy->getPrevious();
};
// ---------- NODE FUNCTIONS ----------
template <typename T> T Node<T>::getValue(void) {
    return Value;
};
template <typename T> Node<T>* Node<T>::getNext(void) {
    return Next;
};
template <typename T> Node<T>* Node<T>::getPrevious(void) {
    return Previous;
};
template <typename T> void Node<T>::setValue(T Value) {
    this->Value = Value;
};
template <typename T> void Node<T>::setNext(Node<T>* Next) {
    this->Next = Next;
};
template <typename T> void Node<T>::setPrevious(Node<T>* Previous) {
    this>Previous = Previous;
};

// -------------------- LINKED LIST --------------------
template <typename T> class LinkedList {
    public:
        // Constructors
        LinkedList(); // Empty Constructor
        LinkedList(const LinkedList<T>&); // Copy Constructor
        // Functions
        int searchByValue(T);
        T searchByIndex(int);
        void insert(int, T);
        void append(T);
        T pop(int);
        T pop();
        T remove(T);
        int getLength();
        T getHead();
    private:
        Node<T>* Head;
        int Length;
};
// ---------- LINKED LIST CONSTRUCTORS ----------
template <typename T> LinkedList<T>::LinkedList() {
    Head = new Node<T>();
    Length = 1;
};
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T>& copy) {
    Head = copy->getHead();
    Length = copy->getLength();
};
// ---------- LINKED LIST FUNCTIONS ----------
template <typename T> int LinkedList<T>::searchByValue(T Value) {
    Node<T>* temp = Head;
    int index = 0;
    while (temp != NULL) {
        if (temp.getValue()) {
            return index;
        }
        temp = temp->getNext();
        index++;
    }
    return -1;
};
template <typename T> T LinkedList<T>::searchByIndex(int Index) {
    if (Index > Length) {
        return ;
    }
    if (Index < 0) {
        return ;
    }
    Node<T>* temp = Head;
    for (int i=0; i <= Index; i++) {
        if (i == Index) {
            return temp->getValue();
        }
        temp = temp->getNext();
    }
    return ;
};
template <typename T> void LinkedList<T>::insert(int Index, T Data) {
    if (Index > Length) {
        return ;
    }
    if (Index < 0) {
        return ;
    }
    Node<T>* newNode = new Node<T>(Data);
    Node<T>* temp = Head;
    if (Length == 0) {
        Head = newNode;
        return ;
    }
    for (int i=0; i < Index; i++) {
        if (i == (Index-1)) {
            Node<T>* next = temp->getNext();
            next->setPrevious(newNode);
            newNode->setPrevious(temp);
            newNode->setNext(next);
            temp->setNext(newNode);
            Length++;
        }
        temp = temp->getNext();
    }
    while (temp->getPrevious() != NULL) {
        temp = temp->getPrevious();
    }
    Head = temp;
};
template <typename T> void LinkedList<T>::append(T Data) {
    this->insert(this->getLength(), Data);
};
template <typename T> T LinkedList<T>::pop(int Index) {
    if (Index > Length) {
        return ;
    }
    if (Index < 0) {
        return ;
    }
    Node<T>* temp = Head;
    for (int i=0; i <= Index; i++) {
        if (i == Index) {
            if (i == Index) {
				Node<T>* previous = temp->getPrevious();
				Node<T>* next = temp->getNext();
				previous->setNext(next);
				next->setPrevious(previous);
				Length--;
				return temp->getValue();
			}
			temp = temp->getNext();
        }
    }
    while (temp->getPrevious() != NULL) {
        temp = temp->getPrevious();
    }
    Head = temp;
    return ;
};
template <typename T> T LinkedList<T>::pop(void) {
    return this->pop(0);
};
template <typename T> T LinkedList<T>::remove(T Value) {
    int index = this->searchByValue(Value);
    return this->pop(index);
};
template <typename T> int LinkedList<T>::getLength(void) {
    return Length;
};
template <typename T> T LinkedList<T>::getHead(void) {
    return Head;
};

// -------------------- STACK --------------------
template <typename T> class Stack {
    public:
        // Constructors
        Stack(); // Empty Constructor
        Stack(const Stack<T>&); // Copy Constructor
        // Functions
        void add(T);
        T pop();
        T current();
        LinkedList<T>* getLinkedList();
    private:
        LinkedList<T>* LL;
};
// ---------- STACK CONSTRUCTORS ----------
template <typename T> Stack<T>::Stack() {
    LL = new LinkedList<T>();
};
template <typename T> Stack<T>::Stack(const Stack<T>& copy) {
    LL = copy->getLinkedList();
};
// ---------- STACK FUNCTIONS ----------
template <typename T> void Stack<T>::add(T Value) {
    LL->append(Value);
};
template <typename T> T Stack<T>::pop(void) {
    return LL->pop(LL->getLength());
};
template <typename T> T Stack<T>::current(void) {
    return LL->searchByIndex(LL->getLength());
};
template <typename T> LinkedList<T>* Stack<T>::getLinkedList(void) {
    return LL;
};

// -------------------- QUEUE --------------------
template <typename T> class Queue {
    public:
        // Constructors
        Queue(); // Empty Constructor
        Queue(const Queue<T>&); // Copy Constructor
        // Functions
        void add(T);
        T pop();
        T current();
        LinkedList<T>* getLinkedList();
    private:
        LinkedList<T>* LL;
};
// ---------- QUEUE CONSTRUCTORS ----------
template <typename T> Queue<T>::Queue(void) {
    LL = new LinkedList<T>();
};
template <typename T> Queue<T>::Queue(const Queue<T>& copy) {
    LL = copy->getLinkedList();
};
// ---------- QUEUE FUNCTIONS ----------
template <typename T> void Queue<T>::add(T Data) {
    LL->append(Data);
};
template <typename T> T Queue<T>::pop(void) {
    return LL->pop();
};
template <typename T> T Queue<T>::current(void) {
    return LL->searchByIndex(0);
};
template <typename T> LinkedList<T>* Queue<T>::getLinkedList(void) {
    return LL;
};

int main() {
    return 1;
};
