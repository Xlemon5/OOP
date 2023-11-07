#include <iostream>

template<typename T>
class Node {
public:
    T data;
    Node* next;
    Node* prev;

    Node(T data) : data(data), next(nullptr), prev(nullptr) {}
};

template <typename T>
class Deque {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    Deque() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!size) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!size) return;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    T& front() {
        return head->data;
    }

    bool empty() const {
        return size == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Deque& deque) {
        Node<T>* current = deque.head;
        os << "Deque elements: ";
        while (current != nullptr) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }


};



/*template <typename T>
class LinkedList {
private:
    Node<T>* head;
    Node<T>* tail;
    int size;

public:
    LinkedList() : head(nullptr), tail(nullptr), size(0) {}

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!size) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void pop_front() {
        if (!size) return;
        Node<T>* temp = head;
        if (head == tail) {
            head = tail = nullptr;
        }
        else {
            head = head->next;
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    T& front() {
        return head->data;
    }

    bool empty() const {
        return size == 0;
    }


    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        Node<T>* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};*/


template <typename T>
class LinkedList {
private:
    Node<T>* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    void push_back(const T& value) {
        Node<T>* newNode = new Node<T>(value);
        if (!size) {
            head = newNode;
        }
        else {
            Node<T>* current = head;
            while (current->next) {
                current = current->next;
            }
            current->next = newNode;
            newNode->prev = current;
        }
        size++;
    }

    void pop_front() {
        if (!size) return;
        Node<T>* temp = head;
        head = head->next;
        if (head) {
            head->prev = nullptr;
        }
        delete temp;
        size--;
    }

    T& front() {
        return head->data;
    }

    bool empty() const {
        return size == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const LinkedList& list) {
        Node<T>* current = list.head;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};


template <template <typename> class Container, typename T>
class Queue {
private:
    Container<T> container;

public:
    void enqueue(const T& value) {
        container.push_back(value);
    }

    void dequeue() {
        container.pop_front();
    }

    T& peek() {
        return container.front();
    }

    bool empty() const {
        return container.empty();
    }


    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        os << q.container;
        return os;
    }
};




int main() {
    Queue<Deque, int> dequeQueue;
    Queue<LinkedList, int> listQueue;
/*
    dequeQueue.enqueue(1);
    dequeQueue.enqueue(2);
    dequeQueue.enqueue(3);

    std::cout<< dequeQueue << std::endl;

    dequeQueue.dequeue();
    dequeQueue.enqueue(10);

    std::cout<< dequeQueue << std::endl;*/


    listQueue.enqueue(3);
    listQueue.enqueue(4);

    std::cout << listQueue << std::endl;

    listQueue.dequeue();
    listQueue.enqueue(17);

    std::cout << listQueue << std::endl;


    return 0;
}
