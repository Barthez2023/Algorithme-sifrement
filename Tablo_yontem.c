#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
char tab1[52],tab2[52];
void tablo(){    // Dans cette fonction je met en place les tables d'encriptage et de de-encriptage
    for (int i = 0; i < 26; i++)
    {
        tab1[i]=i+97;             //caractere miniscules
    }
    for (int i = 27; i < 52; i++)
    {
        tab1[i]=i+38;             //caractere majuscule
    }
    for (int i = 0; i < 52; i++)
    {
        tab2[i]=tab1[(tab1[i]+3)%52];
    }
}

char * tablo_yontem_algo(char* plaintext){
    int count=strlen(plaintext);
    char caractere;
    for (int i = 0; i < count; i++)
    {
        caractere=plaintext[i];
        for (int j = 0; j < 52; j++)
        {
            if (caractere==tab1[j])
            {
                plaintext[i]=tab2[j];
                break;
            }
            if (caractere==' ')
            {
                plaintext[i]=' ';
            }
            
        }
    }
    return plaintext;
}

int main(){
    tablo();
    char *plaintext ,*ciphertext;
    plaintext=(char *)malloc(sizeof(char));
    ciphertext=(char *)malloc(sizeof(char));
    printf("Entrer les message a coder:");
    gets(plaintext);
    ciphertext=tablo_yontem_algo(plaintext);
    printf("Le message coder est de: %s\n",ciphertext);



    /*for (int i = 0; i < 52; i++)
    {
        printf("%c ",tab1[i]);
    }
    printf("\n");
    for (int i = 0; i < 52; i++)
    {
        printf("%c ",tab2[i]);
    }
    printf("Le message coder est de: %s",ciphertext);*/

    return 0;

}