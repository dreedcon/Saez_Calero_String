#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"
#include "P2Linked_List.h"


int main()
{
	int a = 1;
	list<int> prueba;
	prueba.Pushback(3);
	prueba.Pushback(4);
	prueba.Pushback(5);
	prueba.push_front(2);
	
	
	//prueba.End();
	//prueba.Front();
	//prueba.pop_back(a);
	//prueba.pop_front(a);
	//prueba.size();
	//prueba.clear();
	

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

	P2DynArray<char*> prueba(0);
	P2DynArray<char*> prueba1(4);
	prueba.Pushback("hola");
	prueba1.Pushback("a");
	prueba1.Pushback("b");
	prueba1.Pushback("c");
	prueba1.Pushback("d");
	prueba1.Pushback("d");

	*/
	system("pause");

}