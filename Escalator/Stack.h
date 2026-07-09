#ifndef STACK_H
#define STACK_H

#include <iostream>
#include <stdexcept>

template <typename T>
class Stack {
private:
    struct Node {
        T data;
        Node* next;
        Node(T value) : data(value), next(nullptr) {}
    };

    Node* top;
    int size;

public:
    Stack() : top(nullptr), size(0) {}

    ~Stack() {
        while (!isEmpty()) {
            pop();
        }
    }

    // Push element onto stack
    void push(T value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        size++;
    }

    // Pop element from stack
    T pop() {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        Node* temp = top;
        T value = temp->data;
        top = top->next;
        size--;
        delete temp;
        return value;
    }

    // Peek at top element
    T peek() const {
        if (isEmpty()) {
            throw std::underflow_error("Stack is empty!");
        }
        return top->data;
    }

    // Check if stack is empty
    bool isEmpty() const {
        return size == 0;
    }

    // Get stack size
    int getSize() const {
        return size;
    }

    // Display all elements
    void display() const {
        Node* current = top;
        std::cout << "Stack (top to bottom): ";
        if (isEmpty()) {
            std::cout << "Empty" << std::endl;
            return;
        }
        while (current) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

#endif // STACK_H
