#include <iostream>

template <typename T>
class Deque {
private:
    struct Node {
        T data;
        Node* next;
        Node* prev;
        Node(const T& data) : data(data), next(nullptr), prev(nullptr) {}
    };

    Node* frontNode;
    Node* backNode;

public:
    Deque() : frontNode(nullptr), backNode(nullptr) {}

    void push_front(const T& data) {
        Node* newNode = new Node(data);
        if (frontNode == nullptr) {
            frontNode = newNode;
            backNode = newNode;
        }
        else {
            newNode->next = frontNode;
            frontNode->prev = newNode;
            frontNode = newNode;
        }
    }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (backNode == nullptr) {
            frontNode = newNode;
            backNode = newNode;
        }
        else {
            newNode->prev = backNode;
            backNode->next = newNode;
            backNode = newNode;
        }
    }

    T pop_front() {
        if (frontNode == nullptr) {
            throw std::runtime_error("Deque is empty");
        }
        T data = frontNode->data;
        Node* temp = frontNode;
        frontNode = frontNode->next;
        if (frontNode != nullptr) {
            frontNode->prev = nullptr;
        }
        else {
            backNode = nullptr;
        }
        delete temp;
        return data;
    }

    T pop_back() {
        if (backNode == nullptr) {
            throw std::runtime_error("Deque is empty");
        }
        T data = backNode->data;
        Node* temp = backNode;
        backNode = backNode->prev;
        if (backNode != nullptr) {
            backNode->next = nullptr;
        }
        else {
            frontNode = nullptr;
        }
        delete temp;
        return data;
    }

    bool isEmpty() {
        return frontNode == nullptr;
    }

    ~Deque() {
        while (frontNode != nullptr) {
            Node* temp = frontNode;
            frontNode = frontNode->next;
            delete temp;
        }
    }
};

int main() {
    Deque<int> deque;
    deque.push_front(1);
    deque.push_back(2);
    deque.push_front(3);

    while (!deque.isEmpty()) {
        std::cout << deque.pop_front() << " ";
    }

    return 0;
}
