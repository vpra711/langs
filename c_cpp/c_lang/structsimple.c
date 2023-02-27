#include <stdio.h>

struct studentDetails
{
    char name[30];
    char rollno[10];
    char cgpa[5];
};

int main()
{
    struct studentDetails details;
    struct studentDetails details1;

    if(!gets(details.name))
        gets(details.name);

    if(!gets(details.rollno))
        gets(details.rollno);

    if(!gets(details.cgpa))
        gets(details.cgpa);

    FILE *fp;

    fp = fopen("student_details.txt", "w");
    fputs(details.name, fp);
    fputc('\n', fp);
    fputs(details.rollno, fp);
    fputc('\n', fp);
    fputs(details.cgpa, fp);
    freopen("student_details.txt", "r", fp);
    fgets(details1.name, 30, fp);
    fgets(details1.rollno, 10, fp);
    fgets(details1.cgpa, 5, fp);
    fclose(fp);

    printf("%s", details1.name);
    printf("%s", details1.rollno);
    printf("%s", details1.cgpa);

    return 0;
}