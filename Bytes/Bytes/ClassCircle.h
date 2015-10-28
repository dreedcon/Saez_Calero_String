
class Circle
{

private:
	
	int r=3;

public:
	
	Circle(){};
	~Circle(){};

	Circle operator+(const Circle& a)const;
	Circle operator-(const Circle& a)const;
	Circle operator=(const Circle& a);
    bool operator==(const Circle& a)const;
	bool operator!=(const Circle& a)const;
	const Circle operator+=(const Circle& a);
	const Circle operator-=(const Circle& a);
	
	float getArea() const;


};





















