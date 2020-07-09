#ifndef LINKED_LIST_HEADER
#define LINKED_LIST_HEADER

#include <iostream>
#include "Node.h"



class LinkedList
{
    public:
	    typedef double value_type;
	    typedef size_t size_type;

	    /* Constructor */
	    LinkedList(const value_type& value = value_type(), Node * link = NULL);

	    size_type list_length(const Node * head_ptr);

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
