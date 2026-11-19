#include <iostream>
#include <stdexcept>
#include <string>

template <typename T>
class Queue {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& val) : data(val), next(nullptr) {}
    };

    Node* head;
    Node* tail;

public:
    Queue() : head(nullptr), tail(nullptr) {}

    // Destructor to clean up remaining nodes
    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    // Add an element to the back of the queue
    void enqueue(const T& value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    // Remove the element from the front of the queue
    void dequeue() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty: cannot dequeue");
        }
        Node* temp = head;
        head = head->next;
        if (head == nullptr) {
            tail = nullptr;
        }
        delete temp;
    }

    // Access the front element
    T& front() {
        if (isEmpty()) {
            throw std::out_of_range("Queue is empty: no front element");
        }
        return head->data;
    }

    bool isEmpty() const {
        return head == nullptr;
    }
};

int main() {
    Queue<std::string> q;

    // Enqueue string elements
    q.enqueue("First");
    q.enqueue("Second");
    q.enqueue("Third");

    std::cout << "Front element: " << q.front() << "\n"; // Outputs: First

    // Dequeue an element and check the new front
    q.dequeue();
    std::cout << "Front after dequeue: " << q.front() << "\n"; // Outputs: Second

    // Empty the rest of the queue
    std::cout << "Remaining elements: ";
    while (!q.isEmpty()) {
        std::cout << q.front() << " ";
        q.dequeue();
    }
    std::cout << "\n";

    return 0;
}
