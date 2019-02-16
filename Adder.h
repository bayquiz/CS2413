#include <string>
using namespace std;

class Adder {
	float op1;	//only set to float to accomodate division.. 
	float op2;	//they couldve been ints as long as division was correct
	

public:
	//constructor
	Adder(); //default to set to 2
	Adder(int, int); //accept 2 numbers as arguments and use to set local operands

	//destructor... don't think its needed.
//	~Adder(); 

	//functions... that don't require parameters
	int add();	//return type int
	int subtract();	//return an int
	int multiply();	//return an int
	float divide();	//returns a float... i realize there could be precision loss in other operations.. but I only wanted to show that division would work

	//these functions take arguments
	int get(int); //specify which operand to return  (an int)
	void set(int, int); //specify which operand to set, and what to set it to. No return
};
