#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"
#include "P2Linked_List.h"


float Factorial(int num)
{
	if (num > 1)
	{
		return num*Factorial(num - 1);
	}
	else
		return 1;
}




int main()
{   
	int a = 1;
 
	
	Factorial(5);
	
	
	
	/*

	
	Stack_list<int> prueba1;
	prueba1.Push(3);
	prueba1.Push(4);
	prueba1.Push(5);
	prueba1.Pop(a);

	Queue_list<int> prueba;
	prueba.Push(3);
	prueba.Push(4);
	prueba.Push(5);
	prueba.Pop(a);
	prueba.Pop(a);
	prueba.Pop(a);

	int a = 1;
	list<int> prueba;
	prueba.Push_back(3);
	prueba.Push_back(4);
	prueba.Push_back(5);
	prueba.push_front(2);

	prueba.remove(3);
	prueba.End();
	prueba.Insert(1, 4);
    prueba.Front();
	prueba.pop_back(a);
	prueba.pop_front(a);
	prueba.size();
	prueba.clear();
	

	prueba1.Insert(1, "x");
	prueba1.shink_to_fit();
	
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