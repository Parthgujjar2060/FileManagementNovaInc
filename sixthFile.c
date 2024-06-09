#include<stdio.h>
#include <conio.h>

void main(){
    struct student{
        char name[100];
        int rollNo;
        float percentage;
    };
    struct student student;
    FILE *fileOpen;
    fileOpen = fopen("studentFile.txt", "r");
    if (fileOpen == NULL){
        printf("I am unable to open the file for reading\n");
    } else {
        while (fscanf(fileOpen, "%s %d %f\n", student.name, &student.rollNo, &student.percentage) != EOF){
            printf("Name: %s\nRoll No: %d\nPercentage: %f\n", student.name, student.rollNo, student.percentage);
        }
        fclose(fileOpen);
    }

}