#include <iostream>
#include"P2string.h"


P2String::P2String()
{

	capacity = 0;
	string = NULL;

}

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
P2String::P2String(uint _capacity)
{
	if (capacity > 0)
	{
		string = new char[_capacity];
		capacity = _capacity;
    }
	
}

//constructor copia
P2String::P2String(const P2String& _string)
{ 
	uint size = strlen(_string.string) + 1;
	string = new char[size];
	strcpy_s(string, size , _string.string);
}

P2String::~P2String()
{
	if (string != NULL)
	{
		delete[] string;
	}
}

//getters 
uint P2String::GetCapacity()const
{
     return capacity;
}

const char* P2String::C_str()const
{

	return (string);
}

uint P2String::Length()const
{
	
	int count = 0;
	while (count < sizeof(string))
	{
		count++;
	}

	return count;
}

//operadores
bool P2String::operator==(const char* chain)const
{
	return (strcmp(string, chain) == 0);
}

bool P2String::operator==(const P2String& chain)const
{
    return (strcmp(string, chain.string) == 0);
}

bool P2String::operator!=(const char* chain)const
{
	return (strcmp(string, chain) != 0);	
}

bool P2String::operator!=(const P2String& chain)const
{
	return (strcmp(string, chain.string) != 0);
}

const P2String& P2String::operator=(const char*chain)
{
	uint size = strlen(chain) + 1;

	if (size > capacity)
	{
		delete[] string;
		capacity = size;
		string = new char[size];
	}
	strcpy_s(string, size, chain);

	return *this;
}

const P2String& P2String::operator=(const P2String& chain)
{
	uint size = chain.capacity + 1;

	if (size > capacity)
	{
		delete[] string;
		capacity = size;
		string = new char[size];
	}
		strcpy_s(string, size, chain.string);
	
	return *this;
}


const P2String& P2String::operator+=(const char* chain)
{

	if (chain != NULL && string != NULL)
	{
		uint size = strlen(string) + (strlen(chain) + 1);

		if (size > capacity)
		{   
			char* tmp = new char[size];
			strcpy_s(tmp, size, string);
			strcpy_s(string, size, tmp);
			
			strcat_s(string, size, chain);
			delete[] tmp;
		} 
		else
		{
			strcat_s(string, capacity, chain);
		}
	}
	return *this;
}

const P2String& P2String::operator+=(const P2String& chain)
{
	if (chain.string != NULL && string != NULL)
	{
		uint size = strlen(string) + (strlen(chain.string) + 1);
		
		if (size > capacity)
		{    
			 char* tmp = new char[size];
			 strcpy_s(tmp, size, string);
			 string = new char[size];
			
			 strcpy_s(string,size,tmp);
			 strcat_s(string, size, chain.string);
			 
			 delete[] tmp;
		}
		else
		 strcat_s(string, capacity, chain.string);
	}

	return *this;
}

//utility functions

void P2String::Clear()
{
   string[0] = '\0';
}



bool P2String::Empit()const
{
	uint size = strlen(string);

	return (size == NULL);

}

const P2String& P2String::Prefix(const char* chain)
{
  if (chain != NULL && string != NULL)
	{
		uint size = strlen(string) + (strlen(chain) + 1);

		if (size > capacity)
		{
			char* tmp = new char[size];
			strcpy_s(tmp, size, string);

			strcpy_s(string, size, chain);
			chain = tmp;
			
			strcat_s(string, size, chain);
            delete[] tmp;
		}
		else
	    strcat_s(string, capacity, chain);
  }
	return *this;
}

const P2String& P2String::Prefix(const P2String& chain)
{
  if (chain.string != NULL && string != NULL)
	{
		uint size = strlen(string) + (strlen(chain.string) + 1);
		
		if (size > capacity)
		{
			char* tmp = new char[size];
			strcpy_s(tmp, size, string);
			string = new char[size];

			strcpy_s(string, size, chain.string);
			strcpy_s(chain.string, size, tmp);

            strcat_s(string, size, chain.string);
           
			delete[] tmp;
		}
		else
			strcat_s(string, capacity, chain.string);
	}

	return *this;
}