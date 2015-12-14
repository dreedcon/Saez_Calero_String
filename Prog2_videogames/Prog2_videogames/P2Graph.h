#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Utilities.h"
#include "P2Linked_List.h"
#include "P2DynArray.h"


template<class VAR>
class Graph
{
public:
	
struct Node
	{
	public:

		VAR value;
		P2DynArray<Node*> links;

		Node(const VAR& data)
		{
			this->value = data;
		}
		
		void AddLink( Node* children)
		{
			this->links.Pushback(children);
		}
		
		~Node(){ delete[] links;}

	};

private:

	list<Node*> nodes;

public:
	 
	Graph(){};
	~Graph(){};

	Node* AddNode(const VAR& new_data)
	{
		Node* new_node = new Node(new_data);
		nodes.Push_back(new_node);

		return new_node;
	}
	


 


};

/*
bool IsReachable (node* a, node* b)
{
   existe a? existe b?

   if a==b?
   if no tiene links devuelve false
   num links a? = 0 devuelve false
   {
    busco b todos los links -> si los encuentro es true
	si no miro el primer hijo y miro todos los links posibles, para que no vaya mirando lo que ya ha pasado los voy guardando en una queue o stack
   
   
   }
}






*/

#endif