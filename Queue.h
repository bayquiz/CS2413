#pragma once
class Node {
public:
	int datum, otherDat;		//does not mean whole line is int pointer... just datum is pointer. otherdat is plain int
	Node *next, *prev;			//doubly linked list now
	Node(int);
};

class Queue {
	Node* head, *tail;				//points to the top and bottom now
public:
	//constructor
	Queue();

	//destructor
	~Queue();
	void destr_helper(Node*);

	//function
	void push(int);		//puts something in
	int pop();			//removes top and returns
	int peek();			//returns what is on top
	bool is_empty();
};