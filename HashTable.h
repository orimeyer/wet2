#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "List.h"

template <typename T>
class HashTable {
private:
    List<T>* table;   // Array of lists for chain hashing
    int size;         // Size of the hash table
    int count;        // Number of elements in the hash table
    int loadFactor;   // Load factor for rehashing

    int hashFunction(int key) const;
    void rehash();

public:
    HashTable();
    ~HashTable();

    int getSize() const;
    int getCount() const;
    T* getData(int key) const;

    void insert(int key, const T& value);
    bool remove(int key);
    bool find(int key, T& value) const;
};

template <typename T>
HashTable<T>::HashTable()
    : size(8), count(0), loadFactor(10) {
    table = new List<T>[size];
}

template <typename T>
HashTable<T>::~HashTable() {
    delete[] table;
}

template <typename T>
int HashTable<T>::hashFunction(int key) const {
    return key % size;
}

template <typename T>
int HashTable<T>::getSize() const {
    return size;
}

template <typename T>
int HashTable<T>::getCount() const {
    return count;
}

template <typename T>
void HashTable<T>::insert(int key, const T& value) {
    int index = hashFunction(key);
    if (!table[index].find(value)) {
        table[index].push_front(value);
        count++;
    }

    if (count >= size * loadFactor) {
        rehash();
    }
}

template <typename T>
bool HashTable<T>::remove(int key) {
    int index = hashFunction(key);
    if (table[index].remove(key)) {
        count--;
        return true;
    }
    return false;
}

template <typename T>
T* HashTable<T>::getData(int key) const {
    int index = hashFunction(key);
    T* result = nullptr;
    T value;
    if (table[index].find(value)) {
        result = &value;
    }
    return result;
}

template <typename T>
bool HashTable<T>::find(int key, T& value) const {
    int index = hashFunction(key);
    return table[index].find(value);
}

template <typename T>
void HashTable<T>::rehash() {
    int newSize = size * 2;
    List<T>* newTable = new List<T>[newSize];
    int old_size = size;
    size = newSize;

    for (int i = 0; i < old_size; ++i) {
        while (!table[i].empty()) {
            T value = table[i].removeFront();
            int newIndex = hashFunction(value.getId());
            newTable[newIndex].push_front(value);
        }
    }

    delete[] table;
    table = newTable;
}

#endif // HASHTABLE_H

