#include "ClassCircle.h"







   Circle Circle::operator+(const Circle& a)const
	{
		Circle tmp;

		tmp.r = r + a.r;

		return tmp;
	}

	Circle Circle::operator-(const Circle& a)const
	{
		Circle tmp;

		tmp.r = r - a.r;

		return tmp;
	}

	Circle Circle::operator= (const Circle& a)
	{
		

		r = a.r;

		return* this;
	}

	bool Circle:: operator == (const Circle& a)const
	{
		if (r == a.r)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool Circle:: operator !=(const Circle& a)const
	{
		

		if (r != a.r)
		{
			return true;
		}
		else
		{
			return false;
		}

	}

	const Circle Circle::operator+=(const Circle& a)
	{
		
        r += a.r;
        
		return* this;
	}

	const Circle Circle::operator-=(const Circle& a)
	{
		
        r -= a.r;

	    return* this;
	}

	float Circle::getArea()const
	{
		float area;

		area = 3.14f * (r*r);
		
		return area;
	}

