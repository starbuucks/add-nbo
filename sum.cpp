#include "sum.h"

uint32_t sum(uint32_t a, uint32_t b, uint8_t* overflow){
	
	uint32_t result;

	result = a + b;
	if(result < a) *overflow = 1;
	else *overflow = 0;

	return result;
}
