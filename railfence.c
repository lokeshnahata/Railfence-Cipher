#include<stdio.h>
#include<string.h>
 
void encryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = msg[i];
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    printf("\nEncrypted Message: ");
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] != '\n')
                printf("%c", railMatrix[i][j]);
}
 
void decryptMsg(char msg[], int key){
    int msgLen = strlen(msg), i, j, k = -1, row = 0, col = 0, m = 0;
    char railMatrix[key][msgLen];
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            railMatrix[i][j] = '\n';
 
    for(i = 0; i < msgLen; ++i){
        railMatrix[row][col++] = '*';
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
 
    for(i = 0; i < key; ++i)
        for(j = 0; j < msgLen; ++j)
            if(railMatrix[i][j] == '*')
                railMatrix[i][j] = msg[m++];
 
    row = col = 0;
    k = -1;
 
    printf("\nDecrypted Message: ");
 
    for(i = 0; i < msgLen; ++i){
        printf("%c", railMatrix[row][col++]);
 
        if(row == 0 || row == key-1)
            k= k * (-1);
 
        row = row + k;
    }
}
 
int main(){
int n,key;
char msg[50];
char msg1[50];
printf("Enter a choice\n");
printf("1. For encryption using railfence\n");
printf("2. For decryption using railfence\n");
scanf("%d",&n);
switch(n)
{
case 1:
	printf("Enter a message to encrypt\n");
    	scanf("%s",msg);
    printf("Enter a key value to shift rail\n");
    scanf("%d",&key);
 
    printf("Original Message: %s", msg);
 
    encryptMsg(msg, key);

	break;
case 2:
	printf("Enter  a message\n");
	scanf("%s",msg1);
printf("Enter a key value to shift rail\n");
    scanf("%d",&key);

    decryptMsg(msg1, key);
 break;
    
}
return 0;}
