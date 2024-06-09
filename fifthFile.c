#include <stdio.h>
#include <conio.h>

void main()
{

    struct studentFile
    {
        char name[100];
        int rollNo;
        float percentage;
    };
    struct studentFile student;
    FILE *fileOpen;

    char query = 'Y';
    fileOpen = fopen("studentFile.txt", "w");

    if (fileOpen == NULL)
    {
        printf("I am unable to open the file for writing\n");
    }
    else
    {
        while (query == 'Y' || query == 'y')
        {
            printf("Enter the name of the student: ");
            scanf("%s", student.name);
            printf("Enter the roll number of the student: ");
            scanf("%d", &student.rollNo);
            printf("Enter the percentage of the student: ");
            scanf("%f", &student.percentage);

            fprintf(fileOpen, "%s %d %f\n", student.name, student.rollNo, student.percentage);
            printf("Do you want to enter another record? (Y/N): ");

            query = getche();
        }
        fclose(fileOpen);
    }
}