#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "functions.h"

int main(int argc, char** argv)
{
	char method[20];
	char text[100];
	char key[10];

	if (argc == 1) 
	{
		scanf("%s %s %s", method, text, key);
	}
	else if (argc == 4)
	{
		strcpy(method, argv[1]);
		strcpy(text, argv[2]);
		strcpy(key, argv[3]);
	}
	else 
	{
		printf("Error\n");
		return 1;
	}

	mutableToLower(method);
	mutableTrim(text);
	mutableFilter(text);
	mutableToLower(text);

	if (strcmp(method, "-cesar") == 0) 
	{
		if (!isNumber(key)) 
		{
			printf("Key is not a number\n");
			return 11;
		}
		else if (!isLetter(text))
		{
			printf("Key is not a text\n");
			return 10;
		}
		else
		{
			mutableEncoderCesar(text, atoi(key));
		}
	}
	else if (strcmp(method, "-xor") == 0) 
	{
		mutableEncoderXor(text, key);
	}

	printf("%s\n", text);

	return 0;
}