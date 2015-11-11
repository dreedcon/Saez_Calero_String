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

	const VAR& operator[](const uint& position)
	{
		
		assert(position < num_elements);
		return data[position];

	}

	const P2DynArray& operator=(const P2DynArray& _array)
	{
		if (_array.num_elements > mem_capacity)
		{
			delete[] data;
			mem_capacity = _array.mem_capacity;
			data = new VAR[mem_capacity];

			memcpy(data, _array.data, num_elements*sizeof(VAR));
		}
		else
		memcpy(data, _array.data, num_elements*sizeof(VAR));

		return *this;
	
	}

     //utilities
	
	//Pushback() le metemos un elemento detras 
	void Pushback(const VAR& _array)
	{
		if (num_elements == mem_capacity)
		{
			VAR* tmp = data;
			data = new VAR[mem_capacity + BLOCK];
			memcpy(data, tmp, num_elements*sizeof(VAR));
		}
		data[num_elements++] = _array;
	}
	
	//At() le damos una posicion y nos dice que hay
	VAR& At(const uint position)
	{
		if (position >= num_elements)
			printf("out of order \n");
		else
			return data[position];

	}

	//Popback() devuelve el ultimo elemento y lo borra
	void Popback()
	{
		if (num_elements == 0)
			printf("there are zero elements \n");
		else
		num_elements--;
	}
	
	//si sobra memoria ha de asegurarnos que esa memoria se borra
	void shink_to_fit()
	{
		if (num_elements == mem_capacity)
		{
			printf("already are equal\n");
		}
		else
		{
			VAR* tmp = data;
			mem_capacity = num_elements - 1;
			data = new VAR[mem_capacity];
			memcpy(data, tmp, num_elements*sizeof(VAR));
		}

    }
    
	//le pasas una posicion y le insertas algo
	void Insert(const uint& pos, const VAR& _array)
	{
		for (uint i = num_elements; i > pos; --i)
		{
			data[i] = data[i - 1];
		}
		data[pos] = _array;
		num_elements++;
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

//----------------------------------------------------------------------------------
//flip()es como un swap
//insert(pos,data)






#endif