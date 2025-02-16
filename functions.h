#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int checkInput(char* input);
void fillFile(const char* filename);
void printFile(const char* filename);
void findMinMaxSum(const char* filename);
void zeroElements(const char* filename);
void removeZeros(const char* filename);

#endif
