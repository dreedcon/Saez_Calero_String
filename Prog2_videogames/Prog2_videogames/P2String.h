#ifndef _STRING_
#define _STRING_

#define UINT unsigned int

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
	const char* _string()const;

	//operators
	bool operator == (const char*)const;
	bool operator != (const P2String&)const;

	/*


	P2String operator = (const P2String&);
	operador de asignacion->comprobar si hay memoria, si no hay suficiente para copiar tienes que crear una nueva
	*/

};


#endif


/*
propiedades de la clase cadena

private: no queremos que nadie nos toque el codigo
uint capacity; no puede ser nunca menor que cero
--->la capacidad no es el tama�o  de la cadena,puedo tener una de 2 y capacidad 9999
char* string;
--->queremos que sea privado para que nadie nos toca el tama�o eeee eso peta joder!!!

control de la memoria!!!!--->este es el paradigma memoria o no esa es la cuestion

constructor que le pasemos un puntero a la cadena char* string
constructor copia
constructor vacio
capacity
DESTRUCTOR

cuidado con los news y deletes

*/

