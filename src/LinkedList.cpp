#include "LinkedList.hpp"
#include <sstream>

LinkedList::LinkedList() : head_(nullptr) {}

LinkedList::~LinkedList() {
    Node* p = head_;
    while (p) {
        Node* nextNode = p->next;
        delete p;
        p = nextNode;
    }
}

void LinkedList::push_front(int v) {
    head_ = new Node(v, head_);
}

void LinkedList::remove_evens() {
    while (head_ && head_->value % 2 == 0) {
        Node* temp = head_;
        head_ = head_->next;
        delete temp;
    }

    Node* node = head_;
    while (node && node->next) {
        if (node->next->value % 2 == 0) {
            Node* toRemove = node->next;
            node->next = toRemove->next;
            delete toRemove;
        } else {
            node = node->next;
        }
    }
}

std::string LinkedList::to_string() const {
    std::ostringstream out;
    out << "[";
    Node* n = head_;
    bool first = true;
    while (n) {
        if (!first) out << ", ";
        first = false;
        out << n->value;
        n = n->next;
    }
    out << "]";
    return out.str();
}