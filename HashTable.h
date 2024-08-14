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

    void rehash();

public:
    HashTable(int initialSize = 16, int loadFactor = 10);
    ~HashTable();

    void insert(const T& key);
    bool remove(const T& key);
    bool find(const T& key) const;
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
void HashTable<T>::insert(const T& key) {
    int index = key % size;
    if (!table[index].find(key)) {
        table[index].push_front(key);
        count++;
    }

    if (count >= size * loadFactor) {
        rehash();
    }
}

template <typename T>
bool HashTable<T>::remove(const T& key) {
    int index = key % size;
    if (table[index].remove(key)) {
        count--;
        return true;
    }
    return false;
}

template <typename T>
bool HashTable<T>::find(const T& key) const {
    int index = key % size;
    return table[index].find(key);
}

template <typename T>
void HashTable<T>::rehash() {
    int newSize = size * 2;
    List<T>* newTable = new List<T>[newSize];

    for (int i = 0; i < size; ++i) {
        while (!table[i].empty()) {
            T key = table[i].removeFront();
            int newIndex = key % newSize;
            newTable[newIndex].push_front(key);
        }
    }

    delete[] table;
    table = newTable;
    size = newSize;
}

#endif // HASHTABLE_H
