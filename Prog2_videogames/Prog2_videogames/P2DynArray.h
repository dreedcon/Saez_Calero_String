#ifndef _DYNARRAY_H_
#define _DYNARRAY_H_
#include "Utilities.h"

#define BLOCK 32

template<class VAR>
class P2DynArray
{

private:
	
	uint mem_capacity = 0;
	uint num_elements = 0;
	VAR* data = NULL;

public:
	//constructor vacio
	P2DynArray() : mem_capacity(BLOCK)
	{
		data = new VAR[BLOCK];
	}

	//constructor copia
	P2DynArray(const P2DynArray& _array) :num_elements(_array.num_elements)
	{
		mem_capacity = MAX(BLOCK, _arry.elements);
		data = new VAR[mem_capacity];
		memccpy(_array, _array.data, _array.num_elements * sizeof(VAR));
	}
	
	//constructor reserva de memoria 
	P2DynArray(uint new_capacity)
	{
		if (mem_capacity < new_capacity)
		{
         mem_capacity = new_capacity;
		}
		data = new VAR[mem_capacity];
	}

	//destructor
	~P2DynArray()
	{
		if (mem_capacity != NULL)
			delete[] data;
	}

	
	//utility metodes\\

	uint Getcapacity()const
	{
		return mem_capacity;
	}
    
	uint Size() const
	{
		return num_elements;
	}

    const P2DynArray* C_str()const
	{
	    return data;
	}
	
	//operators

	const VAR& operator[](uint position)
	{
		
		assert(position < num_elements);
		return data[position];

	}

	const P2DynArray& operator=(const P2DynArray& _array)
	{
		if (_array.num_elements > mem_capacity)
		{
			delete[] data;
			mem_capacity = _array.mem_capacity;
			data = new VAR[mem_capacity];

			memcpy(data, _array.data, num_elements*sizeof(VAR));
		}
		else
		memcpy(data, _array.data, num_elements*sizeof(VAR));

		return *this;
	
	}

     //metodes\\
	
	//Pushback() le metemos un elemento detras 
	void Pushback(const VAR& _array)
	{
		if (num_elements == mem_capacity)
		{
			VAR* tmp = data;
			data = new VAR[mem_capacity + BLOCK];
			memcpy(data, tmp, num_elements*sizeof(VAR));
			delete[] tmp;
		}
		data[num_elements++] = _array;
	}
	
	//At() le damos una posicion y nos dice que hay
	VAR& At(uint position)
	{
		if (position >= num_elements)
			printf("out of order \n");
		else
			return data[position];

	}

	//Popback() devuelve el ultimo elemento y lo borra
	bool Popback(VAR& _array)
	{
		if (num_elements == 0)
			return false;
		else
		_array = num_elements;
		num_elements--;
		return _array;
	}
	
	//si sobra memoria ha de asegurarnos que esa memoria se borra
	void shink_to_fit()
	{
		if (num_elements == mem_capacity)
		{
			printf("already are equal\n");
		}
		else
		{
			VAR* tmp = data;
			mem_capacity = (num_elements - 1)*sizeof(VAR);
			data = new VAR[mem_capacity];
			memcpy(data, tmp, num_elements*sizeof(VAR));
			delete[] tmp;
		}

    }

	//
	uint find(const VAR& _array)
	{
		uint i = 0;
		while ( i < num_elements)
		{
			
			if (data[i] == _array)
			{
				break;
			}
			
			i++;
			
			return i;
		}
		

	}
    
	//le pasas una posicion y le insertas algo
	void Insert(const uint& pos, const VAR& _array)
	{
		num_elements++;
		VAR* tmp = data;

		if (mem_capacity < num_elements)
		{
			data = new VAR[num_elements];
			mem_capacity++;
			memcpy(data, tmp, (pos)*sizeof(VAR));
			for (uint i = num_elements; i>position; i--)
			{
				data[i] = tmp[i - 1];
			}
			delete[] tmp;
		}
		else
		{
			for (uint i = num_elements; i > pos; --i)
			{
				data[i] = data[i - 1];
			}
			data[pos] = _array;
			num_elements++;
		}
	}
    
	//sort------------------------------------------------------- ordenation metodes-------------------------------------------
	bool BubbleSort(const P2DynArray& _array)
	{
		int flag = 1;
		VAR tmp;
        int length = _array.Size();
		if (_array.num_elements == NULL)
		{
			return false;
		}
		else
		{
			for (int i = 1; (i <= length) && flag; i++)
			{
				flag = 0;
				for (int j = 0; j < (length - 1); j++)
				{
					if (_array.data[j + 1] < _array.data[j])
					{
						tmp = _array.data[j];
						_array.data[j] = _array.data[j + 1];
						_array.data[j + 1] = tmp;
						flag = 1;
						return true;
					}
				}
			}
		
		}


	}

	//Devuelve una referencia al primer elemento del dinarray, puede ser tambien sin const
	const VAR* Front()const
	{
		if (num_elements > 0)
		{
			return &(data[0]);
		}
		
		return NULL;
	}

	//devuelve una referencia constante al ultimo elmento del dynarray
	const VAR* Back()const 
	{
		if (num_elements > 0)
		{
			return &data[num_elements - 1];
		}
		return nullptr;
	}

	
	//limpias el dynarray
    void Clear()
		{
			num_elements = 0;
		}

	//comprueba si esta vacio el dynarray
	bool Empty()const
		{
			return num_elements == 0;
		}

	
};

template<class VAR>
class Stack_Arry
{

private:
	
	P2DynArray<VAR> new_dynarray;

public:

	void Push(const VAR& new_data)
	{
		new_dynarray.Pushback(new_data);
	}
    
	int Size()
	{
		return new_dynarray.Size();
	}

	const VAR* Peek()
	{
		return new_dynarray.Front();
	}

	bool Empty()const 
	{
		return new_dynarray.Empty();
	}

	bool Pop(VAR& new_data)
	{
		return new_dynarray.Popback(new_data);
	}

};

#endif

/*

//constructors vector
#include <iostream>
#include <vector>

int main ()
{
// constructors used in the same order as described above:
std::vector<int> first;                                // empty vector of ints
std::vector<int> second (4,100);                       // four ints with value 100
std::vector<int> third (second.begin(),second.end());  // iterating through second
std::vector<int> fourth (third);                       // a copy of third

// the iterator constructor can also be used to construct from arrays:
int myints[] = {16,2,77,29};
std::vector<int> fifth (myints, myints + sizeof(myints) / sizeof(int) );

std::cout << "The contents of fifth are:";
for (std::vector<int>::iterator it = fifth.begin(); it != fifth.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';

return 0;
}

// vector assign, operador igual Asignar contenido (función miembro pública)
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> first;
std::vector<int> second;
std::vector<int> third;

first.assign (7,100);             // 7 ints with a value of 100

std::vector<int>::iterator it;
it=first.begin()+1;

second.assign (it,first.end()-1); // the 5 central values of first

int myints[] = {1776,7,4};
third.assign (myints,myints+3);   // assigning from array.

std::cout << "Size of first: " << int (first.size()) << '\n';
std::cout << "Size of second: " << int (second.size()) << '\n';
std::cout << "Size of third: " << int (third.size()) << '\n';
return 0;
}

//begin Return iterator to beginning (public member function )

// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
for (int i=1; i<=5; i++) myvector.push_back(i);

std::cout << "myvector contains:";
for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';

return 0;
}

//end Return iterator to end (public member function )
// vector::begin/end
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
for (int i=1; i<=5; i++) myvector.push_back(i);

std::cout << "myvector contains:";
for (std::vector<int>::iterator it = myvector.begin() ; it != myvector.end(); ++it)
std::cout << ' ' << *it;
std::cout << '\n';

return 0;
}

//size Return size (public member function )
// vector::size
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myints;
std::cout << "0. size: " << myints.size() << '\n';

for (int i=0; i<10; i++) myints.push_back(i);
std::cout << "1. size: " << myints.size() << '\n';

myints.insert (myints.end(),10,100);
std::cout << "2. size: " << myints.size() << '\n';

myints.pop_back();
std::cout << "3. size: " << myints.size() << '\n';

return 0;
}

//max_size Return maximum size (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

// set some content in the vector:
for (int i=0; i<100; i++) myvector.push_back(i);

std::cout << "size: " << myvector.size() << "\n";
std::cout << "capacity: " << myvector.capacity() << "\n";
std::cout << "max_size: " << myvector.max_size() << "\n";
return 0;
}

//resize Change size (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

// set some initial content:
for (int i=1;i<10;i++) myvector.push_back(i);

myvector.resize(5);
myvector.resize(8,100);
myvector.resize(12);

std::cout << "myvector contains:";
for (int i=0;i<myvector.size();i++)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}

//capacity Return size of allocated storage capacity (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

// set some content in the vector:
for (int i=0; i<100; i++) myvector.push_back(i);

std::cout << "size: " << (int) myvector.size() << '\n';
std::cout << "capacity: " << (int) myvector.capacity() << '\n';
std::cout << "max_size: " << (int) myvector.max_size() << '\n';
return 0;
}

//empty Test whether vector is empty (public member function )
include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
int sum (0);

for (int i=1;i<=10;i++) myvector.push_back(i);

while (!myvector.empty())
{
sum += myvector.back();
myvector.pop_back();
}

std::cout << "total: " << sum << '\n';

return 0;
}

//reserve Request a change in capacity (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int>::size_type sz;

std::vector<int> foo;
sz = foo.capacity();
std::cout << "making foo grow:\n";
for (int i=0; i<100; ++i) {
foo.push_back(i);
if (sz!=foo.capacity()) {
sz = foo.capacity();
std::cout << "capacity changed: " << sz << '\n';
}
}

std::vector<int> bar;
sz = bar.capacity();
bar.reserve(100);   // this is the only difference with foo above
std::cout << "making bar grow:\n";
for (int i=0; i<100; ++i) {
bar.push_back(i);
if (sz!=bar.capacity()) {
sz = bar.capacity();
std::cout << "capacity changed: " << sz << '\n';
}
}
return 0;
}

//Shrink to fit (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector (100);
std::cout << "1. capacity of myvector: " << myvector.capacity() << '\n';

myvector.resize(10);
std::cout << "2. capacity of myvector: " << myvector.capacity() << '\n';

myvector.shrink_to_fit();
std::cout << "3. capacity of myvector: " << myvector.capacity() << '\n';

return 0;
}

//operator[] Access element (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector (10);   // 10 zero-initialized elements

std::vector<int>::size_type sz = myvector.size();

// assign some values:
for (unsigned i=0; i<sz; i++) myvector[i]=i;

// reverse vector using operator[]:
for (unsigned i=0; i<sz/2; i++)
{
int temp;
temp = myvector[sz-1-i];
myvector[sz-1-i]=myvector[i];
myvector[i]=temp;
}

std::cout << "myvector contains:";
for (unsigned i=0; i<sz; i++)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}


//at Access element (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector (10);   // 10 zero-initialized ints

// assign some values:
for (unsigned i=0; i<myvector.size(); i++)
myvector.at(i)=i;

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size(); i++)
std::cout << ' ' << myvector.at(i);
std::cout << '\n';

//front Access first element (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

myvector.push_back(78);
myvector.push_back(16);

// now front equals 78, and back 16

myvector.front() -= myvector.back();

std::cout << "myvector.front() is now " << myvector.front() << '\n';

return 0;
}

// vector::back
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

myvector.push_back(10);

while (myvector.back() != 0)
{
myvector.push_back ( myvector.back() -1 );
}

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size() ; i++)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}

// vector::data
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector (5);

int* p = myvector.data();

*p = 10;
++p;
*p = 20;
p[2] = 100;

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size(); ++i)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}

//Assign vector content (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> first;
std::vector<int> second;
std::vector<int> third;

first.assign (7,100);             // 7 ints with a value of 100

std::vector<int>::iterator it;
it=first.begin()+1;

second.assign (it,first.end()-1); // the 5 central values of first

int myints[] = {1776,7,4};
third.assign (myints,myints+3);   // assigning from array.

std::cout << "Size of first: " << int (first.size()) << '\n';
std::cout << "Size of second: " << int (second.size()) << '\n';
std::cout << "Size of third: " << int (third.size()) << '\n';
return 0;
}

//push_back Add element at the end (public member function )
include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
int myint;

std::cout << "Please enter some integers (enter 0 to end):\n";

do {
std::cin >> myint;
myvector.push_back (myint);
} while (myint);

std::cout << "myvector stores " << int(myvector.size()) << " numbers.\n";

return 0;
}

//pop_back Delete last element (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
int sum (0);
myvector.push_back (100);
myvector.push_back (200);
myvector.push_back (300);

while (!myvector.empty())
{
sum+=myvector.back();
myvector.pop_back();
}

std::cout << "The elements of myvector add up to " << sum << '\n';

return 0;
}

//insert 
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector (3,100);
std::vector<int>::iterator it;

it = myvector.begin();
it = myvector.insert ( it , 200 );

myvector.insert (it,2,300);

// "it" no longer valid, get a new one:
it = myvector.begin();

std::vector<int> anothervector (2,400);
myvector.insert (it+2,anothervector.begin(),anothervector.end());

int myarray [] = { 501,502,503 };
myvector.insert (myvector.begin(), myarray, myarray+3);

std::cout << "myvector contains:";
for (it=myvector.begin(); it<myvector.end(); it++)
std::cout << ' ' << *it;
std::cout << '\n';

return 0;
}

//erase
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;

// set some values (from 1 to 10)
for (int i=1; i<=10; i++) myvector.push_back(i);

// erase the 6th element
myvector.erase (myvector.begin()+5);

// erase the first 3 elements:
myvector.erase (myvector.begin(),myvector.begin()+3);

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size(); ++i)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}

//swap
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> foo (3,100);   // three ints with a value of 100
std::vector<int> bar (5,200);   // five ints with a value of 200

foo.swap(bar);

std::cout << "foo contains:";
for (unsigned i=0; i<foo.size(); i++)
std::cout << ' ' << foo[i];
std::cout << '\n';

std::cout << "bar contains:";
for (unsigned i=0; i<bar.size(); i++)
std::cout << ' ' << bar[i];
std::cout << '\n';

return 0;
}

//clear 
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector;
myvector.push_back (100);
myvector.push_back (200);
myvector.push_back (300);

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size(); i++)
std::cout << ' ' << myvector[i];
std::cout << '\n';

myvector.clear();
myvector.push_back (1101);
myvector.push_back (2202);

std::cout << "myvector contains:";
for (unsigned i=0; i<myvector.size(); i++)
std::cout << ' ' << myvector[i];
std::cout << '\n';

return 0;
}

//emplace Construct and insert element (public member function )
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector = {10,20,30};

auto it = myvector.emplace ( myvector.begin()+1, 100 );
myvector.emplace ( it, 200 );
myvector.emplace ( myvector.end(), 300 );

std::cout << "myvector contains:";
for (auto& x: myvector)
std::cout << ' ' << x;
std::cout << '\n';

return 0;
}

//emplace back
#include <iostream>
#include <vector>

int main ()
{
std::vector<int> myvector = {10,20,30};

myvector.emplace_back (100);
myvector.emplace_back (200);

std::cout << "myvector contains:";
for (auto& x: myvector)
std::cout << ' ' << x;
std::cout << '\n';

return 0;
}





*/
