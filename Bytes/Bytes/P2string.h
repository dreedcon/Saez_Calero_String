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

*/
#ifndef _STRING_
#define _STRING

#define UINT unsigned  int

class P2String
{

private:
	
	char* string;
	UINT capacity;

public:
	
	//constructor vacio
	P2String(){ capacity = 0; string = NULL; }
	//constructor copia cadena
	P2String(const char*_string){};
	//constructor copia capacity
	P2String(UINT _capacity){ this->capacity = _capacity;}
	//constructor puntero a la cadena
	P2String(const P2String& _string){};
	
	//destructor
	~P2String(){};

	//operators
	
	bool operator==(const P2String&)const;
	bool operator = (const P2String&)const;

};

#endif


