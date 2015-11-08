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
	UINT size = strlen(_string.string) + 1;
	string = new char[size];
	strcpy_s(string, size , _string.string);
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

const char* P2String::C_str()const
{

	return (string);
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

const P2String P2String::operator=(const char*chain)
{
	UINT size = strlen(chain) + 1;

	if (size > capacity)
	{
		delete[] string;
		capacity = size;
		string = new char[size];
	}
	strcpy_s(string, size, chain);

	return *this;
}

const P2String P2String::operator=(const P2String& chain)
{
	UINT size = chain.capacity + 1;

	if (size > capacity)
	{
		delete[] string;
		capacity = size;
		string = new char[size];
	}
		strcpy_s(string, size, chain.string);
	
	return *this;
}


const P2String P2String::operator+=(const char* chain)
{

	if (chain != NULL && string != NULL)
	{
		UINT size = strlen(string)  + (strlen(chain) + 1);

		if (size > capacity)
		{   
			char* tmp = new char[size];
			strcpy_s(tmp, size, string);
			string = new char[size];
			
			strcpy_s(string, size, chain);
			chain = tmp;
			strcat_s(string, size, chain);
			
			delete[] tmp;
		} 
		else
		{
			strcat_s(string, capacity, chain);
		}
	}
	return (*this);
}

const P2String P2String::operator+=(const P2String& chain)
{
	if (chain.string != NULL && string != NULL)
	{
		UINT size = strlen(string) + (strlen(chain.string) + 1);
		if (size > capacity)
		{    
			 char* tmp = new char[size];
			 strcpy_s(tmp, size, string);
			 string = new char[size];
			 
			 strcpy_s(string,size,chain.string);
			 strcpy_s(chain.string, size, tmp);
			
			 
			 strcat_s(string, size, chain.string);
			 
			 delete[] tmp;
		}
		else
		 strcat_s(string, capacity, chain.string);
		}

	return (*this);
}

//utility functions

const void P2String::Clear()const
{
   string[0] = '\0';
}



bool P2String::Empit()const
{
	UINT size = strlen(string);

	if ( size == NULL)
		return true;
	else
		return false;
}

const P2String P2String::Prefix(const char* chain)
{

	if (chain != NULL && string != NULL)
	{
		UINT size = strlen(string)  + (strlen(chain) + 1);
		if (size > capacity)
		{
			strcat_s(string, size, chain);
        }
	}
	
	return (*this);
}

const P2String P2String::Prefix(const P2String& chain)
{

	if (chain.string != NULL && string != NULL)
	{
		UINT size = (strlen(string) + 1) + (strlen(chain.string) + 1);
		if (size > capacity)
		{
		    strcat_s(string, size, chain.string);
        }
	}
    
	return (*this);
}