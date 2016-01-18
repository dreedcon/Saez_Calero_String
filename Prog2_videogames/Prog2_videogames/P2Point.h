#ifndef _P2POINT_H_
#define _P2POINT_H_

#include "Utilities.h"
#include <math.h>

template<class VAR>
class p2Point
{
public:
	
	VAR x, y;
	
	//constructores
	
	p2Point(){}
	
	//constructor copia
	p2Point(const p2Point& v)
	{
		this->x = v.x;
		this->y = v.y;
	}
	
	//constructor asignacion
	p2Point(const VAR& x, const VAR y)
	{
		this->x = x;
		this->y = y;
	}

	
	p2Point& create(const VAR& x, const VAR& y)
	{
		this->x = x;
		this->y = y;

		return (*this);
	}

	//math operators
	p2Point operator +(const p2Point& v)const
	{
		p2Point r;
		
		r.x = x + v.x;
		r.y = y + v.y;

		return (r);
	}

	p2Point operator -(const p2Point& v)const
	{
	   
		p2Point r;
		
		r.x = x - v.x;
		r.y = y - v.y;

		return (r);
    }

	const p2Point operator +=(const p2Point& v)
	{
		x += v.x;
		y += v.y;

		return (*this);
	}

	const p2Point operator -=(const p2Point& v)
	{
		x -= v.x;
		y -= v.y;

		return(*this);
	}

	bool operator ==(const p2Point& v)const
	{
		return(x == v.x && y == v.y);
	
	}

	bool operator != (const p2Point& v)const
	{
		return(x != v.x || y != v.y)
	}

	//utilities
	bool IsZero() const
	{
		return (x == 0 && y == 0);
	}

	p2Point& SetZero()
	{
		x = 0;
		y = 0;

		return (*this);
	}

	p2Point& Negate()
	{
		x = -x;
		y = -y;

		return(*this);
	}

	//Distances
	VAR DistanceTo(const p2Point& v)const
	{

		VAR fx = x - v.x;
		VAR fy = y - v.y;

		return  sqrt(VAR(fx*fx) + VAR(fy*fy));

		
    }

	VAR Distancenoqrt(const p2Point& v)const
	{
		VAR fx = x - v.x;
		VAR fy = y - v.y;

		return ((fx*fx) + (fy*fy));
	}


};

typedef p2Point<int> iPoint;
typedef p2Point<float> fPoint;


#endif