//dyn array vector stl para el proximo dia
#include "Utilities.h"
#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_

#define BLOCK 32

template<class DATA>
class P2DynArray
{

private:
	UINT capacity = 0;
	UINT elements = 0;
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
		mem_capacity = MAX(BLOCK, _array.capacity)
		_array = new DATA[mem_capacity];
		memccpy(_array, _arry._array, _arry.elements * sizeof(DATA));
	}

	//destructor
	~P2DynArray()
	{
		if (capacity == NULL)
			delete[] _array;
	}

	void Phusback(const DATA& _arry)
	{
		if (elements == capacity)
		{
			_array = new DATA[capacity + BLOCK];
		}
		DATA[elements + 1] = _arry;
    }

	UINT Getcapacity()const
	{
		return capacity
	}
	
	UINT GetElements()const
	{
	return capacity;
	}

	const char* C_str()const
	{
	return _array;
	}
	

	 void Clear()
	 {
		elements = 0;
	 }

	bool Empyt()
	{
	return elements == 0
    }



};








#endif