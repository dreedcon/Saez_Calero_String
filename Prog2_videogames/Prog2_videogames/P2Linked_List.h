#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_
#include "Utilities.h"

template<class VAR>
struct node
{
	VAR value = NULL;
	node<VAR>* next = NULL;
	
	node(const VAR& _data){ value = _data; }


};


template<class VAR>
class List
{

public:

	node<VAR>* start = NULL;
	
	List(){}
	~List(){ clear(); }
	


	//utility metodes\\
	
	VAR Front()
	{
		return start->value;
	
	}
	
	VAR End()
	{
		node<VAR>* tmp = start;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
	  
		return tmp->value;
	}

	//metodes\\

	//añade uno al final
	void Push_back(const VAR& new_data)
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
			while (tmp->next)
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
	bool pop_back(VAR& data)
	{
		node<VAR>* tmp = start;
		
		if (start == NULL)
		{
			return false;
        }
		else
		{
		node<VAR>* tmp1 = tmp;
	   while (tmp->next)
		{
		  tmp1 = tmp;
		  tmp = tmp->next;
		}
		
		data = tmp->value;
		
		if (start->next == NULL)
		{
			start = NULL;
		}
		
		delete tmp;
		tmp1 = tmp1->next = NULL;
		return data;
		return true;
		}
	   
	 }

	//elimina uno del principio
	bool pop_front(VAR& data)
	{
		node<VAR>* tmp = start;
		if (start == NULL)
		{
			return false;
		}
		else
		{
			node<VAR>*tmp1;
			start = tmp->next;
			tmp1 = tmp;
			data = tmp->value;
			start = tmp1->next;
			
			delete tmp;
			return data;
			return true;
		}
	}

	//inserta uno en una posicion
	bool Insert(const VAR& new_data, uint position)
	{
		node<VAR>* new_node = new node<VAR>(new_data);
		node<VAR>* tmp = start;
		node<VAR>*tmp1 = tmp;
		node<VAR>* tmp2;
		if (start == NULL)
		{
			return false;
		}
		else
		{
			for (int count = 0; count < position; count++)
			{
				tmp1 = tmp;
				tmp = tmp->next;
			}
			tmp2 = tmp;
			tmp = new_node;
			tmp1->next = tmp;
			tmp->next = tmp2;
			
			return true;
		}
	}

	//le das la posicion de uno y lo liquida
	bool remove(uint position)
	{
		node<VAR>* tmp = start;

		if (start == NULL)
		{
			return false;
		}
		else
		{
			node<VAR>* tmp1 = tmp;
			node<VAR>* tmp2;
			for (int count = 0; count < position; count++)
			{
				tmp1 = tmp;
				tmp = tmp->next;
			}
			tmp2 = tmp;
			tmp = tmp1;
			tmp->next = tmp2->next;
			
			return true;
			delete tmp2;
		}
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


template<class VAR>
class Stack_list
{

private:
	List<VAR> new_list;
public:
	
	void Push(const VAR& new_data)
	{
		new_list.Push_back(new_data);
	
	}

	void Pop(VAR& data)
	{
	  new_list.pop_back(data);
	}
	

};

/*
template<class VAR>
class Queue_list
{
private:
	List<VAR> new_list;
public:

	void Push(const VAR& new_data)
	{
		new_list.Push_back(new_data);
	}

	void Pop(VAR& new_data)
	{
		new_list.pop_front(new_data);
	}


};
*/

#endif

