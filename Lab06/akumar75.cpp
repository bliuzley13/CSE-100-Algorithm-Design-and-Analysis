#include<bits/stdc++.h>
using namespace std;

class Hash {
    int BUCKET; // Number of buckets
    vector<list<int>> table; // Vector of lists for storing key-value pairs

public:
    Hash(int V); // Constructor
    // Inserts key into hash table
    void insertItem(int key);
    // Deletes key from hash table
    void deleteItem(int key);
    // Searches for key in hash table
    void search(int key);
    // Outputs hash table
    void output();
};

// Defines constructor of Hash class
Hash::Hash(int b) {
    // Pointer that points to the current object
    this->BUCKET = b;
    // Resizes table vector and used to change size of vector
    table.resize(BUCKET); // Resizes vector for BUCKET number of lists
}

void Hash::insertItem(int key) {
    // Calculates index where key should be inserted in hash table
    int index = key % BUCKET;
    // Inserts key at beginning of linked list at calculated index
    table[index].push_front(key);
}

void Hash::deleteItem(int key) {
    // Calculates index where key should be deleted in hash table
    int index = key % BUCKET;
    // Uses find function to search for the key in the linked list at calculated index
    auto it = find(table[index].begin(), table[index].end(), key);
    // Checks if key was found in the list
    if (it != table[index].end()) {
        // If found, removes key from list using erase function
        table[index].erase(it);
        // Prints saying it was deleted successfully
        cout << "" << key << ":DELETED;" << endl;
    } else {
        // Prints failure if key was not found
        cout << "" << key << ":DELETE_FAILED;" << endl;
    }
}

void Hash::search(int key) {
    // Calculates index where key should be searched in hash table
    int index = key % BUCKET;
    // Searches for key in linked list at calculated index
    auto it = find(table[index].begin(), table[index].end(), key);
    // Checks if key was found in list
    if (it != table[index].end()) {
        // Calculates position of key in list using distance function
        int position = distance(table[index].begin(), it);
        // Prints out the location
        cout << "" << key << ":FOUND_AT" << index << "," << position << ";" << endl;
    } else {
        // Prints out message that key was not found
        cout << "" << key << ":NOT_FOUND;" << endl;
    }
}

void Hash::output() {
    // Does the work for outputting the hash table
    for (int i = 0; i < BUCKET; i++) {
        cout << i << ":";
        // Iterates through each bucket in hash table and prints index
        for (const auto& key : table[i]) {
            // Follows keys in linked list at index, separated by '->'
            cout << key << "->";
        }
        cout << ";" << endl;
    }
}

int main() {
    // 'size' is the count of buckets in hash table
    int size;
    cin >> size;
    Hash h(size); 
    // Stores operation for the hash table
    char operation;
    // Stores integer key associated with operation
    int key;
    // Constructs loop that continues for valid input for operation 
    while (cin >> operation) {
        // insertItem operation
        if (operation == 'i') {
            cin >> key;
            h.insertItem(key);
        // deleteItem operation
        } else if (operation == 'd') {
            cin >> key;
            h.deleteItem(key);
        // search operation
        } else if (operation == 's') {
            cin >> key;
            h.search(key);
        // output function
        } else if (operation == 'o') {
            h.output();
        // exit function
        } else if (operation == 'e') {
            break;
        }
    }

    return 0;
}
