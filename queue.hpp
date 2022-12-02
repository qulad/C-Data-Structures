#include "linkedList.hpp"

template <typename T> class Queue {
    public:
        // Constructors
        Queue();
        Queue(const Queue<T>&);
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
template <typename T> Queue<T>::Queue(void) {
    this->LL = new LinkedList<T>();
};

// Copy Constructor
template <typename T> Queue<T>::Queue(const Stack<T>& stack) {
    this->LL = stack->getLinkedList();
};

// Adder

// Add data 'Data' to queue
template <typename T> void Queue<T>::Add(T Data) {
    this->LL->Append(Data);
};

// Remover

// Remove data from queue
template <typename T> T Queue<T>::Pop() {
    return this->LL->Pop(0);
};

// Getters

// Get current data
template <typename T> T Queue<T>::Current() {
    return this->LL->SearchByIndex(0);
};

// Get Linked List
template <typename T> LinkedList<T>* Queue<T>::getLinkedList() {
    return this->LL;
};
