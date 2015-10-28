
class Forma
{
public:
	int altura;
	int base;
	virtual float getarea() const = 0;
	
};

class Rectangle : public Forma
{
public:
    
	float getarea()const
	{
		
		float area1 = altura * base;
		return area1;
	}

};

class Triangle : public Forma
{
public:
	
	float getarea()const
	{
		
		float area2 = (base*altura) / 2;
		return area2;
	}
	
};
