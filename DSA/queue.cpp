/*INTRIDUCTION TO QUEUES*
/*A queue isa linear data structure that followsthe First-In, First-Out (FIFO)
principles. This means the first element inserted is the first element removed.

Key Operations
- Enqueue(x): Insert an element 'x' at the rear of the queue.
-Dequeue(): Remove the element from the frontof the queue.
-Front(): Return (without removing) the element at the front.
-isEmpty(): Checkif the queue is empty.
-isFull(): Check if the queue is full (for array-based implementations).

2. ARRAY BASED QUEUE
A. SIMPLE ARRAY BASED IMPLEMENTATION
 A straightforward way to implement a queue is to use an array and two indices: 'front' and 'rear'
 -'front' points to the first element in the queue.
 -'rear' points to the position where the next element will be inserted.
 -After 'rear' reaches the last index, if we continue to enqueue without removing elements,
 we can insert more even if there is space at the front (unless we implement a circular queue)*/

#include <iostream>
using namespace std;

class ArrayQueue {
private:
	int* arr; //dynamically allocated array
	int capacity; //maximum capacity of the queue
	int front; //index of the front element
	int rear; //index just past the last element
	int count; //current number of elements

public:
	//Constructor
	ArrayQueue(int size = 100) {
		capacity = size;
		arr = new int[capacity];
		front = 0;
		rear = 0;
	}

	//Destructor
	~ArrayQueue() {
		delete[] arr;
	}
	//Enqueue operation
	bool enqueue(int value) {
		if (isFull()) {
			return false;
		}
		arr[rear] = value;
		rear = (rear + 1) % capacity; //Move rear forward
		count++;
		return true;
	}

	//Dequeue operation
	bool dequeue() {
		if (isEmpty()) {
			return false;
		}
		front = (front + 1) % capacity; //Move front forward
		count--;
		return true;
	}

	//Get the front element
	int getFront() const {
		if (isEmpty()) {
			return -1; //Or throw an exception
		}
		return arr[front];

	}

	//Check if the queue is empty
	bool isEmpty() const {
		return (count == 0);
	}

	//Check if the queue is full
	bool isFull() const {
		return (count == capacity);
	}

	//Display queue contents
	void display() const {
		if (isEmpty()) {
			cout << "Queue is empty\n";
			return;
		}
		cout << "Queue [front -> rear]:";
		int idx = front;
		for (int i = 0; i < count; i++) {
			cout << arr[idx] << " ";
			idx = (idx + 1) % capacity;
		}
		cout << "\n";
	}
};

int main() {
	ArrayQueue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.display(); //Expected: 10 20 30

	cout << "front element:" << q.getFront() << endl; //Expected: 10

	q.dequeue();
	q.display(); //Expected: 20 30

	q.enqueue(40);
	q.enqueue(50);
	q.enqueue(60);// This should faill if queue is full
	q.display(); //expected: 20 30 40 50

	return 0;

}

/*KEY POINTS*/
/* -We used '(rear+1) % capacity' and '(front +1) % capacity' to achieve a 
circular effect. This way, when 'rear' and 'front' reaches the last index, it wraps around '0'.
-'count' keeps track of how many elements are currently in the queue*/