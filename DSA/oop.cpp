/*Objet-Oriented Programming (OOP) in C++

OOP is a rogramming paradigm that helps you design modular, reusable, and
maintable code by structuring your program into objects and classes.


Key concepts in OOP
1. Classes and objects
2. Encapsulation
3. Inheritance
4. Polymorphism
5. Abstraction

1. Classes and Objects
A class is a blueprint for creating objects. An object is an instance of a class*/

//A Simple Class

#include <iostream>
using namespace std;

class Car {
public:
	string brand;
	int year;

	//Constructor
	Car(string b, int y) {
		brand = b;
		year = y;
	}

	void displayInfo() {
		cout << "Car: " << brand << ", Year: " << year << endl;
	}
};

int main() {
	Car car1("Toyota", 2020);
	Car car2("Honda", 2022);

	car1.displayInfo();
	car2.displayInfo();

	return 0;
}

/*Explanation
-Car is a class with 'brand' and 'year' attributes.
-The constructor 'Car(string b, int y)' intializes the attributes.
-The 'displayInfo()' function prints 'car' details.
-Objects 'car1' and 'car2' are created from the 'Car' class.
*/
