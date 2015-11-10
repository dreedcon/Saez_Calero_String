//dyn array vector stl para el proximo dia
#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#include "Utilities.h"

#define BLOCK 32

template<class DATA>
class P2DynArray
{

private:
	uint capacity = 0;
	uint elements = 0;
	DATA* _array = NULL;

public:
	//constructor vacio
	P2DynArray() : capacity(BLOCK)
	{
		_array = new DATA[BLOCK];
	}

	//constructor copia
	P2DynArray(const P2DynArray& _arry) : elements(_arry.elements)
	{
		mem_capacity = MAX(BLOCK, _arry.elements)
		_array = new DATA[capacity];
		memccpy(_array, _arry._array, _arry.elements * sizeof(DATA));
	}
	//constructor reserva de memoria
	P2DynArray(uint new_capacity)
	{
		if (capacity < new_capacity)
		{
         capacity = new_capacity;
		}
		_array = new DATA[capacity];
	
	}

	//destructor
	~P2DynArray()
	{
		if (capacity != NULL)
			delete[] _array;
	}

	
	//getters
	uint Getcapacity()const
	{
		return capacity
	}
     
    //hacer at -----> future At()

	const char* C_str()const
	{
	return _array;
	}
	
	//utilities
	void Phusback(const DATA& _arry)
	{
		if (capacity > elements)
		{
          DATA[elements + 1] = _arry;
		}
		else
		{
			DATA* tmp = _array;
			_array = new DATA[_arry];
			memcpy(data, tmp, elements*sizeof(DATA));
		}
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