#include <stdio.h> 
#include <stdlib.h> 
#include <string.h> 
#include <conio.h> 
 
#define MAX_DICT_SIZE 4096 
 
typedef struct { 
    char* value; 
    int code; 
} DictionaryEntry; 
 
// Sözlüğü başlat (tek karakterleri ekle) 
void initializeDictionary(DictionaryEntry* dictionary) { 
    for (int i = 0; i < 256; i++) { 
        dictionary[i].value = (char*)malloc(2); 
        dictionary[i].value[0] = (char)i; 
        dictionary[i].value[1] = '\0'; 
        dictionary[i].code = i; 
    } 
} 
 
// Sözlükte arama (varsa kodunu döner) 
int findInDictionary(DictionaryEntry* dictionary, int size, const char* str) { 
    for (int i = 0; i < size; i++) { 
        if (strcmp(dictionary[i].value, str) == 0) { 
            return dictionary[i].code; 
        } 
    } 
    return -1; 
} 
 
void LZWCompress(const char* input) { 
    DictionaryEntry dictionary[MAX_DICT_SIZE]; 
    initializeDictionary(dictionary); 
    int dictSize = 256; 
 
    char P[1024] = {0}; 
    char C[2] = {0}; 
    char PC[1024]; 
 
    int i = 0; 
    int inputLen = strlen(input); 
 
    // 2. Adım: P = ilk karakter 
    P[0] = input[i++]; 
    P[1] = '\0'; 
 
    // 3. WHILE dosya sonu değilse 
    while (i < inputLen) { 
        C[0] = input[i++]; 
        C[1] = '\0'; 
 
        // 5. IF (P + C) sözlükte varsa 
        strcpy(PC, P); 
        strcat(PC, C); 
 
        int index = findInDictionary(dictionary, dictSize, PC); 
        if (index != -1) {//P+C sözcük tablosunda ise  
            // 6. P = P + C 
            strcpy(P, PC); 
        } else { 
            // 8. P'yi sıkıştırılmış çıktıya yaz 
            int pIndex = findInDictionary(dictionary, dictSize, P); 
            printf("%d ", pIndex); 
           // 9. P + C'yi sözlüğe ekle 
            if (dictSize < MAX_DICT_SIZE) { 
                dictionary[dictSize].value = (char*)malloc(strlen(PC) + 1); 
                strcpy(dictionary[dictSize].value, PC); 
                dictionary[dictSize].code = dictSize; 
                dictSize++; 
            } 
 
            // 10. P = C 
            strcpy(P, C); 
        } 
    } 
 
    // 13. P'yi sıkıştırılmış dosyaya yaz 
    int finalIndex = findInDictionary(dictionary, dictSize, P); 
    printf("%d\n", finalIndex); 
} 
 
int main() { 
char input[] = "BABAABAAA"; 
printf("Giriş: %s\n", input); 
printf("Sıkıştırılmış Kodlar: "); 
LZWCompress(input); 
getch(); 
return 0; 
}