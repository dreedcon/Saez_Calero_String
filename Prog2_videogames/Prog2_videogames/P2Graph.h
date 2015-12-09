#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Utilities.h"
#include "P2Linked_List.h"

template<class VAR>
struct node
{
	VAR data;
	list<node>* links;
	
};

template<class VAR>
class Graph
{

	list<node>* nodes;

public:
	 
	Graph();
   ~Graph();
	void AddLink(VAR* new_data, uint pos){}


};



#endif