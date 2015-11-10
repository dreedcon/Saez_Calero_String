//dyn array vector stl para el proximo dia
#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#include "Utilities.h"

#define BLOCK 32

template<class VAR>
class P2DynArray
{

private:
	uint mem_capacity = 0;
	uint num_elements = 0;
	VAR* data = NULL;

public:
	//constructor vacio
	P2DynArray() : mem_capacity(BLOCK)
	{
		data = new VAR[BLOCK];
	}

	//constructor copia
	P2DynArray(const P2DynArray& _array) :num_elements(_array.num_elements)
	{
		mem_capacity = MAX(BLOCK, _arry.elements);
		data = new VAR[mem_capacity];
		memccpy(_array, _array.data, _array.num_elements * sizeof(VAR));
	}
	
	//constructor reserva de memoria 
	P2DynArray(const uint new_capacity)
	{
		if (mem_capacity < new_capacity)
		{
         mem_capacity = new_capacity;
		}
		data = new VAR[mem_capacity];
	}

	//destructor
	~P2DynArray()
	{
		if (mem_capacity != NULL)
			delete[] data;
	}

	
	//getters
	uint Getcapacity()const
	{
		return mem_capacity;
	}
     
    const P2DynArray* C_str()const
	{
	    return data;
	}
	
	//operators

	VAR& operator[](const uint& position)
	{
		if (position >= num_elements)
		assert(position < num_elements);
		else
		return data[position];

	}

     //utilities
	
	//At() le damos una posicion y nos dice que hay
	VAR& At(const uint& position)
	{
		if (position >= num_elements)
			printf("out of order \n");
		else
			return data[position];

	}

	
	//Pushback() le metemos un elemento detras 
	void Pushback(const VAR& _array)
	{
		if (num_elements == mem_capacity)
		{
			VAR* tmp = data;
			data = new VAR[mem_capacity + BLOCK];
			memcpy(data, tmp, num_elements*sizeof(VAR));
			delete[] data;
		}
		data[num_elements++] = _array;
	}

	 void Clear()
	 {
		elements = 0;
	 }

	bool Empyt()const
	{
		return elements == 0;
    }
     


};

//hacer operador[];
//hacer operador=;
//hacer pop_back();retorna el ultimo elemento y lo borra
//----------------------------------------------------------------------------------
//shink:to_fit() si sobra memoria ha de asegurarnos que esa memoria se borra
//flip()es como un swap
//insert(pos,data)le pasas una posicion y le insertas algo






#endif