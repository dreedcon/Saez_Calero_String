class Base
{
public:
	char* characters;
	
	//Base(){};
	Base(int i){ characters = new char[i];}
	virtual ~Base(){ delete[] characters;}
};

class Deriv : public Base
{
public:
	
	int* numbers;
	// Y TODO ESTO ES UN MEMORY LICK para evitarlo tendrias que hacer un destructor virtual, llama al destructor y la clase base no se borraria
	Deriv(int i):Base(i){ numbers = new int[i]; }
	~Deriv(){ delete[] numbers;}



};