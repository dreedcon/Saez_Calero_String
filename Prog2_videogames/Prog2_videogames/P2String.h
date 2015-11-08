#include "Utilities.h"


#ifndef _STRING_
#define _STRING_



class P2String
{

private:

    char* string;
	UINT capacity;

public:

	//constructor vacio
	P2String();
	//constructor copia cadena
	P2String(const char*);
	//constructor copia capacity
	P2String(UINT capacity);
	//constructor puntero a la cadena
	P2String(const P2String&);

	//destructor
	~P2String();

	//getters
	UINT GetSize(const char*)const;
	const char* C_str()const;
   
	UINT length(const char*)const;
	UINT length(const P2String&)const;
	
	//operators
	bool operator == (const char*)const;
	bool operator == (const P2String&)const;

	bool operator != (const char*)const;
	bool operator != (const P2String&)const;
	
	const P2String operator = (const char*);
	const P2String operator = (const P2String&);
	
	const P2String operator +=(const P2String&);
	const P2String operator +=(const char*);

	//utility functions
	const void Clear()const;
	bool Empit()const;

	const P2String Prefix(const char*);
	const P2String Prefix(const P2String&);
		

};


#endif


/*
propiedades de la clase cadena

private: no queremos que nadie nos toque el codigo
uint capacity; no puede ser nunca menor que cero
--->la capacidad no es el tamaño  de la cadena,puedo tener una de 2 y capacidad 9999
char* string;
--->queremos que sea privado para que nadie nos toca el tamaño eeee eso peta joder!!!

control de la memoria!!!!--->este es el paradigma memoria o no esa es la cuestion

constructor que le pasemos un puntero a la cadena char* string
constructor copia
constructor vacio
capacity
DESTRUCTOR

cuidado con los news y deletes

empit()si la cadena esta vacia o no
clear() deja la cadena vacia
prefix()hace lo mismo que el += pero al principio
c_str()
length()


*/

