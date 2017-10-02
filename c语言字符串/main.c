#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int alter(const char*dest, char(*result)[256], const char* limit);
//cÓïÑÔ×Ö·û´®·Ö¸î
int alter(const char*dest, char(*result)[256],const char* limit)
{
	int length = strlen(limit);
	if (dest == NULL)
		return 0;
	const char* p = dest;
	const char* ptr = dest;
	int i = 0;
	while ((p = strstr(p, limit)) != NULL)
	{
		if (strcmp(dest, p) == 0)
		{
			p += length;
			ptr = p;
			continue;
		}	
		strncpy(result[i],ptr,p-ptr);	
		result[i][p - ptr ] = 0;
		p += length;
		ptr = p;
		++i;
	}
	if (strcmp(ptr, "") != 0)
	{
		strcpy(result[i], ptr);
		++i;
	}
	return i;
}

void main(void)
{
	const char* str = "now # is the time for all # good men to come to the # aid of their country";
	char result[16][256];
	int i=alter(str, result, "#");
	for (int j = 0; j < i; ++j)
		printf("result is \"%s\"\n", result[j]);
}