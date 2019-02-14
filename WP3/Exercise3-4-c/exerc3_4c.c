/* ====================================
File name: exerc3_4.c
Date: 2019-02-12
Group nr 04
Members that contribute to the solutions
Filip Fatic
Naief Jobsen
David Lindgren
Demonstration code: [gib me code]
====================================== */

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
//
/*-----
Typedefs
-------*/
typedef struct
{
    char firstname[20];
    char famname[20];
    char pers_number[13]; // yyyymmddnnnc
} PERSON;

// Function declaration (to be extend)
PERSON input_record(void);

// Reads in a person record.
void write_new_file(PERSON *inrecord); //Creats a file and write a first record
void printfile(void);                  // print out all persons in the file
void search_by_firstname(char *name);  // print out person if in list
void append_file(PERSON *inrecord);    // appends a new person to the file

int main(void)
{
    PERSON ppost;
    PERSON *ptr = &ppost;
    char choice[3];
    char searchname[20];
    while (choice[0] != '5')
    {
        printf("Choose a function: \n");
        printf("1. Create a new and delete the old file\n"
               "2. Add a new person to file\n"
               "3. Search for a person in the file\n"
               "4. Print out all in file\n"
               "5. Exit the program\n");
        fgets(choice, 3, stdin);
        switch (choice[0])
        {
        case '1':
            write_new_file(ptr);
            break;
        case '2':
            printf("First name(max 20 chars):\n");
            fgets(ppost.firstname, 20, stdin);
            printf("Family name(max 20 chars):\n");
            fgets(ppost.famname, 20, stdin);
            printf("Personnummer(max 13 digits):\n");
            fgets(ppost.pers_number, 13, stdin);
            append_file(ptr);
            break;
        case '3':
            printf("Enter the first name of the person:\n");
            fgets(searchname, 20, stdin);
            search_by_firstname(searchname);
            break;
        case '4':
            printfile();
            break;
        case '5':
            printf("Quitting..\n");
            break;
        default:
            printf("Invalid option\n");
            break;
        }
    }
    return (0);
}

void write_new_file(PERSON *inrecord)
{
    //TODO create file

    //writing to file params:
    //address of data, sizeof data, 1(??) and address to file

    FILE *fh = fopen("file.bin", "wb");
    char test[20] = "test\n";
    strcpy(inrecord->firstname, test);
    strcpy(inrecord->famname, test);
    strcpy(inrecord->pers_number, test);
    if (fh != NULL)
    {
        fwrite(inrecord, sizeof(PERSON), 1, fh);
        printf("File initialized.\n");
        fclose(fh);
    }
    else
    {
        printf("\n Could not open file. \n");
    }
}

void printfile()
{
    FILE *fh = fopen("file.bin", "rb");
    PERSON *ptr = malloc(sizeof(PERSON));
    int i = 1;
    if (fh != NULL)
    {
        while (!feof(fh))
        {
            if (fread(ptr, sizeof(PERSON), 1, fh))
            {
                printf("Person %d: ", i);
                printf("\n %s", ptr->firstname);
                printf("\n %s", ptr->famname);
                printf("\n %s\n", ptr->pers_number);
            }
            i++;
        }
        fclose(fh);
    }
}

void search_by_firstname(char *name)
{
    FILE *fh = fopen("file.bin", "rb");
    PERSON *ptr = malloc(sizeof(PERSON));
    bool found = false;
    if (fh != NULL)
    {
        while (!feof(fh))
        {
            if (fread(ptr, sizeof(PERSON), 1, fh))
            {
                if (strcmp(ptr->firstname, name) == 0)
                {
                    printf("Found file:\n");
                    printf("\n %s", ptr->firstname);
                    printf("\n %s", ptr->famname);
                    printf("\n %s", ptr->pers_number);
                    found = true;
                    break;
                }
            }
        }
        if (!found)
        {
            printf("Could not find specified person\n");
        }
        fclose(fh);
    }
}

void append_file(PERSON *inrecord)
{
    FILE *fh = fopen("file.bin", "ab");
    PERSON *ptr = malloc(sizeof(PERSON));
    if (fh != NULL)
    {
        fwrite(inrecord, sizeof(PERSON), 1, fh);
        printf("Person added.\n");
        fclose(fh);
    }
    else
    {
        printf("\n Could not open file.\n");
    }
}

void clear_stdin()
{
    while (getchar() != '\n')
    {
        ;
    }
}