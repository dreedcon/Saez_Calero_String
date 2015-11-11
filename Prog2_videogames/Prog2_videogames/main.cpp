#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"

int main()
{ 
	P2DynArray<char*> prueba(0);
	P2DynArray<char*> prueba1(4);
	prueba.Pushback("hola");
	prueba1.Pushback("a");
	prueba1.Pushback("b");
	prueba1.Pushback("c");
	prueba1.Pushback("d");
	prueba1.Pushback("d");
	//prueba1.Insert(1, "x");
	//prueba1.shink_to_fit();
	/*
	P2String prueba("hola");
	P2String prueba1("mundo");
	//const char* a = "mundo";
	//prueba += prueba1;
	prueba.Prefix(prueba1);
	//prueba1.Clear();
	//prueba.Empit();
	*/
	//system("pause");
}