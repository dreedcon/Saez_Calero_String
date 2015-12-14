#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Utilities.h"
#include "P2Linked_List.h"
#include "P2DynArray.h"

template<class VAR>
struct Node
{
	VAR value = NULL;
	P2DynArray<node>* links;

	node(const VAR& data)
	{
		value = data;
	}
	
};

template<class VAR>
class Graph
{

	list<Node>* nodes = NULL;

public:
	 
	Graph();
   ~Graph();
	
   void AddNode(const VAR& new_data,const Node* father = NULL)
   {
	   NodeGraph<VAR*> new_node = new Node<VAR*>(new_data);

	   if (father != NULL)
	   {
		   father->links->Pushback(new_node);
	   }

	   nodes->PushBack(new_node);

	   if (start == NULL)
		   start = new_node;

	   p2List<Node*> tmp = start;
   }

   void LinkNodes(Node* father, Node* child)
   {
	   father->links->Pushback(fill);
   }
  
   Node* GetNode(int position)
   {
	   p2List<Node*> tmp = start;
	   int i = 0;
	   while (tmp->next)
	   {
		   if (position = i)
		   {
			   break;
		   }

		   i++;
	   }
	   return tmp;
   }





};



#endif