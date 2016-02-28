#pragma once
#include <stdarg.h>

// function names
void testfunc(); // help
unsigned int mtu_countUTF8(char*);
int mtu_writeFileOpen(char*, char*, int, char*);
int mtu_writeFileFopen(char*, char*, int, char*);
unsigned int mtu_popen();
int mtu_canNegate(int);
int mtu_canDivide(int, int);
void mtu_qsort(float*, int);
char* mtu_lang();
int* mtu_pairSum(int, ...);
int mtu_printFiles();
