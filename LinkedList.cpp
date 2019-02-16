#include "LinkedList.h"
#include <iostream>

//constructor for node class
Node::Node(int data) {
	this->data = data;		//local
	this->next = NULL;		//doesn't point to anything
}

//destructor for node class
Node::~Node() {

}

int Node::get_data() {
	return this->data;
}

void Node::set_data(int data) {
	this->data = data;
}

Node* Node::get_next() {
	return this->next;
}

void Node::set_next(Node *next) {
	this->next = next;
}

//linked list class now

LinkedList::LinkedList() {
	this->size = 0;
	this->head = NULL;		//Head doesn't point to anything yet
}

LinkedList::~LinkedList() {
	this->destr_helper(this->head);
}
void LinkedList::destr_helper(Node *node) {
	if (node->get_next() != NULL) {					//recursive call
		this->destr_helper(node->get_next());
	}
	delete node;
}

int LinkedList::get(int position) {
	if (position >= size || position < 0) {			//if its bigger than size
		throw "Index Out of Bounds!";
	}
	Node *temp = this->head;					//creating temp node pointer and setting to head
	for (int i = 0; i < position; i++) {
		temp = temp->get_next();				//move temp forward
	}
	return temp->get_data();
}

void LinkedList::set(int position, int value) {
	if (position >= size || position < 0) {
		throw "Index Out of Bounds!";
	}
	Node *temp = this->head;
	for (int i = 0; i < position; i++) {	
		temp = temp->get_next();			//move temp forward
	}
	temp->set_data(value);
}

void LinkedList::insert(int pos, int value) {
	if (pos > size || pos < 0) {
		throw "Index Out of Bounds!";
	}
	Node *newNode = new Node(value);			//new node that point to nothing
	Node *temp = this->head;					//set temp node to head
	if (pos == 0) {
		newNode->set_next(this->head);
		this->head = newNode;					//if inserting at pos 0, new node is the head
	}
	else {
		for (int i = 0; i < pos - 1; i++) {		//starting at pos 0.. go until given pos -1 bc we insert after that point
			temp = temp->get_next();					//keep moving temp forward
		}
		newNode->set_next(temp->get_next());			//new nodes link goes to temps link
		temp->set_next(newNode);						//now temp links to new node
	}
	this->size++;										//added an element so size must increase
}

int LinkedList::remov(int pos) {
	if (pos > size || pos < 0) {
		throw "Index Out of Bounds!";
	}
	int retVal;								//used to return data inside deleted node
	Node* temp = this->head;				//make temp point to head
	Node *helpNode;
	if (pos == 0) {							//if deleting the head
		head = temp->get_next();			//move head over to new position	
		helpNode = temp;						//
	}
	else {
		for (int i = 1; i < pos; i++) {			//stop at 1 before desired position
			temp = temp->get_next();			//move temp forward
		}
		helpNode = temp->get_next();				//now help node is the node to be deleted
		temp->set_next(helpNode->get_next());		//skipped over help and linked to helps link
	}
	retVal = helpNode->get_data();					//so we can return this future deleted value
	delete helpNode;								//delete unlinked node	
	return retVal;									//return data inside old node
	size--;											//decrement size							
}
void LinkedList::print_list() {
	std::cout << "{";
	if (this->size > 0) {
		//if we have items in the list
		std::cout << this->head->get_data();				//print the heads data
		for (Node* temp = this->head->get_next(); temp; temp = temp->get_next()) {
			//start temp at heads link. as long as temp has a value. move temp forward
			std::cout << ", " << temp->get_data();
		}
		std::cout << "}" << std::endl;

	}
}
void LinkedList::back_print() {
	Node *tail = this->head;

	std::cout << "{ ";
	while (tail->get_next()) {
		tail = tail->get_next(); //move it forward
	}
	std::cout << " " << this->tail->get_datum();
	while (tail != head) {
		std::cout << ", ";
		tail = tail->get_prev();
		std::cout << tail->get_datum();
	}
}