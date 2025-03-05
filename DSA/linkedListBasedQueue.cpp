/*Linked-List based Queue

A linked list-based queue does not have a fixed. capaity. it grows as long as you have memory avalilabel.
-A head pointing to the front node.
-A tail pointer to the rear node.*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
	Node(int val): data(val), next(nullptr) {}
};

class LinkedListQueue {
private:
	Node* head; //Front
	Node* tail; //Rear

public:
	//consttructor
	LinkedListQueue(): head(nullptr), tail(nullptr){}

	void enqueue(int value) {
		Node* newNode = new Node(value);

		if (tail == nullptr) {
			head = newNode;
			tail = newNode;
		}
		else {
			tail->next = newNode;
			tail = newNode;
		}
	}

	//Deque operation
	bool dequeue() {
		if (isEmpty()) {
			return false;
		}
		Node* temp = head;
		head = head->next;
		if (head == nullptr) {
			//If the queue became empty
			tail = nullptr;
		}
		delete temp;
		return true;
	}

	//Get the front element
	int getFront() const {
		if (isEmpty()){
			return -1; //Or throw an exception
		}
		return head->data;
	}

	//Check if the queue is empty
	bool isEmpty() const {
		return (head == nullptr);
	}

	//Display the queue
	void display() const {
		if (isEmpty()) {
			cout << "Queue is Empty\n";
			return;

		}
		cout << "Queue [front-> rear]:";
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << " ";
			current = current->next;
		}
		cout << "\n";
	}

	//Destructor
	~LinkedListQueue() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}


};

int main() {
	LinkedListQueue q;

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display();

	cout << "Front element:" << q.getFront()<<endl;

	q.dequeue();
	q.display();

	q.enqueue(40);
	q.enqueue(50);
	q.display();

	q.dequeue();
	q.dequeue();
	q.display();


	return 0;
}

/*Key points
-enqueue: Create a new node, attach it to tail-> next, and mover tail to the new node
-Dequeue: Remove the nde at head and move head forward. If the queue becomes empty, set tail to nullptr
-No fixed capacity (only limted by system memory)*/