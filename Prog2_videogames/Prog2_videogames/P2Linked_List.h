#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Utilities.h"

template<class VAR>
struct node
{
    //hacer private los punteros y public el value
	VAR value;
   //hacer gets recuerda sergio son const
	node<VAR>* next = NULL;
    node<VAR>* prev = NULL;
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
		
	}
	
	int size()const
	{
		uint count = 0;
		node<VAR>* tmp = start;
	    
		while (tmp == NULL)
		{
			tmp = tmp->next;
			count++;
		}
	 
		return count;
	}
	
	void clear()
	{
		node<VAR>* tmp = start;
	    
		while (tmp->next == NULL)
		{
			tmp = tmp->next;
			delete tmp->prev;
			
		}
		start = NULL;
	
	}
	
	bool Empty()const
	{
	   return start == NULL;
	}
};
#endif


/*
front()es el start return const
back()y back es el ultimo return const
push_front() le ponemos uno al principio
pop_back() le quitamos uno al final retorna la data del node
pop_front()quitas el nodo principal y retorna la data del node
---------------------------------------------------------------------
insert()coge una posicion y añade uno
remove()coge uno y lo liquida
*/