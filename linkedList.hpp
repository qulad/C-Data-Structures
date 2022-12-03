#include "node.hpp"

template <typename T> class LinkedList {
    public:
        // Constructors
        LinkedList();
        LinkedList(const LinkedList<T>&);
        // Adders
        void Append(T);
        void Insert(int, T);
        // Removers
        T Pop(int);
        T Pop();
        T Remove(T);
        // Searchers
        T SearchByIndex(int);
        int SearchByValue(T);
        // Getters
        Node<T>* getHead();
        int getLength();
    private:
        Node<T>* Head;
        int Length;
};

// Constructors

// Empty Constructor
template <typename T> LinkedList<T>::LinkedList(void) {
    Head = nullptr;
    Length = 0;
};

// Copy Constructor
template <typename T> LinkedList<T>::LinkedList(const LinkedList<T>& LL) {
    this->Head = LL->getHead();
    this->Length = LL->getLength();
};

// Adders

// Insert data 'Data' to index 'Index'
template <typename T> void LinkedList<T>::Insert(int Index, T Data) {
    if (Index < 0) return ;
    if (Index > this->Length) return ;

    Node<T>* newNode = new Node<T>();
    newNode->setValue(Data);
    if (this->Length == 0) {
        this->Head = newNode;
        this->Length = 1;
        return ;
    }
    if (Index == 0) {
        newNode->setNext(this->Head);
        this->Head = newNode;
        Length++;
        return ;
    }
    Node<T>* temp = this->Head;
    if (Index == this->Length) {
        for (int i=1; i<Length; i++) {
            temp = temp->getNext();
        }
        temp->setNext(newNode);
        Length++;
        return ;
    }

    for (int i=1; i<=Index; i++) {
        if (i == Index) {
            Node<T>* nextNode = temp->getNext();
            temp->setNext(newNode);
            newNode->setNext(nextNode);
            return;
        }
        temp = temp->getNext();
    }
};

// Append data 'Data' to the end
template <typename T> void LinkedList<T>::Append(T Data) {
    this->Insert(this->Length, Data);
};

// Removers

// Remove node @ index 'Index'
template <typename T> T LinkedList<T>::Pop(int Index) {
    T error;
    if (Index < 0) return error;
    if (Index > this->Length-1) return error;

    T value;
    if (Index == 0) {
        value = this->Head->getValue();
        this->Head = this->Head->getNext();
        return value;
    }
    Node<T>* temp = this->Head;
    for (int i=0; i<=Index; i++) {
        if (i == Index-1) {
            value = temp->getNext()->getValue();
            Node<T>* next = temp->getNext()->getNext();
            if (temp->getNext()->getNext() == nullptr) {
                temp->setNext(nullptr);
                Length--;
                return value;
            }
            temp->setNext(next);
            return value;
        }
        
        temp = temp->getNext();
    }
    return error;
};

// Remove node @ end
template <typename T> T LinkedList<T>::Pop() {
    return this->Pop(this->Length-1);
};

// Remove first found
template <typename T> T LinkedList<T>::Remove(T Data) {
    return this->Pop(this->SearchByValue(Data));
};

// Searchers

// Searches for data at index 'Index'
template <typename T> T LinkedList<T>::SearchByIndex(int Index) {
    T error;
    if (Index < 0) return error;
    if (Index > Length-1) return error;

    Node<T>* temp = Head;
    for (int i=0; i <= Index; i++) {
        if (i == Index) return temp->getValue();
        temp = temp->getNext();
    }
    return error;
};

// Searches for index of data 'Data'
template <typename T> int LinkedList<T>::SearchByValue(T Data) {
    T error;

    Node<T>* temp = Head;
    for (int i=0; i <= this->Length-1; i++) {
        if (temp->getValue() == Data) return i;
        temp = temp->getNext();
    }
    return error;
};

// Getters

// Get private attribute 'Head'
template <typename T> Node<T>* LinkedList<T>::getHead() {
    return this->Head;
};

// Get private attribute 'Length'
template <typename T> int LinkedList<T>::getLength() {
    return this->Length;
};
