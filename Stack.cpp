#include "stack.h"

Node::Node(int datum) {
	this->datum = datum;
	this->next = 0;				//could also be null. null = 0
}

Stack::Stack() {
	this->head = 0;
}

Stack::~Stack() {
	this->destr_helper(this->head);
}

void Stack::destr_helper(Node *node) {
	if (node) {
		//if the node is not null
		destr_helper(node->next);				//dont have to use get next bc we made next public
		delete node;
	}
}

void Stack::push(int datum) {
	Node *newNode = new Node(datum);		//new node w int inside
	newNode->next = this->head;
	this->head = newNode;
}

int Stack::pop() {
	if (!this->head) {
		//if we dont' have a head... so if theres nothing there
		throw "Stack is empty";
	}
	int retVal = this->head->datum;		//return value is heads data
	Node *oldHead = this->head;
	this->head = this->head->next;		//now move the head down
	delete oldHead;
	return retVal;
}

int Stack::peek() {
	if (!this->head) {
		throw "stack is empty";
	}
	return this->head->datum;
}

bool Stack::is_empty() {
	return !this->head;		//if we dont have a head.. TRUE. if we dont have a head .. FALSE
}