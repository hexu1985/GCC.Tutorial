#include "mydynamiclibexports.h"

void no_such_function();

int first_function(int x)
{
    no_such_function();
	return (x+1);
}
