#include <iostream>
#include "RunAlgorithm.h"
int main()  
{
	RunAlgorithm r(1); //0 to manual insert, 1 to randomize numbers
	r.~r();
	_CrtDumpMemoryLeaks();
}
