#include <stdio.h>
#include <stdlib.h>

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

int deleteFile() {
    char filename[100];
    printf("Enter the file name to delete: ");
    scanf("%s", filename);
    if (remove(filename) == 0) {
        printf("Deleted the file successfully\n");
    } else {
        printf("Unable to delete the file\n");
    }
    return 0;
}

void main()
{
    char string[1000];
    FILE *fileOpen;

    clearScreen();

    fileOpen = fopen("appendNewFile.txt", "w");

    if (fileOpen == NULL)
    {
        printf("I am unable to open the File for reading, Can Not Open the file\n");
    }
    else
    {
        printf("Enter the content to be written in the file:\n");
        fgets(string, sizeof(string), stdin); 
        fputs(string, fileOpen);
        printf("File is Opened with Written content\n");
        fclose(fileOpen);
    }

    deleteFile();
}
