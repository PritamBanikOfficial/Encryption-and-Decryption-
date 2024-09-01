#include <stdio.h>
#include <string.h>
#define MAX_MESSAGE_LENGTH 1024

char decryptChar(char c, int key) {
    return (c - key);
}

void decryptMessage(char *message, int key) {
    for (int i = 0; i < strlen(message); i++) {
        message[i] = decryptChar(message[i], key);
    }
}

int main() {
    char message[MAX_MESSAGE_LENGTH];
    int key;
    FILE *file;

    file = fopen("encrypted_message.txt", "r");
    if (file == NULL) {
        printf("Error opening file for reading!\n");
        return 1;
    }

    fgets(message, MAX_MESSAGE_LENGTH, file);
    fclose(file);

    printf("Enter the decryption key (positive integer): ");
    scanf("%d", &key);

    decryptMessage(message, key);

    printf("Decrypted message: %s\n", message);

    return 0;
}

