#include<stdio.h>
#include<string.h>

int main(){
    char array[100000];
    FILE *fileOpen;
    fileOpen = fopen("secondOpenFile.txt", "r");
    fileOpen = fopen("secondOpenFile.txt", "w");
    if(fileOpen == NULL){
        printf("I am unalbe to open the File for reading\n");
    }
    else{
        for(int i = 0; i < strlen(array); i++){
            fputc(array[i], fileOpen);
        }
        printf("File is Opened with Written content\n");
        fclose(fileOpen);
    }
} 