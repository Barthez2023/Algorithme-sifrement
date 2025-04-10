#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * sezar_algo(char* plaintext,int key){
    int count=strlen(plaintext);
    for (int i = 0; i < count; i++)
    {
        if (plaintext[i]>='a' && plaintext[i]<='z')
        {
            plaintext[i]=((plaintext[i]-97)+key)%26+97;
        }
        else if (plaintext[i]>='A' && plaintext[i]<='Z')
        {
            plaintext[i]=((plaintext[i]-65)+key)%26+65;
        }
        else if (plaintext[i]>='0' && plaintext[i]<='9')
        {
            plaintext[i]=((plaintext[i]-48)+key)%10+48;
        }
        else if (plaintext[i]==27)
        {
            plaintext[i]=27;
        }
    }
    return plaintext;
}

int main(){
    char *plaintext ,*ciphertext;
    plaintext=(char *)malloc(sizeof(char));
    ciphertext=(char *)malloc(sizeof(char));
    int key;
    printf("Entrer les message a coder:");
    gets(plaintext);
    printf("Entrer la cle du codage:");
    scanf("%d",&key);
    ciphertext=sezar_algo(plaintext,key);
    printf("Le message coder est de: %s",ciphertext);

    return 0;

}