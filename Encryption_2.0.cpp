#include<stdio.h>
#include<string.h>
#define MAX_MESSAGE_LENGTH 1024

char encryptChar(char c, int key){
	return (c + key);
}

void encryptMessage(char *message, int key){
	for (int i = 0; i < strlen(message); i++) {
        message[i] = encryptChar(message[i], key);
    }
}

int main(){
	char message[MAX_MESSAGE_LENGTH];
	int key;
	FILE *file;
	
	printf("Enter your message which will be encrypted : ");
	fgets(message ,MAX_MESSAGE_LENGTH, stdin);
	//message [strcspn(message, "\n")] = '/0';
	
	printf("Enter the encryption key (must be an interger number) : ");
	scanf("%d", &key);
	printf("\n\n	You have to remember the encryption key to decrypt the text file \n\n");
	encryptMessage(message, key);
	
	file = fopen("Encrypted_message.txt","w");
	if(file == NULL){
		printf("Error opening file for writing !\n");
		return 1;
	}
	
	fprintf(file, "%s", message);
	fclose(file);
	printf("\n\n	Message encryption done and saved to 'Encrpted_message.txt'\n");
	
	return 0;
}
