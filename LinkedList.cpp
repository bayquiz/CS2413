#include "LinkedList.h"
#include <iostream>

Node::Node(int datum) {
	this->datum = datum;
	this->next = NULL;		//doesn't point to anything yet
	this->prev = NULL;		//blank nodes
}

//destructor
Node::~Node() {

}

int Node::get_datum() {
	return this->datum;
}

void Node::set_datum(int datum) {
	this->datum = datum;
}

Node* Node::get_next() {
	return this->next;
}

void Node::set_next(Node *next) {
	this->next = next;
}

Node* Node::get_prev() {
	return this->prev;
}

void Node::set_prev(Node *prev) {
	this->prev = prev;
}


//Linked list class

//constructor
LinkedList::LinkedList() {
	this->size = 0;
	this->head = NULL;		//no value is in head yet
	this->tail = NULL;
}

//destructor
LinkedList::~LinkedList() {
	this->destr_helper(this->head);
}

//destructor helper
void LinkedList::destr_helper(Node *node) {
	if (node->get_next() != NULL) {
		this->destr_helper(node->get_next());		//recursively call
	}
	delete node;
}

int LinkedList::get(int index) {
	if (index >= this->size) {
		throw "Index Out of bounds";
	}
	Node *temp = this->head;	//temp node pointer thats pointing to head
	for (int i = 0; i < index; i++) {
		temp = temp->get_next();	//move temp forward
	}
	return temp->get_datum();
}
void LinkedList::set(int index, int value) {
	if (index >= this->size) {
		throw "Index Out of bounds";
	}
	Node *temp = this->head;	//temp node pointer thats pointing to head
	for (int i = 0; i < index; i++) {
		temp = temp->get_next();	//move temp forward
	}
	temp->set_datum(value);			//set to value given
}

void LinkedList::insert(int index, int value) {
	if (index > this->size) {				//cant insert too far
		throw "Index Out of bounds";
	}
	Node *newNode = new Node(value);		//we have new node pointing to nothing
	Node *temp = this->head;				//temp pointer is pointing to head
	if (index == 0) {
		//if temp is null.... aka if head is null
		newNode->set_next(this->head);		//newNode is set to head
		if (this->head) {					//if we have a head
			this->head->set_prev(newNode);	//set previous to new node
		}
		this->head = newNode;
	}
	else {
		for (int i = 1; i < index; i++) {	//no need to check 0 bc we already did above. temp is already 0
			temp = temp->get_next();		//you can also start at i = 0; and go to i < index - 1;
		}
		newNode->set_next(temp->get_next());	//setting new node link to temps link
		newNode->set_prev(temp);					//previous of new node is temp
		if (newNode->get_next()) {					//inserting at the tail?
			newNode->get_next()->set_prev(newNode);
		}
		temp->set_next(newNode);				//changing temps link to new node.. breaking old connection
	}
	this->size++;		//EITHER WAY WE JUST ADDED AN ELEMENT
}

int LinkedList::rem(int index) {
	if (index >= this->size) {
		throw "Index out bounds";
	}

	int retVal;						//we will need the value inside the deleted node
	Node* temp = this->head;
	//Node *retNode;					//will point to node that is going to be removed. no longer needed bc we can point backwards
	if (index == 0) {
		//deleting the head
		this->head = temp->get_next();		//bc head is being deleted... move head up a link

		if (this->head) {
			this->head->set_prev(NULL);		//bc there is nothing before head
		}
	//	retNode = temp;			
	}
	else {
		for (int i = 0; i < index; i++) {
			//will stop 1 i front of desired position NOT ANYMORE
			//bc we have prev pointer we can stop at desired destination

			temp = temp->get_next();			//move temp forward
		}
		//retNode = temp->get_next();				//retnode is now the node to be deleted
		//temp->set_next(retNode->get_next());	//skipping links... retnode is now connected to nothing
		temp->get_prev()->set_next(temp->get_next());
		if (temp->get_next()) {
			//if we are removing at tail
			temp->get_next()->set_prev(temp->get_prev());
		}
	
	}
	retVal = temp->get_datum();
	delete temp;
	return retVal;
	this->size--;
}

void LinkedList::print_list() {
	std::cout << "{ ";			//have to used std bc we didn't declare using namespace std
	if (this->size > 0) {
		//if we have a list
		std::cout << " " << this->head->get_datum();
		for (Node *temp = this->head->get_next(); temp; temp = temp->get_next()) {
			//starting at temp = heads next. as long as temp is something. move temp forward
			std::cout << ", " << temp->get_datum();
		}
	}
	std::cout << " }" << std::endl;
}

void LinkedList::back_print() {
	tail = this->head;

	std::cout << "{ ";
	if (this->size > 0) {
		//std::cout << tail->get_datum();
		while (tail->get_next() != NULL) {
			this->tail = tail->get_next();
		}
		//now should be at the end
		std::cout << tail->get_datum();
		while (tail->get_prev() != NULL) {
			tail = tail->get_prev();
			std::cout << " " << tail->get_datum();
		}
		
	}
	std::cout << " }";
}