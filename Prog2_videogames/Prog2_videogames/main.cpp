#include <iostream>
#include "P2string.h"
#include "P2DynArray.h"
#include "P2Linked_List.h"
#include "P2Graph.h"
#include "P2List_double.h"
#include "P2Point.h"
float Factorial(int num)
{
	if (num > 1)
	{
		return num*Factorial(num - 1);
	}
	else
		return 1;
}


uint done = 0;
uint failed = 0;

#define TEST(msg, test) done++; printf("\t%s\t%s\n", !(##test) ? failed++,"FAIL" : "OK", msg)


int main()
{   


	// DynArray -------------------
	{
		printf("Testing DynArray ...\n");
		P2DynArray<int> container;
		("Empty constructor", container.Getcapacity() == BLOCK);
		P2DynArray<int> container1(5);
		TEST("Capacity constructor", container1.Getcapacity() == 5);
		container.Pushback(1);
		container.Pushback(2);
		container.Pushback(3);
		TEST("Push Back", container[2] == 3 && container.Size() == 3);
		TEST("Front", *(container.Front()) == 1);
		TEST("Back", *(container.Back()) == 3);
		TEST("Empty", container.Empty() == false);
		int d;
		container.Popback(d);
		container.Popback(d);
		container.Popback(d);
		TEST("Pop Back", d == 1 && container.Popback(d) == false);
	}

	// List -------------------
	{
		printf("Testing Double Linked List ...\n");
		List_double<int> container;
		container.Push_back(1);
		container.Push_back(2);
		container.Push_back(3);
		TEST("Push Back", container.Size() == 3);
		TEST("Front", (container.Front()) == 1);
		TEST("Back", (container.End()) == 3);
		TEST("Empty", container.Empty() == false);
		int d;
		container.Pop_back(d);
		container.Pop_back(d);
		container.Pop_back(d);
		TEST("Pop Back", d == 1 && container.Pop_back(d) == false);
	}

	// Single List -------------------
	{
		printf("Testing Single Linked List ...\n");
		List<int> container;
		container.Push_back(1);
		container.Push_back(2);
		container.Push_back(3);
		TEST("Push Back", container.size() == 3);
		TEST("Front", (container.Front()) == 1);
		TEST("Back", (container.End()) == 3);
		TEST("Empty", container.Empty() == false);
		int d;
		container.pop_back(d);
		container.pop_back(d);
		container.pop_back(d);
		TEST("Pop Back", d == 1 && container.pop_back(d) == false);
	}

	// Queue List -------------------
	{
		printf("Testing Queue implemented with Single Linked List ...\n");
		Queue_list<int> container;
		container.Push(1);
		container.Push(2);
		container.Push(3);
		TEST("Push", container.Size() == 3);
		TEST("Empty", container.Empty() == false);
		TEST("Peek", (container.Peek()) == 1);
		int d;
		container.Pop(d);
		container.Pop(d);
		container.Pop(d);
		TEST("Pop", d == 3 && container.Pop(d) == false);
	}

	// Stack DynArray -------------------
	{
		printf("Testing Stack implemented with SIngle Dyn Array ...\n");
		Stack_Arry<int> container;
		container.Push(1);
		container.Push(2);
		container.Push(3);
		TEST("Push", container.Size() == 3);
		TEST("Empty", container.Empty() == false);
		TEST("Peek", *(container.Peek()) == 1);
		int d;
		container.Pop(d);
		container.Pop(d);
		container.Pop(d);
		TEST("Pop", d == 1 && container.Pop(d) == false);
	}
	
	
	// String -------------------
	{
		printf("Testing String ...\n");
		P2String str;
		TEST("Empty Constructor", str.GetCapacity() == 1 && str.size() == 0);
		P2String str1(25);
		TEST("Capacity Constructor", str1.GetCapacity() == 25 && str1.size() == 0);
		P2String str2("hello world");
		TEST("C String Constructor", str2.GetCapacity() == 12 && str2.size() == 11);
		TEST("Operator == string", !(str2 == str1));
		TEST("Operator == c string", str2 == "hello world");
		str1 = str2;
		TEST("Operator = string", str1 == "hello world");
		str2 = "bye world";
		TEST("Operator = c string", str2 == "bye world");
		str2.Prefix(" test");
		TEST("Operator += c string", str2 == "bye world test");
	}
	
	
	// Point -------------------
	{
		printf("Testing Point ...\n");
	    iPoint a(2, 2);
	    iPoint b = a + a;

		TEST("Operator + Point", b == iPoint(4, 4));
		TEST("Operator -= Point", (b -= a) == iPoint(2, 2));
		TEST("Distance", iPoint(2, 2).DistanceTo(iPoint(2, 5)) == 3);
	}
	
	

	
	// Graph -------------------
	{
		printf("Testing Graph ...\n");
		Graph<int> container;
		TEST("Empty", container.Empty() == true);
		Graph<int>::vertice* vertice_1 = container.Push_back(1);
		Graph<int>::vertice* vertice_2 = container.Push_back(2);
		Graph<int>::vertice* vertice_3 = container.Push_back(3);
		TEST("Push Back", container.Size() == 3);
		vertice_1->links.push_back(vertice_2);
		vertice_2->links.push_back(vertice_3);
		vertice_3->links.push_back(vertice_3); // loop
		vertice_3->links.push_back(vertice_2);
		TEST("Push Back", container.Size() == 3);
		TEST("is_reachable_iterative A", container.Is_reachable_iterative(vertice_1, vertice_3) == true);
		TEST("is_reachable_iterative B", container.Is_reachable_iterative(vertice_3, vertice_1) == false);
		TEST("is_reachable_recursive A", container.Is_reachable_recursive(vertice_2, vertice_3) == true);
		TEST("is_reachable_recursive B", container.Is_reachable_recursive(vertice_3, vertice_1) == false);
		container.Clear();
		TEST("Clear", container.Empty() == true);
	}
	

	printf("\nFailures: %d/%d", failed, done);




	getchar();
	return 0;
	


/*



   //String----------------------------------------------------------------------------
   P2String prueba("hola");
   P2String prueba1("mundo



   const char* a = "mundo";
   prueba.Prefix(prueba1);
   prueba.Clear();
   prueba.Empit();


     
    //Graph-----------------------------------------------------------------------------
   
	int a = 1;

    Graph<int> prueba;
	Graph<int>::vertice* node1 = prueba.Push_back(1);
	Graph<int>::vertice* node2 = prueba.Push_back(2);
	Graph<int>::vertice* node3 = prueba.Push_back(3);
	//nodo 1
	node1->links.Push_back(node2);
	node1->links.Push_back(node1);//loop
	//nodo 2
	node2->links.Push_back(node3);

	//nodo 3
	node3->links.Push_back(node1);
	node3->links.Push_back(node2);

	//comprobadores de links
	prueba.Is_reachable_iterative(node3, node2);
	prueba.Size();
	prueba.Clear();
	prueba.Empty();

	//Stack_list------------------------------------------------------------------------- 
	Stack_list<int> prueba1;
	prueba1.Push(3);
	prueba1.Push(4);
	prueba1.Push(5);
	prueba1.Pop(a);


	//Queue_list-------------------------------------------------------------------------
	Queue_list<int> prueba;
	prueba.Push(3);
	prueba.Push(4);
	prueba.Push(5);
	prueba.Pop(a);
	prueba.Pop(a);
	prueba.Pop(a);

	//single_list------------------------------------------------------------------------
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
	
	//DynArray----------------------------------------------------------------------------
	P2DynArray<char*> prueba(0);
	P2DynArray<char*> prueba1(4);
	prueba.Pushback("hola");
	prueba1.Pushback("a");
	prueba1.Pushback("b");
	prueba1.Pushback("c");
	prueba1.Pushback("d");
	prueba1.Pushback("d");

	prueba1.Insert(1, "x");
	prueba1.shink_to_fit();


	
	//List_double-------------------------------------------------------------------------
	int a = 1;
	List_double<int> prueba;
	prueba.Push_back(3);
	prueba.Push_back(4);
	prueba.Push_back(5);
	prueba.Push_front(2);
	prueba.Insert(1,3);
	prueba.Remove(3);

	*/

 }