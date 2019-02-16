//#include <string>

class Node {
	int datum;
	Node *next, *prev;		//pointer to node. Self referential (refers to itself inside itself

public:
	//constructor
	Node(int);
	//destructor
	~Node();
	//getters and setters
	int get_datum();
	void set_datum(int);		//change what datum is
	Node* get_next();
	void set_next(Node*);		//needs a node pointer so it knows which to insert after. change what next is
	Node* get_prev();
	void set_prev(Node*);
};


class LinkedList {
	int size;
	Node *head;
	Node *tail;		//dont we need a tail
public: 
	LinkedList();
	//LinkedList(int);
	~LinkedList();
	void destr_helper(Node*);
	int get(int);
	void set(int, int);
	void insert(int, int);
	int rem(int);
	void print_list();
	void back_print();
};