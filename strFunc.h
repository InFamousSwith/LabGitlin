#pragma once
void mutableToUpper(char* text, int len);
void immutableToUpper(char* text, char* buf, int len);
void mutableToLower(char* text, int len);
void immutableToLower(char* text, char* buf, int len);
void mutableFilter(char* text, int len);
void immutableFilter(char* text, char* buf, int len);
void mutableDeleteSpace(char* text, int len);
void immutableDeleteSpace(char* text, char* buf, int len);
bool isNumber(char* text, int len);
bool isLetter(char* text, int len);
void mutableTrim(char* text, int len);
void immutableTrim(char* text, char* buf, int len);