#ifndef LIST_H
#define LIST_H

template <typename T>
class List {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& data) : data(data), next(nullptr) {}
    };

    Node* head;

public:
    List() : head(nullptr) {}
    ~List();

    void push_front(const T& value);
    bool remove(const T& value);
    bool find(const T& value) const;
    bool empty() const;
    void clear();
    T removeFront();
};

template <typename T>
List<T>::~List() {
    clear();
}

template <typename T>
void List<T>::push_front(const T& value) {
    Node* newNode = new Node(value);
    newNode->next = head;
    head = newNode;
}

template <typename T>
bool List<T>::remove(const T& value) {
    Node* current = head;
    Node* prev = nullptr;

    while (current) {
        if (current->data == value) {
            if (prev) {
                prev->next = current->next;
            } else {
                head = current->next;
            }
            delete current;
            return true;
        }
        prev = current;
        current = current->next;
    }
    return false;
}

template <typename T>
bool List<T>::find(const T& value) const {
    Node* current = head;
    while (current) {
        if (current->data == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
bool List<T>::empty() const {
    return head == nullptr;
}

template <typename T>
void List<T>::clear() {
    while (!empty()) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

template <typename T>
T List<T>::removeFront() {
    if (head) {
        Node* temp = head;
        T value = head->data;
        head = head->next;
        delete temp;
        return value;
    }
    return T(); // Return a default-constructed T if the list is empty
}

#endif // LIST_H
