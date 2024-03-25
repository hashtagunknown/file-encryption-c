#include <stdio.h>
#include <string.h>
#include "encryption.h"

int main() {
    char inputFileName[256];
    char outputFileName[256];
    char key[256];
    int choice;

    printf("1. Encrypt a file\n");
    printf("2. Decrypt a file\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    printf("Enter input file name: ");
    scanf("%s", inputFileName);

    printf("Enter output file name: ");
    scanf("%s", outputFileName);

    printf("Enter key: ");
    scanf("%s", key);

    switch (choice) {
        case 1:
            if (encryptFile(inputFileName, outputFileName, key) != 0) {
                printf("Encryption failed!\n");
            }
            break;
        case 2:
            if (decryptFile(inputFileName, outputFileName, key) != 0) {
                printf("Decryption failed!\n");
            }
            break;
        default:
            printf("Invalid choice!\n");
    }

    return 0;
}
