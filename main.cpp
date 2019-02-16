#include "LinkedList.h"
using namespace std;
#include <iostream>

int main() {

	LinkedList *mylist = new LinkedList;		//create list pointer using default constructor
	
	mylist->print_list();				//should be nothing in list
	
	mylist->insert(0, 1);
	mylist->print_list();
	mylist->insert(1, 2);
	mylist->print_list();
	mylist->insert(2, 3);
	mylist->print_list();

	cout << "printing backwards" << endl;
	mylist->back_print();

//	cout << mylist->rem(1) << "was removed \n" << endl;
/*	mylist->print_list();
	try {
		mylist->insert(25, 26);
	}
	catch (const char *msg) {
		cout << msg << endl;
	}

	mylist->insert(2, 4);
	mylist->print_list();
	cout << mylist->rem(2) << " was removed \n" << endl;
	mylist->print_list();

	//mylist->back_print();
*/


	return 0;
}