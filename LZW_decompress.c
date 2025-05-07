#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 

#define MAX_DICT_SIZE 4096 

// creation du dictionnaire
typedef struct Dictionary
{
    char * value;
    int code;
}DictionaryEntry;

//initialisation du dictionnaire avec des valeur de 0 a 255 representant les valeurs de la table ASCII
void initialisationDict(DictionaryEntry *Dictionnaire){
    for (int i = 0; i < 256; i++)
    {
        Dictionnaire[i].value=(char*)malloc(2);
        Dictionnaire[i].value[0]=(char)i;
        Dictionnaire[i].value[1]='\0';
        Dictionnaire[i].code=i;
    }
}



void LZWDeCompress(int*compress ,int size){
    DictionaryEntry dictionary[MAX_DICT_SIZE]; 
    initialisationDict(dictionary); 
    int dictSize = 256; 

    int old=compress[0];  //on recupere le premier chiffre de la chaine a decompresser
    char *S =dictionary[old].value;
    printf("%s",S);

    char C=S[0];

    for (int i = 1; i < size; i++)
    {
        int new=compress[i]; 
        if (new<dictSize)  // le caractere lu est dans le dictionnaire
        {
           S=dictionary[new].value;    // S prend la valeur du caractere asocie a new
           printf("%s", S);
           C = S[0];  // Premier caractère de S
        }
        else{
            if (new==dictSize)   // new n'est pas dans le dictionnaire S + C'yi oluştur
            {
                S = (char*)malloc(strlen(dictionary[old].value) + 2);  // Yeterli bellek ayır
                strcpy(S, dictionary[old].value);  // Eski kodun karşılığını al
                int len =strlen(S);
                C=S[0];
                S[len]=C;
                S[len+1]='\0';
                printf("%s",S);
                C=S[0];
            }
        }
        // (OLD + C)'yi sözlüğe ekle
        if (dictSize < MAX_DICT_SIZE) { 
            dictionary[dictSize].value = (char*)malloc(strlen(dictionary[old].value) + 2); 
            sprintf(dictionary[dictSize].value, "%s%c", dictionary[old].value, C); 
            dictionary[dictSize].code = dictSize; 
            dictSize++; 
        }
         // OLD'yi güncelle 
         old = new; 
        
        //printf("\n");
        
    }
}

int main() { 
    // Örnek sıkıştırılmış dosya (sadece kodlar) 
    int compressed[] = {66, 65, 256, 257, 65,260}; 
    int compressedSize = sizeof(compressed) / sizeof(compressed[0]); 
 
    printf("Sikistirilmis Dosya icerigi: "); 
    for (int i = 0; i < compressedSize; i++) { 
        printf("%d ", compressed[i]); 
    } 
    printf("\n"); 
 
    printf("Acilmis Dosya icerigi: "); 
    LZWDeCompress(compressed, compressedSize); 
    getch(); 
    return 0; 
}
