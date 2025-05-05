#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_LEN 100000
void vigenereEncrypt(const char*text, const char*key,char*result) {
    int textLen = strlen(text);
    int keyLen = strlen (key);
    for(int i = 0,j = 0; i< textLen; i++){
        char c = text[i];
        if ( isalpha (c)) {
            char base = isupper(c) ? 'A' : 'a';
            char k = tolower(key[j% keyLen])-'a';
            result[i] = ((tolower(c)-'a' +k) %26)+base;
            j++;
        }else{
            result[i] = c;
        }
}
result[textLen] = '\0';
}
int main(){
    FILE* inputFile = fopen("input.txt","r");
    FILE*keyFile = fopen("key.txt","r");
    FILE*outputFile = fopen("output.txt","wb");
     if(!inputFile || !keyFile || !outputFile){
        perror("Error opening file");
        return 1;
     }
     char text[MAX_LEN];
     char key[256];
     char result[MAX_LEN];

     fread(text, 1, MAX_LEN, inputFile);
     fscanf(keyFile,"%s", key);

     vigenereEncrypt(text, key, result);
     fprintf(outputFile, "%s" ,result);

     fclose(inputFile);
     fclose(keyFile);
     fclose(outputFile);

     return 0;

}