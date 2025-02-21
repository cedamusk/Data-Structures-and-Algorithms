/*STACK IMPLEMENTATION USING A LINKEDLIST
If you want a dynamic stack that grows and shrinks without a fied size limit, you can use a linked list
*/

#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};

class StackLL {
private:
	Node* head; //Top of the stack

public:
	StackLL() : head(nullptr) {}

	//Push an element onto the stack
	void push(int value) {
		Node* newNode = new Node();
		newNode->data = value;
		newNode->next = head;
		head = newNode;
	}

	//Pop the top element from the stack
	void pop() {
		if (isEmpty()) {
			cout << "Stack underflow! Cannot pop." << endl;
			return;
		}
		Node* temp = head;
		head = head->next;
		delete temp;
	}

	//Return the top element without removing it
	int top() {
		if (isEmpty()) {
			cout << "Stack is empty! No top element." << endl;
			return -1; //Or handle  error
		}
		return head->data;
	}

	//check if the stack is empty
	bool isEmpty() {
		return (head == nullptr);
	}

	//Display all elements in the stack
	void display() {
		if (isEmpty()) {
			cout << "Stack is empty!" << endl;
			return;
		}
		cout << "Stack elements [top->bottom]:";
		Node* current = head;
		while (current != nullptr) {
			cout << current->data << "";
			current = current->next;
		}
		cout << endl;
	}

	//Destrutor to free memory
	~StackLL() {
		while (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
	}
};

int main() {
	StackLL stack;

	stack.push(100);
	stack.push(200);
	stack.push(300);
	stack.display(); //Expected: 300 200 100

	cout << "Top element:" << stack.top() << endl; //Expected: 300

	stack.pop();
	stack.display(); //Expected: 200 100

	stack.pop();
	stack.pop();
	stack.pop(); //triggers "Stack underflow!"

	return 0;
}

/*HOW IT WORKS
-Each 'Node' stores 'data' and a pointer 'next'.
-The head pointer represents the top os the stack.
-Push: Create a new node, link it to the current head, and update head to the new node.
-Pop: Move head to the next node and delete the old head.
-Top: Return 'head->data.'
-isEmpty: Check if head is 'nullptr'*/