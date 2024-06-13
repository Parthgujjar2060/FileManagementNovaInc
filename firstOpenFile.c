#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fileOpen;
    fileOpen = fopen("firstOpenFile.txt", "w");
    printf("Do you want to create a new File??\n");
    printf("Press Y for Yes and N for No: ");
    char query;
    scanf(" %c", &query);

    if (query == 'Y' || query == 'y')
    {
        printf("What is the name of the File (without extension)\n");
        char fileName[100];
        scanf("%s", fileName);

        strcat(fileName, ".txt");

        fileOpen = fopen(fileName, "w");
    }
    else
    {
        printf("File is not created\n");
    }

    if (fileOpen == NULL)
    {
        printf("File not found: %s\n", strerror(errno));
    }
    else
    {
        printf("File is opened\n");
        fclose(fileOpen);
    }

    return 0;
}
