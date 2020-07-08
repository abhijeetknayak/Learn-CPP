#include "Node.h"

Node::Node(const value_type& value, Node * link)
{
	data = value;
	next_node = link;
}
