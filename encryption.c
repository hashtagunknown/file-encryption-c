#include "encryption.h"

int encryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    FILE *inputFile = fopen(inputFileName, "rb");
    if (!inputFile) {
        perror("Error opening input file");
        return 1;
    }

    FILE *outputFile = fopen(outputFileName, "wb");
    if (!outputFile) {
        perror("Error opening output file");
        fclose(inputFile);
        return 1;
    }

    int keyIndex = 0;
    char inputChar, outputChar;
    while ((inputChar = fgetc(inputFile)) != EOF) {
        outputChar = inputChar ^ key[keyIndex];
        fputc(outputChar, outputFile);
        
        keyIndex = (keyIndex + 1) % strlen(key);
    }

    printf("File encrypted successfully!\n");

    fclose(inputFile);
    fclose(outputFile);

    return 0;
}

int decryptFile(const char *inputFileName, const char *outputFileName, const char *key) {
    return encryptFile(inputFileName, outputFileName, key);
}
