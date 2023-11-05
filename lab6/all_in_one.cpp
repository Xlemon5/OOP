#include <iostream>

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;

        Node(const T& value, Node* nextNode = nullptr, Node* prevNode = nullptr)
            : data(value), next(nextNode), prev(prevNode) {}
    };

    Node* front;
    Node* back;

public:
    Deque() : front(nullptr), back(nullptr) {}

    // Методы для добавления элементов в начало и конец очереди
    void push_front(const T& value) {
        Node* newNode = new Node( value, nullptr, nullptr );
        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    void push_back(const T& value) {
        Node* newNode = new Node( value, nullptr, nullptr );
        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
        }
    }

    // Методы для удаления элементов с начала и конца очереди
    void pop_front() {
        if (!empty()) {
            Node* temp = front;
            front = front->next;
            if (front) {
                front->prev = nullptr;
            }
            else {
                back = nullptr;
            }
            delete temp;
        }
    }

    void pop_back() {
        if (!empty()) {
            Node* temp = back;
            back = back->prev;
            if (back) {
                back->next = nullptr;
            }
            else {
                front = nullptr;
            }
            delete temp;
        }
    }

    bool empty() const {
        return front == nullptr;
    }

    // Дружественные операции ввода и вывода как внешние функции-шаблоны
    friend std::ostream& operator<<(std::ostream& os, const Deque& deque) {
        typename Deque<T>::Node* current = deque.front;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Deque& deque) {
        T value;
        is >> value;
        deque.push_back(value);
        return is;
    }
};









// Шаблон очереди с параметром-шаблоном
template <template <typename> class QueueType, typename ItemType>
class Queue {
private:
    QueueType<ItemType> queue;

public:
    // Методы для добавления и удаления элементов в очередь
    void enqueue(const ItemType& value) {
        queue.push_back(value);
    }

    void dequeue() {
        if (!empty()) {
            queue.pop_front();
        }
    }

    bool empty() const {
        return queue.empty();
    }

    // Дружественные операции ввода и вывода как внешние функции-шаблоны
    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        os << q.queue;
        return os;
    }

    friend std::istream& operator>>(std::istream& is, Queue& q) {
        ItemType value;
        is >> value;
        q.enqueue(value);
        return is;
    }
};




int main() {
    Queue<Deque, int> intQueue;


    intQueue.enqueue(1);
    intQueue.enqueue(2);
    intQueue.enqueue(3);



    std::cout << "intQueue: " << intQueue << std::endl;

    std::cout << "Dequeue from intQueue: ";
    intQueue.dequeue();
    std::cout << intQueue << std::endl;



    return 0;
}
