#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"

int main()
{ 
	P2DynArray<char*> prueba(20);
	prueba.Pushback("hola");
	prueba[2];

	
	/*
	P2String prueba("hola");
	P2String prueba1("mundo");
	//const char* a = "mundo";
	//prueba += prueba1;
	prueba.Prefix(prueba1);
	//prueba1.Clear();
	//prueba.Empit();
	*/
	
}