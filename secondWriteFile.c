#include <stdio.h>

int main()
{
    int i;
    FILE *fileOpen;
    char array[100] = {"Hello Mr.hennry How r u? Here you feel free to write anything"};
    fileOpen = fopen("secondOpenFile.txt", "w");
    if (fileOpen == NULL)
    {
        printf("I am unable to open the File\n");
    }
    else
    {
        for (i = 0; i < strlen(array); i++)
        {
            fputc(array[i], fileOpen);
        }
        printf("File is Opened with Written content\n");
        fclose(fileOpen);
    }
}