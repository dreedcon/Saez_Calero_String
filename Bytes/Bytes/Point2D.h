#include <iostream>



class Point_2D
{

private:
	int x;
	int y;

public:
	
	Point_2D setPoint()
	{
		x = 3;
		y = 3;
	
	}

	Point_2D operator +(const Point_2D& a)const
	{
		Point_2D tmp;

		tmp.x = a.x + x;
		tmp.y = a.y + y;

		return tmp;
	}

	Point_2D operator -(const Point_2D& a)const
	{
		Point_2D tmp;

		tmp.x = a.x - x;
		tmp.y = a.y - y;

		return tmp;
	}

	Point_2D operator +=(const Point_2D& a)
	{
		Point_2D tmp;

        x += tmp.x;
		y += tmp.y;

		return tmp;
	}

	Point_2D operator -=(const Point_2D& a)
	{
		Point_2D tmp;

		x += tmp.x;
		y += tmp.y;

		return tmp;
	}

	bool operator ==(Point_2D& a)const
	{
		Point_2D tmp;
		
		
		if (a.x == tmp.x && a.y == tmp.y)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator !=(Point_2D& a)const
	{
		Point_2D tmp;

		if (a.x != tmp.x && a.y != tmp.y)
		{
			return true;
		}
		else
		{
			return false;
		}

	}


};