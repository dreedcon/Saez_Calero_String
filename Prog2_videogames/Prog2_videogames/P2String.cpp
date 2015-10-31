#include <iostream>
#include"P2string.h"


P2String::P2String(){}

//constructor copia de una cadena
P2String::P2String(const char* _string)
{
	if (_string != NULL)
	{ 
		
	     capacity = strlen(_string) + 1;
	     string = new  char[capacity];
	     strcpy_s(string,capacity,_string);
		
	}

	
}

//constructor copia de capacidad
P2String::P2String(UINT _capacity)
{
	if (capacity > 0)
	{
		string = new char[_capacity];
		capacity = _capacity;
    }
	
}

//constructor copia de un puntero a la cadena
P2String::P2String(const P2String& _string)
{
	capacity = _string.capacity;
	string = new char[capacity + 1];
	strcpy_s(string, capacity, _string.string);

	
}

P2String::~P2String()
{
	if (string != NULL)
	{
		delete[] this->string;
	}
}

//getters los necesitamos porque como nuestras variables estan en privado tenemos que tenerlos para poder retornar sus valores
UINT P2String::GetSize(const char* _string)const
{
	UINT size = 0;
	size = strlen(_string);

    return size;
}

const char* P2String::_string()const
{

	return 0;
}


bool P2String::operator==(const char* chain)const
{
	if (chain != NULL)
	{
		if (strcmp(string, chain) == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
		return false;
	}
}

bool P2String::operator==(const P2String& chain)const
{

	if (strcmp(string, chain.string) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool P2String::operator!=(const char* chain)const
{
	if (strcmp(string, chain) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}


}

bool P2String::operator!=(const P2String& chain)const
{
	if (strcmp(string, chain.string) != 0)
	{
		return true;
	}
	else
	{
		return false;
	}


}

P2String P2String::operator=(const char* chain)
{
	UINT size = 0;
	UINT size1 = 0;
	size = strlen(chain);
	size1 = strlen(string);
	
	if (chain != NULL)
	{
		size = size1;
	}
	
	return *this;
}