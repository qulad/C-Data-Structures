#include "linkedList.hpp"

template <typename T> class Stack {
    public:
        // Constructors
        Stack();
        Stack(const Stack<T>&);
        // Adder
        void Add(T);
        // Remover
        T Pop();
        // Getters
        T Current();
        LinkedList<T>* getLinkedList();
    private:
        LinkedList<T>* LL;
};

// Constructors

// Empty Constructor
template <typename T> Stack<T>::Stack(void) {
    this->LL = new LinkedList<T>();
};

// Copy Constructor
template <typename T> Stack<T>::Stack(const Stack<T>& stack) {
    this->LL = stack->getLinkedList();
};

// Adder

// Add data 'Data' to stack
template <typename T> void Stack<T>::Add(T Data) {
    this->LL->Append(Data);
};

// Remover

// Remove data from stack
template <typename T> T Stack<T>::Pop() {
    return this->LL->Pop();
};

// Getters

// Get current data
template <typename T> T Stack<T>::Current() {
    return this->LL->SearchByIndex(LL->getLength()-1);
};

// Get Linked List
template <typename T> LinkedList<T>* Stack<T>::getLinkedList() {
    return this->LL;
};
