#ifndef _GRAPH_H_
#define _GRAPH_H_
#include "Utilities.h"
#include "P2list_ric.h"
#include "P2DynArray.h"


template<class VAR>
class Graph
{
public:
	
struct vertice
	{
	public:

		VAR value;
		p2List<vertice*> links;
		
		vertice(const VAR& value) : value(value)
		{}

		
		bool CanReach(const vertice* destination, P2DynArray<const vertice*>& visited)const
		{
			//comprobamos si esta en el destino
			if (this == destination)
			return true;
			
			
				visited.Pushback(this);
				//haciendo servir la recursividad  llama a todos los links que no han sido visitados
				for (const p2List<vertice*>::node* item = links.front_node(); item; item = item->next())
				{
					if (visited.find(item->data) == visited.Size())
					{
						if (item->data->CanReach(destination, visited) == true)
							return true;
					}
				}
				//si no encuentra el destino 
				return false;
			
		}
		
	};

private:

	p2List<vertice*> vertices;

public:
	 
	Graph(){};
	~Graph(){};

	//metodes\\
		
	//añade un vertice al final este es nuestro add node
	vertice* Push_back(const VAR& new_data)
	{
		vertice* new_vertice = new vertice(new_data);
		vertices.push_back(new_vertice);
		return new_vertice;
	
	}

   //comprueba si puede llegar hacia un vertice de manera iterativa(como un bucle recuerdalo) source = fuente, origen
	bool Is_reachable_iterative(const vertice* source,const vertice* distance)
	{
		if (source == distance)
		{
		return true;
		}
		//lleva  un registro de los nodos visitados
		P2DynArray<const vertice*> visited(Size());

		//con una queue organizamos los nodos que visitamos 
		Queue_list<const vertice*> queue;

		//añade el primer node que es visitado al final
		visited.Pushback(source);

		//Como sabemos como funciona la queue coge el ultimo nodo que hemos añadido y lo pone al principio
		queue.Push(source);

		//creamos un nuevo vertice que el que estamos mirando en ese momento current
		 const vertice* current;
		//comenzamos la iteracion :)
		while (queue.Pop(current) == true)
			{
				//iteramos todos los links
				const p2List<vertice*>::node* item = current->links.front_node();
				
				for (; item != NULL; item = item->next())
				{
					//Si hemos encontrado el destino habremos acabdo
					if (item->data == distance)
						return true;

					//comprobamos si han sido visitados
					if (visited.find(item->data) == visited.Size())
					{
						//si no han sido visitados los marcamos para añadirlos a la cola
						visited.Pushback(item->data);
						queue.Push(item->data);

					}
				}
				

            }
		return false;
	  
	}
   
	
	//lo mismo que el anterior pero de manera recursiva
	bool Is_reachable_recursive( vertice* source, const vertice* distance)
	{
		//hace un array dinamico con todos los vertices que tenemos
		P2DynArray<const vertice*>visited(Size());
	
		//llamamos a la funcion recursiva
		return source->CanReach(distance, visited);
	}
	

	uint Size()const
	{
		return vertices.size();
	}

	void Clear()
	{
		vertices.clear();
	}

	bool Empty()const
	{
		return vertices.empty();
	}

};


#endif