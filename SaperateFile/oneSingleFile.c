#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

void clearScreen() {
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #else
        system("clear");
    #endif
}

void createFile() {
    char fileName[100];
    printf("Enter the name of the file to create (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    FILE *fileOpen = fopen(fileName, "w");
    if (fileOpen == NULL) {
        printf("Unable to create the file: %s\n", strerror(errno));
    } else {
        printf("File '%s' created successfully\n", fileName);
        fclose(fileOpen);
    }
}

void writeFile() {
    char fileName[100];
    printf("Enter the name of existing file to write to (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    FILE *fileOpen = fopen(fileName, "w");
    if (fileOpen == NULL) {
        printf("Unable to open the file: %s\n", strerror(errno));
    } else {
        char content[1000];
        printf("Enter the content to write in the file:\n");
        getchar();
        fgets(content, sizeof(content), stdin);

        fputs(content, fileOpen);
        printf("Content written to '%s' successfully\n", fileName);
        fclose(fileOpen);
    }
}

void readFile() {
    char fileName[100];
    printf("Enter the name of the file to read from (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    FILE *fileOpen = fopen(fileName, "r");
    if (fileOpen == NULL) {
        printf("Unable to open the file: %s\n", strerror(errno));
    } else {
        char content[1000];
        printf("Content of '%s':\n", fileName);
        while (fgets(content, sizeof(content), fileOpen) != NULL) {
            printf("%s", content);
        }
        fclose(fileOpen);
    }
}

void appendFile() {
    char fileName[100];
    printf("Enter the name of the file to append to (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    FILE *fileOpen = fopen(fileName, "a");
    if (fileOpen == NULL) {
        printf("Unable to open the file: %s\n", strerror(errno));
    } else {
        char content[1000];
        printf("Enter the content to append to the file:\n");
        getchar(); // To consume the newline character left by previous scanf
        fgets(content, sizeof(content), stdin);

        fputs(content, fileOpen);
        printf("Content appended to '%s' successfully\n", fileName);
        fclose(fileOpen);
    }
}

void deleteFile() {
    char fileName[100];
    printf("Enter the name of the file to delete (without extension): ");
    scanf("%s", fileName);
    strcat(fileName, ".txt");

    if (remove(fileName) == 0) {
        printf("Deleted the file '%s' successfully\n", fileName);
    } else {
        printf("Unable to delete the file: %s\n", strerror(errno));
    }
}

int main() {
    int choice;

    do {
        clearScreen();
        printf("File Management System\n");
        printf("1. Create File\n");
        printf("2. Write to File\n");
        printf("3. Read from File\n");
        printf("4. Append to File\n");
        printf("5. Delete File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                createFile();
                break;
            case 2:
                writeFile();
                break;
            case 3:
                readFile();
                break;
            case 4:
                appendFile();
                break;
            case 5:
                deleteFile();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }

        if (choice != 6) {
            printf("Press Enter to continue...");
            getchar(); // To consume the newline character left by previous scanf
            getchar(); // To wait for the user to press Enter
        }
    } while (choice != 6);

    return 0;
}
