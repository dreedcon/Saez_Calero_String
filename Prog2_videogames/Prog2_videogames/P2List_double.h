#ifndef _DOUBLE_LINKED_LIST_H_
#define _DOUBLE_LINKED_LIST_H_
#include "Utilities.h"
#include "P2Graph.h"




template<class VAR>
class List_double
{


public:
   
	template<class VAR>
	struct node_double
	{
		friend class List_double <VAR>;
		VAR value = NULL;
		node_double<VAR>* next = NULL;
		node_double<VAR>* prev = NULL;


		node_double(const VAR& _data){ value = _data; }

	};

private:
	node_double<VAR>* start = NULL;

public:
	List_double(){};
	~List_double(){ clear(); }


	//utility metodes\\

	node_double<VAR>* Front_node()const
	{
		return start;
	}

	node_double<VAR>* Back_node()
	{
		node_double<VAR>* tmp = start;
		while (tmp->next)
		{
			tmp = tmp->next;
		}
		return tmp;
	}

     VAR Front() 
	{
		return start->value;
	}

	 VAR End() 
	{
		node_double<VAR>* tmp = start;
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
		node_double<VAR>* new_node = new node_double<VAR>(new_data);

		if (start == NULL)
		{
			start = new_node;
			new_node->next = NULL;
		}
		else
		{
			node_double<VAR>* tmp = start;

			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = new_node;
			new_node->prev = tmp;

		}

	}

	//añade uno al principio
	void Push_front(const VAR& new_data)
	{
		node_double<VAR>* new_node = new node_double<VAR>(new_data);

		if (start == NULL)
		{
			start = new_node;
			new_node->next = NULL;
		}
		else
		{
			node_double tmp = start;

			start = new_node;
			new_node->next = tmp;
			tmp->prev = new_node;
		}
	}

	//elimina uno del final
	bool Pop_back(VAR& data)
	{
		if (start == NULL)
		{
			return false;
		}
		else
		{
			node_double<VAR>* tmp = start;
			node_double<VAR>* tmp1;

			while (tmp->next)
			{
				tmp = tmp->next;
			}
			data = tmp->value;
			tmp1 = tmp->prev;
			
			if (start->next != NULL)
			{
			   tmp1->next = NULL;
			}
			if (tmp->prev == NULL)
			{
				start = NULL;
			}
	
			delete tmp;
			return data;
			return true;
		}
	}

	//elimina uno del principio
	bool Pop_front(VAR& data)
	{
		if (start == NULL)
		{
			return false;
		}
		else
		{
			node_double<VAR>* tmp = start;
			data = tmp->value;
			start = start->next;
			
			delete tmp;
			return data;
			return true;
		}


	}

	//inserta un nodo en  una posicion
	bool Insert(const VAR& new_data, uint position)
	{
		node_double<VAR>* new_node = new node_double<VAR>(new_data);

		if (start == NULL)
		{
			return false;
		}
		else
		{
			node_double<VAR>* tmp = start;
			node_double<VAR>* tmp1 = tmp;
			node_double<VAR>* tmp2;

			for (int count = 0; position != count; count++)
			{
				tmp1 = tmp;
				tmp = tmp->next;
			}
			tmp2 = tmp;
			tmp = new_node;
			tmp1->next = tmp;
			tmp->next = tmp2;
			tmp->prev = tmp2;

			return true;
		}

	}

	//liquida uno de la posicion indicada
	bool Remove(uint position)
	{
		if (start == NULL)
		{
			return false;
		}
		else
		{
			node_double<VAR>* tmp = start;
			node_double<VAR>* tmp1 = tmp;
			node_double<VAR>* tmp2;

			for (int count = 0; position != count; count++)
			{
				tmp1 = tmp;
				tmp = tmp->next;
			}
			tmp2 = tmp;
			tmp = tmp1;
			tmp->next = tmp2->next;

			delete tmp2;

			if (tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
				tmp1->prev = tmp;
			}


			return true;
		}
	}

	//devuelve cuantos nodos hay en la lista
	int Size()const
	{
		int count = 0;
		node_double<VAR>* tmp = start;

		while (tmp != NULL)
		{
			tmp = tmp->next;
			count++;
		}
		return count;
	}

	//elimina los nodos de la lista en orden
	void clear()
	{
		node_double<VAR>* tmp = start;
		node_double<VAR>* tmp1;
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
class Queue_list
{
private:
	
	List_double<VAR> new_list;

public:

	void Push(const VAR& new_data)
	{
	  new_list.Push_back(new_data);
	}

	int Size()
	{
		return new_list.Size();
	}

    VAR Peek() 
	{
		return new_list.Front();
    }

	bool Empty()const
	{
		return new_list.Empty();
	}

	bool Pop(VAR& new_data)
	{
	  return new_list.Pop_front(new_data);
	}


};


#endif