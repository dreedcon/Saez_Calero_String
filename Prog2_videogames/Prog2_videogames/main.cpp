#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"

int main()
{ 
	P2DynArray<char*> prueba(0);
	P2DynArray<char*> prueba1(2);
	prueba.Pushback("hola");
	prueba1.Pushback("mundo");
	prueba1.Pushback("alexis");

	prueba[0];
	prueba.shink_to_fit();
	prueba.Getcapacity();
	prueba.Flip();
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