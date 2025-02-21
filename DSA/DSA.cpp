/*Linked List*/
/* A linked list is a sequence of nodes where each node contains two parts:
-Data: The actual value stored (for example, an integer)
-Pointer: A reference (or address) to the next node in the list

Unlike arrays, linked lists don't require contiguous memory allocation.This makes
them great for situations where the number or elements can vary dynamically

*/
/*IMPLEMENTING A SINGLY LINKED LIST IN C++
Below is a simple implementation of a singly linked list in C++. This example covers:
-Inserting nodes at the head and tail.
-Displaying the list
-Searching for an element
-Deleting a node by its value
*/
#include <iostream>
using namespace std;

// Define a node structure
struct Node {
    int data;
    Node* next;
};

// Linked List class encapsulating list operations
class LinkedList {
private:
    Node* head; // Pointer to the first node

public:
    // Constructor: Initialize to nullptr
    LinkedList() : head(nullptr) {}

    // Function to insert a new node at the head
    void insertAtHead(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = head;
        head = newNode;
    }

    // Function to insert a new node at the tail
    void insertAtTail(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    // Function to display the list
    void display() {
        Node* current = head;
        while (current != nullptr) {
            cout << current->data << " -> ";
            current = current->next;
        }
        cout << "NULL" << endl;
    }

    // Function to search for a value in the list
    bool search(int value) {
        Node* current = head;
        while (current != nullptr) {
            if (current->data == value)
                return true;
            current = current->next;
        }
        return false;
    }

    // Function to delete a node by value
    void deleteValue(int value) {
        if (head == nullptr)
            return;

        // If the node to delete is at the head
        if (head->data == value) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next != nullptr && current->next->data != value) {
            current = current->next;
        }

        if (current->next != nullptr) {
            Node* temp = current->next;
            current->next = temp->next;
            delete temp;
        }
    }

    // Destructor: Free all nodes to avoid memory leaks
    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    LinkedList list;

    // Insert elements
    list.insertAtHead(10);
    list.insertAtTail(20);
    list.insertAtTail(30);

    // Display the list
    cout << "Initial list: ";
    list.display(); // Expected output: 10 -> 20 -> 30 -> NULL

    // Search for an element
    cout << "Searching for 20: " << (list.search(20) ? "Found" : "Not Found") << endl;

    // Delete an element and display the list again
    list.deleteValue(20);
    cout << "After deleting 20: ";
    list.display(); // Expected output: 10 -> 30 -> NULL

    return 0;
//}
/*EXPLANATION OF THE CODE

-Node structure: Each node contains an integer 'data' and a pointer 'next' to the next node
-LinkedList Class:
=Constructor: Initializes 'head' to 'nullptr'
=insertAtHead: Creates a new node and makes it the new head
=insertAtTail: Traverses the list to add a new node at the end.
=display: Iterates over the list and prints each node's data.
=search: Looks for a specific value in the list.
=deleteValue: Searches for and removes a node with a given value.
=Destructor: Deletes all nodes to free up memory.*/