#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Utilities.h"

template<class VAR>
struct node
{
VAR value :
node<VAR>* next;
};


template<class VAR>
class List
{
public:

	node<VAR>* start = NULL;

public:

	 List();
	~List();
	
	void Pushback(node *&_list)
	{
		node *new_node;
		node *tmp;
		new_node = new node;
		new_node->next = NULL;
		if (_list != NULL)
		{
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			 tmp->next = new_node;
		}
		else
			_list = new_node;
	}
	
	int size();
	int Empty();
	void clear();
};








#endif