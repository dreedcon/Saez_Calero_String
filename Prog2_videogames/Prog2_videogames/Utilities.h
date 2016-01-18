#ifndef _UTILITIES_
#define _UTILITIES_
#include <assert.h>

#define NULL 0
#define MIN(a,b)  ((a)<(b)) ? a : b
#define MAX(a,b)  ((a)>(b)) ? a : b

// Deletes a buffer
#define RELEASE( x ) \
	    {                        \
    if( x != nullptr )        \
		    {                      \
      delete x;            \
	  x = nullptr;              \
		    }                      \
	    }


// Deletes an array of buffers
#define RELEASE_ARRAY( x ) \
	    {                              \
    if( x != nullptr )              \
		    {                            \
      delete[] x;                \
	  x = nullptr;                    \
		    }                            \
                              \
	    }


typedef unsigned int uint;

#endif