template <typename T> class Node {
    public:
        // Constructors
        Node();
        Node(const Node<T>&);
        // Getters
        T getValue();
        Node<T>* getNext();
        // Setters
        void setValue(T);
        void setNext(Node<T>*);
    private:
        T Value;
        Node<T>* Next;
};

// Constructors

// Empty Constructor
template <typename T> Node<T>::Node(void) {
    Next = nullptr;
};
// Copy Constructor
template <typename T> Node<T>::Node(const Node<T>& Node) {
    this->Value = Node->getValue();
    this->Next = Node->getNext();
};

// Setters

// Set private attribute 'Value'
template <typename T> void Node<T>::setValue(T Value) {
    this->Value = Value;
};

// Set private attribute 'Next'
template <typename T> void Node<T>::setNext(Node<T>* Next) {
    this->Next = Next;
};

// Getters

// Get private attribute 'Value'
template <typename T> T Node<T>::getValue(void) {
    return this->Value;
};

// Get private attribute 'Next'
template <typename T> Node<T>* Node<T>::getNext(void) {
    return this->Next;
};
