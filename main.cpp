#include "LinkedList.h"
#include <iostream>
using namespace std;

int main() {

	LinkedList *list =  new LinkedList;
	
	list->insert(0, 1);
	list->print_list();
	
	list->insert(1, 2);
	list->print_list();

	list->insert(2, 3);
	list->print_list();

	list->insert(3, 4);
	list->print_list();

	list->insert(4, 5);
	list->print_list();

	cout << "printing backwards" << endl;
	list->back_print();

	cout << "Removing the last element... " << list->remov(4) << endl;
	list->print_list();




	return 0;
}