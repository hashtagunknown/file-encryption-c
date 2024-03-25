#ifndef ENCRYPTION_H
#define ENCRYPTION_H

#include <stdio.h>

int encryptFile(const char *inputFileName, const char *outputFileName, const char *key);
int decryptFile(const char *inputFileName, const char *outputFileName, const char *key);

#endif
