#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "functions.h"
bool isAlphaNumericOrSpace(char c)
{
	return !((c < 48) || ((c > 57) && (c < 65)) || ((c > 90) && (c < 97)) || (c > 122));
}

void mutableToUpper(char* text)
{
	int i;
	int k = strlen(text);
	for (i = 0; i < k; i++)
	{
		text[i] = toupper(text[i]);
	}
}

void immutableToUpper(char* text, char* buf)
{
	int i;
	int k = strlen(text);
	for (i = 0; i < k; i++)
	{
		buf[i] = toupper(text[i]);
	}
	buf[k] = '\0';
}

void mutableToLower(char* text)
{
	int i;
	int k = strlen(text);
	for (i = 0; i < k; i++)
	{
		text[i] = tolower(text[i]);
	}
}

void immutableToLower(char* text, char* buf)
{
	int i;
	int k = strlen(text);
	for (i = 0; i < k; i++)
	{
		buf[i] = tolower(text[i]);
	}
}
void mutableFilter(char* text)
{
	int len = strlen(text);
	int delta = 0;
	bool shiftMode = false;

	for (int k = 0; k < len - delta; k++)
	{
		if (!isAlphaNumericOrSpace(text[k]) || (shiftMode == true))
		{
			if (!isAlphaNumericOrSpace(text[k]))
			{
				delta++;
			}
			shiftMode = true;
			text[k] = text[k + delta];
		}
	}
	text[len - delta] = '\0';
}

void  immutableFilter(char* text, char* buf)
{
	int len = strlen(text);
	int i = 0;

	for (int k = 0; k < len; k++)
	{
		if (isAlphaNumericOrSpace(text[k]))
		{
			buf[i] = text[k];
			i++;
		}
	}
	buf[i] = 0;
}


void mutableDeleteSpace(char* text)
{
	int len = strlen(text);
	int delta = 0;
	bool shiftMode = false;

	for (int k = 0; k < len - delta; k++)
	{
		if ((text[k] == 32) || (shiftMode == true))
		{
			if (text[k] == 32)
			{
				delta++;
			}
			shiftMode = true;
			text[k] = text[k + delta];
		}
	}
	text[len - delta] = '\0';
}

void immutableDeleteSpace(char* text, char* buf)
{
	int len = strlen(text);
	int i = 0;
	

	for (int k = 0; k < len; k++)
	{
		if (text[k] != 32)
		{
			buf[i] == text[i];
			i++;
		}
	}
	buf[i] = '\0';
}

void mutableTrim(char* text)
{
	int len = strlen(text);
	int deltaS = 0, deltaE = 0;
	int k = 0;

	while (text[k] == 32)
	{
		deltaS++;
		k++;
	}
	k = len - 1;
	while (text[k] == 32)
	{
		deltaE++;
		k--;
	}

	int endOfStringPos = len - deltaE - deltaS;
	for (int i = 0; i < endOfStringPos; i++)
	{
		text[i] = text[i + deltaS];
	}

	text[endOfStringPos] = 0;
}
void immutableTrim(char* text, char* buf)
{
	int len = strlen(text);
	int deltaS = 0, deltaE = 0;
	int k = 0;

	while (text[k] == 32)
	{
		deltaS++;
		k++;
	}
	k = len - 1;
	while (text[k] == 32)
	{
		deltaE++;
		k--;
	}

	int endOfStringPos = len - deltaE - deltaS;
	for (int i = 0; i < endOfStringPos; i++)
	{
		buf[i] = text[i + deltaS];
	}

	buf[endOfStringPos] = 0;
}

bool isNumber(char* text)
{
	int i = strlen(text);
	for (int k = 0; k < i; k++)
	{
		if ((text[k] < 48) || (text[k] > 57))
		{
			return false;
		}
	}
	return true;
}

bool isLetter(char* text)
{
	int i = strlen(text);
	for (int k = 0; k < i; k++)
	{
		if ((text[k] < 65) || ((text[k] > 90) && (text[k] < 97)) || (text[k] > 122))
		{
			return false;
		}
	}
	return true;
}

void mutableEncoderCesar(char* text, int step)
{
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		text[i] = text[i] + step;
	}
}

void immutableEncoderCesar(char* text, int step, char* buf)
{
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		buf[i] = text[i] + step;
	}
}

void mutableDecoderCesar(char* text, int step)
{
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		text[i] = text[i] - step;
	}
}

void immutableDecoderCesar(char* text, int step, char* buf)
{
	for (unsigned int i = 0; i < strlen(text); i++)
	{
		buf[i] = text[i] - step;
	}
}

void mutableEncoderXor(char* text, char* key)
{
	int len = strlen(key);
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		text[i] ^= key[keyindex];
	}
}

void immutableEncoderXor(char* text, char* key, char* buf)
{
	int len = strlen(key);
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		buf[i] = text[i] ^ key[keyindex];
	}
	buf[strlen(text)] = 0;
}

void mutableDecoderXor(char* text, char* key)
{
	int len = strlen(key);
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		text[i] ^= key[keyindex];
	}
}

void immutableDecoderXor(char* text, char* key, char* buf)
{
	int len = strlen(key);
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		buf[i] = text[i] ^ key[keyindex];
	}
	buf[strlen(text)] = 0;
}