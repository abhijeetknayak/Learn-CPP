#include "Node.h"


int main()
{
	Node * head_ptr, * tail_ptr;

	head_ptr = NULL;
	tail_ptr = NULL;

	Node * p = new Node;
	Node * q = new Node(3.4);
	Node * r = new Node(1.2, p);
}
