//#include <string>

class Node {
	int data;
	Node *next;

public:
	//constructor
	Node(int);
	//destructor
	~Node();

	//accessors and mutators
	int get_data();
	void set_data(int);
	Node* get_next();
	void set_next(Node*);			//needs node pointer so it knows where to set after
};

class LinkedList {
	int size;
	Node *head;
	
public:
	//constructor
	LinkedList();
	//destructor and helper
	~LinkedList();
	void destr_helper(Node*);

	//functions
	int get(int);					//returns index data
	void set(int, int);				//set data at an index
	void insert(int, int);			//insert data at position
	int remov(int);
	void print_list();
	void back_print();
};