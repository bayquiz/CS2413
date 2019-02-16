#include "Adder.h"

//constructor
Adder::Adder() {
	this->op1 = 2;		//setting ops to default values of 2
	this->op2 = 2;
	int choice;			//other variables used for decision making 
	int op; 
	int num;

}

//2nd constructor
Adder::Adder(int op1, int op2) {
	this->op1 = op1;
	this->op2 = op2;
}	//set local ops

/*destructor... not sure if it is needed
Adder::~Adder() {
	delete this->op1;
	delete this->op2;
}
*/

int Adder::add() {
	return this->op1 + this->op2;
}

int Adder::subtract() {
	return this->op1 - this->op2;
}

int Adder::multiply() {
	return this->op1 * this->op2;
}

float Adder::divide() {
	return this->op1 / this->op2;
}

int Adder::get(int choice) {
	if (choice == 1) {
		return this->op1;
	}
	else if (choice == 2) {
		return this->op2;
	}
	if (choice != 1 || choice != 2) {
		throw "Bad op choice. Must choose 1 or 2.";
	}
}

void Adder::set(int op, int num) {
	if (op == 1) {
		this->op1 = num;
	}
	else {
		this->op2 = num;
	}
}