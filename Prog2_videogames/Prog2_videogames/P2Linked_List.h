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
	


	//metodes\\
	
	node<VAR>* Front()
	{
		return start;
	
	}
	
	node<VAR>* End()
	{
		node<VAR>* tmp = start;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
	  
		return tmp;
	}

	//utility metodes\\



	//añade uno al final
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

	//añade uno al principio
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

	//elimina uno del final
	int pop_back(VAR& data)
	{
		node<VAR>* tmp = start;
		
		if (start == NULL)
		{
			printf("there are zero nodes \n");
        }
		else
		{
		node<VAR>* tmp1 = tmp;
	   while (tmp->next)
		{
		  tmp1 = tmp;
		  tmp = tmp->next;
		}
		tmp1 = tmp1->next = NULL;
		data = tmp->value;
		delete tmp;
		}
	    return data;
	 }

	//elimina uno del principio
	int pop_front(VAR& data)
	{
		node<VAR>* tmp = start;
		if (start == NULL)
		{
			printf("there are zero nodes \n");
		}
		else
		{
			node<VAR>*tmp1;
			start = tmp->next;
			tmp1 = tmp;
			data = tmp->value;
			start = tmp1->next;
			
			delete tmp;
		}
	
		return data;
	}
	
	//devuelve de cuantos nods estas compuesto el tamaño de la lista
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
	
	//vacia la lista
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
	
	//comprueba si esta vacia la lista
	bool Empty()const
	{
	   return start == NULL;
	}

	




};
#endif


/*
---------------------------------------------------------------------
insert()coge una posicion y añade uno
remove()coge uno y lo liquida
*/