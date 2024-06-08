#include <stdio.h>
#include <errno.h>
#include <string.h>

int main()
{
    FILE *fileOpen;
    fileOpen = fopen("firstOpenFile.txt", "w");
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