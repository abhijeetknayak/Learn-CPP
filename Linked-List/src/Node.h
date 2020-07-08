#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <iostream>



class Node
{
    public:
	    typedef double value_type;

	    /* Constructor */
	    Node(const value_type& value = value_type(), Node * link = NULL);

	    void set_data(const value_type& value) { data = value; }
	    void set_link(Node * link = NULL) { next_node = link; }

	    value_type get_data() const { return data; }
	    const Node * get_link() const { return next_node; }
	    Node * get_link() { return next_node; }






    private:
	    value_type data;
	    Node * next_node;
//	    Node * prev_node;








};


#endif
