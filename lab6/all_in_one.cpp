#include <iostream>

// Шаблон двусторонней очереди
template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
    };

    Node* front;
    Node* back;

public:
    Deque() : front(nullptr), back(nullptr) {}

    void push_front(const T& value) {
        Node* newNode = new Node{ value, nullptr, nullptr };
        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

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

    void push_back(const T& value) {
        Node* newNode = new Node{ value, nullptr, nullptr };
        if (empty()) {
            front = back = newNode;
        }
        else {
            newNode->prev = back;
            back->next = newNode;
            back = newNode;
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

    friend std::ostream& operator<<(std::ostream& os, const Deque& deque) {
        Node* current = deque.front;
        while (current) {
            os << current->data << " ";
            current = current->next;
        }
        return os;
    }
};



// Шаблон списка
template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
    };

    Node* head;

public:
    List() : head(nullptr) {}

    class Iterator {
    private:
        Node* current;

    public:
        Iterator(Node* node) : current(node) {}

        T& operator*() {
            return current->data;
        }

        Iterator& operator++() {
            if (current) {
                current = current->next;
            }
            return *this;
        }

        bool operator!=(const Iterator& other) {
            return current != other.current;
        }

        friend class List;
    };

    void insert(const T& value, Iterator position) {
        Node* newNode = new Node{ value, nullptr };
        if (position.current) {
            newNode->next = position.current->next;
            position.current->next = newNode;
        }
        else {
            newNode->next = head;
            head = newNode;
        }
    }

    void pop_front() {
        if (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    Iterator begin() {
        return Iterator(head);
    }

    Iterator end() {
        return Iterator(nullptr);
    }

    bool empty() const {
        return head == nullptr;
    }

    friend std::ostream& operator<<(std::ostream& os, const List& list) {
        for (Iterator it = list.begin(); it != list.end(); ++it) {
            os << *it << " ";
        }
        return os;
    }
};

// Общий интерфейс для работы с разными реализациями очереди
template <typename T>
class QueueInterface {
public:
    virtual void enqueue(const T& value) = 0;
    virtual void dequeue() = 0;
    virtual bool empty() const = 0;
    virtual ~QueueInterface() {}
};

// Шаблон очереди с параметром-шаблоном
template <typename QueueType, typename ItemType>
class Queue : public QueueInterface<ItemType> {
private:
    QueueType queue;

public:
    void enqueue(const ItemType& value) override {
        queue.push_back(value);
    }

    void dequeue() override {
        if (!empty()) {
            queue.pop_front();
        }
    }

    bool empty() const override {
        return queue.empty();
    }

    friend std::ostream& operator<<(std::ostream& os, const Queue& q) {
        os << q.queue;
        return os;
    }
};

int main() {
    Queue<Deque<int>, int> intDequeQueue;
    Queue<List<int>, int> intListQueue;

    intDequeQueue.enqueue(1);
    intDequeQueue.enqueue(2);
    intDequeQueue.enqueue(3);

    intListQueue.enqueue(1);
    intListQueue.enqueue(2);
    intListQueue.enqueue(3);

    std::cout << "intDequeQueue: " << intDequeQueue << std::endl;
    std::cout << "intListQueue: " << intListQueue << std::endl;

    std::cout << "Dequeue from intDequeQueue: ";
    intDequeQueue.dequeue();
    std::cout << intDequeQueue << std::endl;

    std::cout << "Dequeue from intListQueue: ";
    intListQueue.dequeue();
    std::cout << intListQueue << std::endl;

    return 0;
}
