/*STACK

A stack is a linear data structure that follows the Last-In, First-Out (LIFO) principle.
This means the last item push (inserted) onto the stack is the first item popped (removed)

KEY OPERATIONS
1. Push(x): Insert an element 'x' on to of the stack.
2. Pop(): Remove the element from the top of the stack.
3. Peek()/Top(): return the element at the top without removing it.
4. isEmpty(): Check if the stack is empty.*/

#include <iostream>
using namespace std;

class Stack {
private:
	int* arr; //Pointer to array that will store stack elements
	int capacity;//maximum capacity of the stack
	int topIndex; //Index of the top element

public:
	//Constructor
	Stack(int size) {
		capacity = size;
		arr = new int[capacity];
		topIndex = -1;//Empty stacj indicator
	}

	//Destructor
	~Stack() {
		delete[] arr; //Free allocated memory
	}

	//Push an element onto the stack
	void push(int value) {
		if (topIndex == capacity - 1) {
			cout << "Stack overflow! Cannot push " << value << endl;
			return;
		}
		arr[++topIndex] = value;
	}

	//Pop the top element from the stack
	void pop() {
		if (isEmpty()) {
			cout << "Stack underflow! Cannot pop." << endl;
			return;
		}
		topIndex--;
	}

	//Return the top element without removing it
	int top() {
		if (isEmpty()){
			cout<<"Stack is empty! No top element."<<endl;
			return -1;//Or handle error differetly
		}
		return arr[topIndex];
	}

	//Check if the stack is empty
	bool isEmpty() {
		return (topIndex == -1);
	}

	//Display all elements in the stack
	void display() {
		if (isEmpty()) {
			cout << "Stak is empty!" << endl;
			return;
		}
		cout << "Stack elements [top->bottom]:";
		for (int i = topIndex; i >= 0; i--) {
			cout << arr[i] << "";
		}
		cout << endl;
	}
};

int main() {
	//Create a stack of capacity 5
	Stack s(5);

	s.push(10);
	s.push(20);
	s.push(30);
	s.display(); //Expected: 30 20 10

	cout << "Top element:" << s.top() << endl;//Expected: 30

	s.pop();
	s.display(); //Expected: 20 10

	s.pop();
	s.pop();
	s.pop(); //This should trigger "Stack underflow!

	return 0;
}

/*HOW IT WORKS
-We use a dynamic array 'arr' of size 'capacity.'
-topIndex starts '-1' (indicating an emoty stack).
-Push: Increment 'topIndex' and place the new element as 'arr[topIndex]'.
-Pop: Decrement 'topIndex' to remove the top element.
-Top: Return 'arr[topIndex]' (if not empty).
-isEmpty: Check if 'topIndex' is '-1'.
*/

