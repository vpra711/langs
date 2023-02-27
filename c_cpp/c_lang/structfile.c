#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct studentDetails studentDetails;
struct studentDetails
{
    char* name;
    char* rollno;
    char* cgpa;
};

studentDetails* getinput();
void writeIntoFile(studentDetails*);
studentDetails* readFromFile();
void print(studentDetails*);

int main(void)
{
    studentDetails* s = getinput();
    printf("\nWriting to a file:");
    writeIntoFile(s);
    print(s);
    printf("\n\nReading from a file:");
    studentDetails* s1 = readFromFile();
    print(s1);
    return 0;
}

studentDetails* getinput()
{
    char buffer[100];
    float cgpa;
    studentDetails* details;

    details = (studentDetails*) malloc(sizeof(studentDetails));
    printf("\nEnter name: ");

    if(!gets(buffer))
        gets(buffer);

    details->name = (char*) malloc(strlen(buffer) + 1);
    strcpy(details->name, buffer);
    printf("Enter rollno: ");

    if(!gets(buffer))
        gets(buffer);

    details->rollno = (char*) malloc(strlen(buffer) + 1);
    strcpy(details->rollno, buffer);
    printf("Enter cgpa: ");
    
    if(!gets(buffer))
        gets(buffer);

    details->cgpa = (char*) malloc(strlen(buffer) + 1);
    strcpy(details->cgpa, buffer);

    return details;
}

void writeIntoFile(studentDetails* details)
{
    FILE *fp;
    fp = fopen("student_details.txt", "w");

    fputs(details->name, fp);
    fputc('\n', fp);
    fputs(details->rollno, fp);
    fputc('\n', fp);
    fputs(details->cgpa, fp);

    fclose(fp);
}

studentDetails* readFromFile()
{
    char buffer[100];
    studentDetails* details;
    FILE* fp;
    int i = 0;
    fp = fopen("student_details.txt", "r");
    char c;

    while((c = fgetc(fp)) != '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';
    details->name = (char*) malloc(sizeof(buffer) + 1);
    strcpy(details->name, buffer);

    i = 0;
    while((c = fgetc(fp)) != '\n')
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';
    details->rollno = (char*) malloc(sizeof(buffer) + 1);
    strcpy(details->rollno, buffer);

    i = 0;
    while((c = fgetc(fp)) != EOF)
    {
        buffer[i] = c;
        i++;
    }

    buffer[i] = '\0';
    details->cgpa = (char*) malloc(sizeof(buffer) + 1);
    strcpy(details->cgpa, buffer);

    fclose(fp);
    return details;
}

void print(studentDetails* details)
{
    printf("\nStudent Name: %s", details->name);
    printf("\nStudent RollNo: %s", details->rollno);
    printf("\nStudent CGPA: %s", details->cgpa);
}