#include"caculator.h"

void main(void)
{
	const char* str = "3+2/24*3";
	char buffer[64];
	getResult_s(str, buffer,2);
	printf("%s\n",buffer);
}