#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Utilities.h"

template<class VAR>
struct node
{
    //hacer private los punteros y public el value
	VAR value = NULL;
   //hacer gets recuerda sergio son const
	node<VAR>* next = NULL;
	
	node(const VAR& _data){ value = _data; }


};


template<class VAR>
class list
{
public:
	
	//hacer get recuerda sergio son const
	node<VAR>* start = NULL;
	

	list(){}
	~list(){ clear(); }
	
	void Pushback(const VAR& new_data)
	{ 
		node<VAR>* new_node = new node<VAR>(new_data);

		if (start == NULL)
		{
			start = new_node;
		    new_node->next = NULL;
		}
		else
		{
			node<VAR>* tmp = start;
			while (tmp->next != NULL)
			{
				tmp = tmp->next;
			}
			tmp->next = new_node;
		    new_node->next = NULL;
		
		}
	}
	
	

	int size()const
	{
		uint count = 0;
		node<VAR>* tmp = start;
	    
		while (tmp != NULL)
		{
			tmp = tmp->next;
			count++;
		}
		return count;
	}
	
	void clear()
	{
		node<VAR>* tmp = start;
		node<VAR>* tmp1;
		
		
		while (tmp != NULL)
		{
	        tmp1 = tmp;
			tmp = tmp->next;
			delete tmp1;
			
		}
		start = NULL;
		}
	
	bool Empty()const
	{
	   return start == NULL;
	}

	void push_front(const VAR& new_data)
	{
		node<VAR>* new_node = new node<VAR>(new_data);

		if (start == NULL)
		{
		start = new_node;
		new_node->next = NULL;
		}
		else
		{
			node<VAR>* tmp = start;
			
			start = new_node;
			new_node->next = tmp;
		}
	}




};
#endif


/*
front()es el start return const
back()y back es el ultimo return const
pop_back() le quitamos uno al final retorna la data del node
pop_front()quitas el nodo principal y retorna la data del node
---------------------------------------------------------------------
insert()coge una posicion y añade uno
remove()coge uno y lo liquida
*/