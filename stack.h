
class Node {
public:
	int datum, otherDat;		//does not mean whole line is int pointer... just datum is pointer. otherdat is plain int
	Node *next, *prev;
	Node(int);
};

class Stack {
	Node* head;				//points to the top
public:
	//constructor
	Stack();
	
	//destructor
	~Stack();
	void destr_helper(Node*);

	//function
	void push(int);		//puts something in
	int pop();			//removes top and returns
	int peek();			//returns what is on top
	bool is_empty();
};