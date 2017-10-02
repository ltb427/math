#include"Expression.h"

extern void saveVDigits(const char* str, char* result, U8 limit)
{
	char buffer[64];
	sprintf(buffer, "%%.%df", limit);
	double temp = atof(str);
	sprintf(result, buffer, temp);
}

extern void saveVDigits_pro(const char * str, char * result, const U8 number, const U8 limit)
{
	char buffer[64];
	sprintf(buffer, "%%%d.%df", number, limit);
	double temp = atof(str);
	sprintf(result, buffer, temp);
}

extern void getHexStr(const unsigned char * buffer, const U8 length, char * result)
{
	int j = 0;
	for (int i = 0; i < length; ++i)
	{
		j += sprintf(result + j, "%02X", buffer[i]);
	}
}

extern U8 getHex(const char * hexstr)
{
	
}

extern unsigned int getDec(const char* hexstr)
{
	unsigned int result;
	sscanf(hexstr, "%x", &result);
	return result;
}
