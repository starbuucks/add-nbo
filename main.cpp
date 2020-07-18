#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <arpa/inet.h>
#include "sum.h"

void usage(char* name){
	printf("usage : %s file1 file2\n", name);
}

uint32_t readfile(char* filename){

	FILE *fd;
	char buf[8] = {0,};
	uint32_t num;

	fd = fopen(filename, "r");
	fread(buf, sizeof(uint32_t), 1, fd);
	num = *(uint32_t*)buf;

	return ntohl(num);
}

int main(int argc, char* argv[]){
	
	if (argc != 3){
		usage(argv[0]);
		return 1;
	}
	uint32_t a, b;
	uint32_t result;
	uint8_t overflow;
	FILE * fd;

	a = readfile(argv[1]);
	b = readfile(argv[2]);

	printf("%08X + %08X = ", a, b);

	result = sum(a, b, &overflow);

	if(overflow)
		printf("1");
	
	printf("%08X\n", result);
	
}
