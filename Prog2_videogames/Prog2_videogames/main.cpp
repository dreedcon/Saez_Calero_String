#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"

int main()
{
	
	P2String prueba("hola");
	P2String prueba1("mundo");
	const char* a = "mundo";

	
	prueba += prueba1;
	
	
	prueba.Clear();
	prueba.Empit();
	
	
}