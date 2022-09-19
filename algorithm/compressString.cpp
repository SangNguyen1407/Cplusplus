/* String Compression
 * aaaaabbcc -> a5b2c2
 */

#include <stdio.h>
#include <string>
#include <cstring>

#define MAXSIZE 10000

int handleCompressString(char *inputString, char *compressString, int *compressCount){
    int count = 0;
    int len = strlen(inputString);
    
    for (int i = 0; i < len; i++){
        if (compressString[count] == ' '){
            compressString[count] = inputString[i];
        }
        else if (compressString[count] != inputString[i]){
            count++;
            compressString[count] = inputString[i];
        }
        compressCount[count]++;
    }
    return count;
}

int handleEncompressString(char *outputString, char *compressString, int *compressCount, int count){
    int len = 0;
      
    for (int i = 0; i < count+1; i++){
        for (int j = 0; j < compressCount[i]; j++ ){
            outputString[len++] = compressString[i];
        }
    }
    return len;
}

void printCompressContent(char *compressString, int *compressCount, int count){
    if (compressString == NULL || count == 0){
        return;
    }

    for (int i = 0; i<count+1; i++){
        printf ("%c-%d\n", compressString[i], compressCount[i]);
    }
    return;
}

void printEncompressContent(char* outputString, int len){
    if(len == 0){
        return;
    }
    for (int i = 0; i<len; i++){
        printf ("%c", outputString[i]);
    }
    return;
}

int main (){
    char *inputString;
    FILE* fp = fopen ("file.txt", "r");
    fgets(inputString, MAXSIZE, (FILE*)fp); 
    int len = strlen(inputString);
    int outputStringLength = 0;

    char *compressString = (char *) malloc (sizeof(char) * len);
    int *compressCount = (int *) malloc (sizeof(int) * len);
    char *outputString = (char *) malloc (sizeof(char) * len);

    memset(compressString, ' ', len);
    memset(outputString, ' ', len);
    memset(compressCount, 0, len);

    printf ("---COMPRESS STRING---\n");
    printf ("character - count: \n");
    int count = handleCompressString(inputString, compressString, compressCount);
    printCompressContent(compressString, compressCount, count);

    printf ("\n---ENCOMPRESS STRING---\n");
    printf ("string:   ");
    count = handleEncompressString(outputString, compressString, compressCount, count);
    printEncompressContent(outputString, len);
}