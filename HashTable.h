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
    HashTable(int initialSize = 16, int loadFactor = 10);
    ~HashTable();

    int getSize() const;
    int getCount() const;

    void insert(int key, const T& value);
    bool remove(int key);
    bool find(int key, T& value) const;
};

template <typename T>
HashTable<T>::HashTable(int initialSize, int loadFactor)
    : size(initialSize), count(0), loadFactor(loadFactor) {
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
bool HashTable<T>::find(int key, T& value) const {
    int index = hashFunction(key);
    return table[index].find(value);
}

template <typename T>
void HashTable<T>::rehash() {
    int newSize = size * 2;
    List<T>* newTable = new List<T>[newSize];

    for (int i = 0; i < size; ++i) {
        while (!table[i].empty()) {
            T value = table[i].removeFront();
            int newIndex = hashFunction(value.getId()) % newSize;
            newTable[newIndex].push_front(value);
        }
    }

    delete[] table;
    table = newTable;
    size = newSize;
}

#endif // HASHTABLE_H

