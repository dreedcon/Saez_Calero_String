#include <iostream>
#include"P2string.h"


P2String::P2String()
{
	string = NULL;
	capacity = 0;
}

//constructor copia de una cadena
P2String::P2String(const char* _string)
{
	capacity = strlen(_string);
	_string = new  char[capacity + 1];
	strcpy_s(string, capacity, _string);

	delete _string;
}

//constructor copia de capacidad
P2String::P2String(UINT _capacity)
{
	capacity = _capacity;
}

//constructor copia de un puntero a la cadena
P2String::P2String(const P2String& _string)
{
	capacity = _string.capacity;
	string = new char[capacity + 1];
	strcpy_s(string, capacity, _string.string);

	delete string;
}

//getters los necesitamos porque como nuestras variables estan en privado tenemos que tenerlos para poder retornar sus valores
P2String P2String::getCapacity()
{
	return capacity;
}

P2String P2String::getString()
{
	return string;
}

bool P2String::operator==(const P2String& chain)const
{
	P2String tmp;

	if (chain.string == tmp.string)
	{
		return true;
	}
	else
	{
		return false;
	}

}