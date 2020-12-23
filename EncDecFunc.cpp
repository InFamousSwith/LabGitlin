#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

#include "encdec.h"

void mutableEncoderCesar(char* text, int step, int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		text[i] = text[i] + step;
	}
}

void immutableEncoderCesar(char* text, int step, char* buf, int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		buf[i] = text[i] + step;
	}
}

void mutableDecoderCesar(char* text, int step, int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		text[i] = text[i] - step;
	}
}

void immutableDecoderCesar(char* text, int step, char* buf, int len)
{
	for (unsigned int i = 0; i < len; i++)
	{
		buf[i] = text[i] - step;
	}
}

void mutableEncoderXor(char* text, char* key, int len)
{
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		text[i] ^= key[keyindex];
	}
}

void immutableEncoderXor(char* text, char* key, char* buf, int len)
{
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		buf[i] = text[i] ^ key[keyindex];
	}
	buf[strlen(text)] = 0;
}

void mutableDecoderXor(char* text, char* key, int len)
{
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		text[i] ^= key[keyindex];
	}
}

void immutableDecoderXor(char* text, char* key, char* buf, int len)
{
	for (unsigned int i = 0; text[i]; i++)
	{
		int keyindex = i % len;
		buf[i] = text[i] ^ key[keyindex];
	}
	buf[strlen(text)] = 0;
}