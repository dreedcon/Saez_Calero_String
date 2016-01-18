#ifndef __p2String_H__
#define __p2String_H__

//#include <stdlib.h>
//#include <stdarg.h>
#include <string.h>
#include "p2Defs.h"

class p2String
{
public:

	// Constructors
	p2String()
	{
		Alloc(1);
		clear();
	}

	p2String(uint max_capacity)
	{
		Alloc(MAX(1,max_capacity));
		clear();
	}

	p2String(const p2String& string)
	{
		Alloc(string.length() + 1);
		strcpy_s(str, max_capacity, string.str);
	}

	p2String(const char *string)
	{
		if(string != nullptr)
		{
			Alloc(strlen(string) + 1);
			strcpy_s(str, max_capacity, string);
		}
		else
		{
			Alloc(1);
			clear();
		}
	}
	
	// Destructor
	 ~p2String()
	{
		RELEASE_ARRAY(str);
	}

	// Operators
	bool operator== (const p2String& string) const
	{
		return strcmp(string.str, str) == 0;
	}

	bool operator== (const char* string) const
	{
		if(string != nullptr)
			return strcmp(string, str) == 0;
		return false;
	}

	bool operator!= (const p2String& string) const
	{
		return strcmp(string.str, str) != 0;
	}

	bool operator!= (const char* string) const
	{
		if(string != nullptr)
			return strcmp(string, str) != 0;
		return true;
	}
	
	const p2String& operator= (const p2String& string)
	{
		if(string.length() + 1 > this->max_capacity)
		{
			RELEASE_ARRAY(str);
			Alloc(string.length() + 1);
		}

		strcpy_s(str, max_capacity, string.str);

		return(*this);
	}

	const p2String& operator= (const char* string)
	{
		if(string != nullptr)
		{
			if(strlen(string) + 1 > max_capacity)
			{
				RELEASE_ARRAY(str);
				Alloc(strlen(string)+1);
			}

			strcpy_s(str, max_capacity, string);
		}
		else
			clear();

		return(*this);
	}
	
	const p2String& operator+= (const p2String& string)
	{
		unsigned int need_max_capacity = string.length() + length() + 1;

		if(need_max_capacity > max_capacity)
		{
			char* tmp = str;
			Alloc(need_max_capacity);
			strcpy_s(str, max_capacity, tmp);
			RELEASE_ARRAY(tmp);
		}

		strcat_s(str, max_capacity, string.str);

		return(*this);
	}

	const p2String& operator+= (const char* string)
	{
		if(string != nullptr)
		{
			unsigned int need_max_capacity = strlen(string) + length() + 1;

			if(need_max_capacity > max_capacity)
			{
				char* tmp = str;
				Alloc(need_max_capacity);
				strcpy_s(str, max_capacity, tmp);
				RELEASE_ARRAY(tmp);
			}

			strcat_s(str, max_capacity, string);
		}

		return(*this);
	}

	// Utils
	uint length() const
	{
		return strlen(str);
	}

	uint size() const
	{
		return strlen(str);
	}

	bool empty() const
	{
		return strlen(str) == 0;
	}

	void clear()
	{
		str[0] = '\0';
	}

	const char* c_str() const
	{
		return str;
	}

	uint capacity() const
	{
		return max_capacity;
	}

private:

	void Alloc(unsigned int required_memory)
	{
		max_capacity = required_memory;
		str = new char[max_capacity];
	}

private:

	char* str;
	uint max_capacity;

};

#endif // __p2String_H__
/*
// memcpy example 
#include <stdio.h>
#include <string.h>

struct {
	char name[40];
	int age;
} person, person_copy;

int main()
{
	char myname[] = "Pierre de Fermat";

	// using memcpy to copy string: 
	memcpy(person.name, myname, strlen(myname) + 1);
	person.age = 46;

	// using memcpy to copy structure: 
	memcpy(&person_copy, &person, sizeof(person));

	printf("person_copy: %s, %d \n", person_copy.name, person_copy.age);

	return 0;
}

// memmove example 
#include <stdio.h>
#include <string.h>

int main()
{
	char str[] = "memmove can be very useful......";
	memmove(str + 20, str + 15, 11);
	puts(str);
	return 0;
}

// strcpy example 
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "Sample string";
	char str2[40];
	char str3[40];
	strcpy(str2, str1);
	strcpy(str3, "copy successful");
	printf("str1: %s\nstr2: %s\nstr3: %s\n", str1, str2, str3);
	return 0;
}

// strncpy example 
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[] = "To be or not to be";
	char str2[40];
	char str3[40];

	// copy to sized buffer (overflow safe): 
	strncpy(str2, str1, sizeof(str2));

	// partial copy (only 5 chars):
	strncpy(str3, str2, 5);
	str3[5] = '\0';   // null character manually added

	puts(str1);
	puts(str2);
	puts(str3);

	return 0;
}


// strcat example
#include <stdio.h>
#include <string.h>

int main()
{
	char str[80];
	strcpy(str, "these ");
	strcat(str, "strings ");
	strcat(str, "are ");
	strcat(str, "concatenated.");
	puts(str);
	return 0;
}

// strncat example
#include <stdio.h>
#include <string.h>

int main()
{
	char str1[20];
	char str2[20];
	strcpy(str1, "To be ");
	strcpy(str2, "or not to be");
	strncat(str1, str2, 6);
	puts(str1);
	return 0;
}

// memcmp example
#include <stdio.h>
#include <string.h>

int main()
{
	char buffer1[] = "DWgaOtP12df0";
	char buffer2[] = "DWGAOTP12DF0";

	int n;

	n = memcmp(buffer1, buffer2, sizeof(buffer1));

	if (n>0) printf("'%s' is greater than '%s'.\n", buffer1, buffer2);
	else if (n<0) printf("'%s' is less than '%s'.\n", buffer1, buffer2);
	else printf("'%s' is the same as '%s'.\n", buffer1, buffer2);

	return 0;
}

//strcmp
#include <stdio.h>
#include <string.h>

int main ()
{
char key[] = "apple";
char buffer[80];
do {
printf ("Guess my favorite fruit? ");
fflush (stdout);
scanf ("%79s",buffer);
} while (strcmp (key,buffer) != 0);
puts ("Correct answer!");
return 0;
}

// strncmp example 
#include <stdio.h>
#include <string.h>

int main()
{
	char str[][5] = { "R2D2", "C3PO", "R2A6" };
	int n;
	puts("Looking for R2 astromech droids...");
	for (n = 0; n<3; n++)
		if (strncmp(str[n], "R2xx", 2) == 0)
		{
			printf("found %s\n", str[n]);
		}
	return 0;
}

*/