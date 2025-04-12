#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

char * vigenere(char* plaintext,char*  key){
    int count=strlen(plaintext);
    int key_index=0;
    int index=strlen(key);
    int decalage;
    for (int i = 0; i < count; i++)
    {
        if (key[key_index]>='a' && key[key_index]<='z')    //permet de verifier si le caractere de la cle est une miniscule
        {
            decalage=97;
        }
        else if (key[key_index]>='A' && key[key_index]<='Z')      //permet de verifier si le caractere de la cle est une majuscule
        {
            decalage=65;
        }
        else{
            decalage=0;
        }

        if (plaintext[i]>='a' && plaintext[i]<='z')
        {
            plaintext[i]=((plaintext[i]-97)+(key[key_index]-decalage))%26+97;
            key_index=(key_index+1)%index;                                   //permet de faire une boucle sur la cle si on arrive a la fin de la cle cela nous permet de revenir au debut
        }
        else if (plaintext[i]>='A' && plaintext[i]<='Z')
        {
            plaintext[i]=((plaintext[i]-65)+(key[key_index]-decalage))%26+65;
            key_index=(key_index+1)%index;
        }
        else if (plaintext[i]>='0' && plaintext[i]<='9')
        {
            plaintext[i]=plaintext[i];
        }
        else if (plaintext[i]==27)
        {
            plaintext[i]=27;
        }
    }
    return plaintext;
}

char * vigenere_dechiffrage(char* plaintext,char*  key){
    int count=strlen(plaintext);
    int key_index=0;
    int index=strlen(key);
    int decalage;
    for (int i = 0; i < count; i++)
    {  
        if (key[key_index]>='a' && key[key_index]<='z')
        {
            decalage=97;
        }
        else if (key[key_index]>='A' && key[key_index]<='Z')
        {
            decalage=65;
        }
        else{
            decalage=0;
        }

        if (plaintext[i]>='a' && plaintext[i]<='z')
        {
            int shit=(plaintext[i]-97)-(key[key_index]-decalage);
            if (shit<0)
            {
                shit=shit+26;
            }
            plaintext[i]=(shit%26)+97;
            key_index=(key_index+1)%index;
        }
        else if (plaintext[i]>='A' && plaintext[i]<='Z')
        {
            int shit=(plaintext[i]-65)-(key[key_index]-decalage);
            if (shit<0)
            {
                shit=shit+26;
            }
            plaintext[i]=(shit%26)+65;
            key_index=(key_index+1)%index;
        }
        else if (plaintext[i]>='0' && plaintext[i]<='9')
        {
            plaintext[i]=plaintext[i];
        }
        else if (plaintext[i]==27)
        {
            plaintext[i]=27;
        }
    }
    return plaintext;
}

int main(){
    char *plaintext ,*ciphertext,*key;
    plaintext=(char *)malloc(sizeof(char));
    ciphertext=(char *)malloc(sizeof(char));
    key=(char *)malloc(sizeof(char));
    printf("Entrer les message a coder:");
    gets(plaintext);
    printf("Entrer la cle du codage:");
    gets(key);
    ciphertext=vigenere(plaintext,key);
    printf("Le message coder est de: %s\n",ciphertext);
    printf("Entrer les message a decoder:");
    gets(plaintext);
    ciphertext=vigenere_dechiffrage(plaintext,key);
    printf("Le message decoder est de: %s",ciphertext);
    return 0;

}