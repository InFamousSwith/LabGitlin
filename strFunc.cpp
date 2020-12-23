#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "strFunc.h"
bool isAlphaNumericOrSpace(char c)
{
	return !((c < 48) || ((c > 57) && (c < 65)) || ((c > 90) && (c < 97)) || (c > 122));
}

void mutableToUpper(char* text, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		text[i] = toupper(text[i]);
	}
}

void immutableToUpper(char* text, char* buf, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		buf[i] = toupper(text[i]);
	}
	buf[len] = '\0';
}

void mutableToLower(char* text, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		text[i] = tolower(text[i]);
	}
}

void immutableToLower(char* text, char* buf, int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		buf[i] = tolower(text[i]);
	}
}
void mutableFilter(char* text, int len)
{
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

void  immutableFilter(char* text, char* buf, int len)
{
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


void mutableDeleteSpace(char* text, int len)
{
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

void immutableDeleteSpace(char* text, char* buf, int len)
{
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

void mutableTrim(char* text, int len)
{
	int deltaStart = 0, deltaFinish = 0;
	int k = 0;

	while (text[k] == 32)
	{
		deltaStart++;
		k++;
	}
	k = len - 1;
	while (text[k] == 32)
	{
		deltaFinish++;
		k--;
	}

	int endOfStringPos = len - deltaFinish - deltaStart;
	for (int i = 0; i < endOfStringPos; i++)
	{
		text[i] = text[i + deltaStart];
	}

	if (deltaStart == len)
	{
		endOfStringPos = 0;
	}
	text[endOfStringPos] = 0;
}
void immutableTrim(char* text, char* buf, int len)
{
	int deltaStart = 0, deltaFinish = 0;
	int k = 0;

	while (text[k] == 32)
	{
		deltaStart++;
		k++;
	}
	k = len - 1;
	while (text[k] == 32)
	{
		deltaFinish++;
		k--;
	}

	int endOfStringPos = len - deltaFinish - deltaStart;
	for (int i = 0; i < endOfStringPos; i++)
	{
		buf[i] = text[i + deltaFinish];
	}

	if (deltaStart == len)
	{
		endOfStringPos = 0;
	}
	buf[endOfStringPos] = 0;
}

bool isNumber(char* text, int len)
{
	for (int k = 0; k < len; k++)
	{
		if ((text[k] < 48) || (text[k] > 57))
		{
			return false;
		}
	}
	return true;
}

bool isLetter(char* text, int len)
{
	for (int k = 0; k < len; k++)
	{
		if ((text[k] < 65) || ((text[k] > 90) && (text[k] < 97)) || (text[k] > 122))
		{
			return false;
		}
	}
	return true;
}