#include <iostream>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <float.h>
#include <string.h>

#include "Strcopy.h"
#include "Swap.h"
#include "Rectangle.h"
#include "Point2D.h"
#include "ClassCircle.h"
#include "memory_lick.h"
#include "constructors.h"
#include "P2string.h"



int main()
{
	char* prueba;
	P2String a;
	
	a = prueba;




	system("pause");

}








/*
int Byte = 0;
long bits = 0;
int exponente = 0;
int fchar, fshort , fint, flong, ffloat,a,b,c;
bool flag = true;

a = sizeof(void*);
b = sizeof(char*);
c = sizeof(double*);

printf("el valor en bytes del void* es: %i\n", a);
printf("el valor en bytes del char* es: %i\n", b);
printf("el valor en bytes del double* es: %i\n", c);

//////paso de bits a bytes\\\\\\\\\\\\\\\\

while (flag)
{
Byte = exponente / 7;
exponente++;

bits = pow(2, exponente);

if (bits - 1 == UCHAR_MAX)
{
fchar = Byte;
printf("el valor en bytes del char es: %d\n", fchar);
flag = false;
}
}


/////// SHORT \\\\\\\\\\\\\\

flag = true;
while (flag)
{

Byte = exponente / 7;
exponente++;

bits = pow(2, exponente);

if (bits - 1 == SHRT_MAX)
{

fshort = Byte;
printf("el valor en bytes del short es: %d\n", fshort);
flag = false;
}
}

/////// INT \\\\\\\\\\\\\\

flag = true;
while (flag)
{

Byte = exponente / 7;
exponente++;

bits = pow(2, exponente);

if (Byte == 4)
{

fint = Byte;
printf("el valor en bytes del  int es: %d\n", fint);
flag = false;
}
}

/////// LONG \\\\\\\\\\\\\\

flag = true;
while (flag)
{
Byte = exponente / 7;
exponente++;

bits = pow(2, exponente);

if (bits -1  == LONG_MAX)
{

flong = Byte;
printf("el valor en bytes del long es: %i\n", flong);
flag = false;
}
}


///////// FLOAT \\\\\\\\\\\

flag = true;
while (flag)
{
Byte = exponente / 7;
exponente++;

bits = pow(2, exponente);

if (Byte == 4)
{
ffloat = Byte;
printf("el valor en bytes del float es: %i\n", ffloat);
flag = false;
}
}

FUNCIONAMIENTO DE LA LIBRERIA LIMITS.H


printf("el numero de bits en un byte es: %d\n", CHAR_BIT);

printf("el numero minimo valor de un SIGNED CHAR es: %d\n", SCHAR_MIN);
printf("el numero minimo valor de un SIGNED CHAR es: %d\n", SCHAR_MAX);
printf("el numero minimo valor de un UNSIGNED CHAR es: %d\n", UCHAR_MAX);

printf("el numero minimo valor de un SHORT INT es: %d\n", SHRT_MIN);
printf("el numero minimo valor de un SHORT INT es: %d\n", SHRT_MAX);

printf("el valor minimo de un INT es: %d\n", INT_MIN);
printf("el valor maximo de un INT es: %d\n", INT_MAX);

printf("el minimo valor de un char es:  %d\n", CHAR_MIN);
printf("el maximo valor de un char es: %d\n", CHAR_MAX);

printf("el minimo valor en un long es: %ld\n", LONG_MIN);
printf("el maximo valor en un long es: %ld\n", LONG_MAX);


*/