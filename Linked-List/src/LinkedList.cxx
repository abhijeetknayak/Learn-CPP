#include "LinkedList.h"


LinkedList::size_type LinkedList::list_length(const Node * head_ptr)
{
	size_type count = 0;
	const Node * cursor;

	for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_link())
		count++;

	return count;
}
