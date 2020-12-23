#pragma once

void mutableEncoderCesar(char* text, int step, int len);
void mutableDecoderCesar(char* text, int step, int len);
void immutableEncoderCesar(char* text, int step, char* buf, int len);
void immutableDecoderCesar(char* text, int step, char* buf, int len);
void mutableEncoderXor(char* text, char* key, int len);
void mutableDecoderXor(char* text, char* key, int len);
void immutableEncoderXor(char* text, char* key, char* buf, int len);
void immutableDecoderXor(char* text, char* key, char* buf, int len);

