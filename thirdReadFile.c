#include <stdio.h>

int main()
{
    char array[100];
    FILE *fileOpen;
    fileOpen = fopen("secondOpenFile.txt", "r");
    if (fileOpen == NULL)
    {
        printf("I am unable to open the File for reading\n");
    }
    else
    {
        while (fgets(array, 100, fileOpen) != NULL)
        {
            printf("%s", array);
        }
        fclose(fileOpen);
    }
}