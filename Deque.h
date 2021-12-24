#pragma once

#include <iostream>
#include <ostream>
#include <vector>
using namespace std;

template<class T>
class Deque {
public:
    struct Node {
        T value;

        friend class Deque;

    private:
        Node() : value(T()), prev_(nullptr), next_(nullptr) {}

        explicit Node(const T& new_value) : value(new_value), prev_(nullptr), next_(nullptr) {}

        explicit Node(Node* from) : value(from->value), prev_(from->prev_), next_(from->next_) {}

    private:
        Node* prev_;
        Node* next_;
    };

    Deque() = default;

    Deque(const Deque<T>& from) {
        Node* location = from.front_;

        while (location != nullptr) {
            PushBack(location->value);
            location = location->next_;
        }
    }

    void Clear() {
        if (size_ == 0) {
            front_ = back_ = nullptr;
            return;
        }

        size_ = 0;
        while (front_ != back_) {
            Node* new_front = front_->next_;
            delete front_;
            front_ = new_front;
        }
        delete front_;
        front_ = back_ = nullptr;
    }

    ~Deque() {
        Clear();
    }

    Deque<T>& operator=(const Deque<T>& from) {
        if (this == &from) {
            return *this;
        }
        Clear();

        Node* location = from.front_;

        while (location != nullptr) {
            PushBack(location->value);
            location = location->next_;
        }
        return *this;
    }

    void PushFront(const T& value) {
        if (size_ == 0) {
            size_ = 1;
            front_ = back_ = new Node(value);
            return;
        }

        size_++;
        Node* new_front = new Node(value);
        front_->prev_ = new_front;
        new_front->next_ = front_;
        front_ = new_front;
    }

    void PushBack(const T& value) {
        if (size_ == 0) {
            size_ = 1;
            front_ = back_ = new Node(value);
            return;
        }

        size_++;
        Node* new_back = new Node(value);
        back_->next_ = new_back;
        new_back->prev_ = back_;
        back_ = new_back;
    }

    void PopFront() {
        size_--;
        if (Size() == 0) {
            delete front_;
            front_ = back_ = nullptr;
            return;
        }

        Node* new_front(front_->next_);
        new_front->prev_ = nullptr;
        delete front_;
        front_ = new_front;
    }

    void PopBack() {
        size_--;
        if (Size() == 0) {
            delete front_;
            front_ = back_ = nullptr;
            return;
        }

        Node* new_back(back_->prev_);
        new_back->next_ = nullptr;
        delete back_;
        back_ = new_back;
    }

    int Size() const {
        return size_;
    }

    void PrintInNormalOreder(ostream& output) const {
        Node* location = front_;
        output << "Elements of Deque in normal order";
        while (location != nullptr) {
            output << " " << location->value;
            location = location->next_;
        }
        output << endl;
    }

    void PrintInReversedOreder(ostream& output) const {
        Node* location = back_;
        output << "Elements of Deque in reversed order";
        while (location != nullptr) {
            output << " " << location->value;
            location = location->prev_;
        }
        output << endl;
    }

    int size_{ 0 };
    Node* front_{ nullptr };
    Node* back_{ nullptr };
};