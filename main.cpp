#include "Adder.h"
#include <iostream>


int main() {
	//create instance of the class
	//default constructor.... it should set both ops to 2
	Adder add1;

	//testing default
	cout << "TESTING DEFAULT CONSTRUCTOR... automatically set to 2 & 2." << endl;
	cout << "Get op1: " << add1.get(1) << endl;
	cout << "Get op2: " << add1.get(2) << endl;
	cout << "Sum is: " << add1.add() << endl;
	cout << "Difference is: " << add1.subtract() << endl;
	cout << "Product is : " << add1.multiply() << endl;
	cout << "Quotient is: " << add1.divide() << endl;
	cout << "Changing op1 using set function " << endl;
	add1.set(1, 6);		//using set function to change op 1 to 6
	cout << "Op1 is now: " << add1.get(1) << endl;
	//testing bad set choice


	//second constructor. You get to set local ops
	Adder add2(4, 3);

	cout << "TESTING 2ND CONSTRUCTOR. Initially set to 4 and 3" << endl;
	cout << "Get op1: " << add2.get(1) << endl;
	cout << "Get op2: " << add2.get(2) << endl;
	cout << "Sum is: " << add2.add() << endl;
	cout << "Difference is: " << add2.subtract() << endl;
	cout << "Product is: " << add2.multiply() << endl;
	cout << "Quotient is: " << add2.divide() << endl;
	cout << "Changing op2 to 5 using set function " << endl;
	add2.set(2, 5);		//using set function to change op 2 to 5
	cout << "Op2 is now : " << add2.get(2) << endl;
	//testing bad op choice
	cout << "Testing a bad op choice. I chose to get op3" << endl;
	try {
		add2.get(3);
	}
	catch (const char *str) {
		cout << str << endl;
	}


	return 0;
}