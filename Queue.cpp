#include "Queue.h"

Node::Node(int datum) {
	this->datum = datum;
	this->next = 0;	
	this->next = 0;			//could also be null. null = 0
}

Queue::Queue() {
	this->head = 0;
	this->tail = 0;
}

Queue::~Queue() {
	this->destr_helper(this->head);
}

void Queue::destr_helper(Node *node) {
	if (node) {
		//if the node is not null
		destr_helper(node->next);				//dont have to use get next bc we made next public
		delete node;
	}
}

void Queue::push(int datum) {
	Node *newNode = new Node(datum);		//new node w int inside
	if (this->head) {
		this->head->prev = newNode;
	}
	newNode->next = this->head;
	this->head = newNode;
	if (!tail) {
		//if we dont have a tail
		this->tail = newNode;				//could also say tail = head
	}
}

int Queue::pop() {
	if (!this->head) {
		//if we dont' have a head... so if theres nothing there
		throw "Queue is empty";
	}
	int retVal = this->tail->datum;		//return value is heads data
	Node *oldtail = this->tail;
	this->tail = this->tail->prev;		//now move the head down
	if (this->tail) {
		this->tail->next = 0;			//bc we are deleting
	}
	else {
		this->head = 0;
	}
	delete oldtail;
	return retVal;
}

int Queue::peek() {
	if (!this->tail) {
		throw "Queue is empty";
	}
	return this->tail->datum;
}

bool Queue::is_empty() {
	return !this->head;		//if we dont have a head.. TRUE. if we dont have a head .. FALSE
}