#include "Teste.h"
#define _CRTDBG_MAP_ALLOC  
#include <stdlib.h>  
#include <crtdbg.h>  
int main() {
	{
		testOffer();
		testOffers();
		testService();
	}
	_CrtDumpMemoryLeaks();
	return 0;
}
