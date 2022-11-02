#include <stdio.h>
#include <conio.h>
#include<string.h>
#include <stdlib.h>
#include <windows.h>
#include <string.h>

void gotoxy(int, int);
void menu();
void addTeacher1();
void addStudent();
void viewStudent();
void search();
void modify();
void deleterec();
void viewTeacher1();

struct student

{
    char name[20];
    char mobile[10];
    char year[5];
    int rollno;
    char course[20];
    char branch[20];
    int marks;
    float cgpa;
    float percentage;
    //============changes============
    char subject1[20];
    char subject2[20];
    char subject3[20];
    int subject1Marks;
    int subject2Marks;
    int subject3Marks;
    char grade;
    char result[4];
};

struct teacher
{
    char name[20];
    char mobile[10];
    int teacherID;
    char subjectName[20];
    int subjectID;
};

int main()
{
    gotoxy(15, 8);
    printf("<--:Student Record Management System:-->");
    gotoxy(19, 15);
    printf("\n\n\t\t\tPress any key to continue.");
    getch();
    menu();
    return 0;
}


// Function to hold the cursor in the screen coordinate x and y
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE),c);
}


// Create the menu of the program
void menu()
{
    int choice;
    system("cls");
    gotoxy(10, 3);
    printf("<--:MENU:-->");
    gotoxy(10, 5);
    printf("Enter appropriate number to perform following task.");
    gotoxy(10, 7);
    printf("1 : Admin Settings");
    gotoxy(10, 8);
    printf("2 : Teacher");
    gotoxy(10, 9);
    printf("3 : Student");
    gotoxy(10, 10);
    printf("4 : Exit.");
    gotoxy(10, 11);
    printf("Enter your choice.");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("\n\nSub Menu:\n1. Add teacher\n2. View Teacher\n\nEnter option: ");
        int subopt;
        scanf("%d", &subopt);
        switch (subopt)
        {
        case 1:
            addTeacher1();
            break;
        case 2:
            viewTeacher1();
            break;
        default:
            printf("\n\nInvalid choice");
            break;
        }
        break;
        case 2:
        printf("\n\nSub Menu:\n1. Add student\n2. View student\n3. Modify student\n4. Delete student\n\n\n\nEnter option: ");
        int subopt1;
        scanf("%d", &subopt1);
        switch (subopt1)
        {
        case 1:

            addStudent();
            break;
        case 2:

            viewStudent();
            break;
        case 3:

            modify();
            break;
        case 4:
            deleterec();
            // viewStudent();
            break;
        default:
            printf("\n\nInvalid choice");
            break;
        }
        break;

    case 3:
        printf("\n\nSub Menu:\n1. View Result \n\nEnter option: ");
        int choice;
        scanf("%d", &choice);
        switch (choice)
        {
        // case 1:
        //     viewStudent();
        //     break;

        case 1:
            search();
            break;
        default:
            gotoxy(10, 17);
            printf("Invalid Choice.");
        }
        break;
    case 4:
        exit(1);
        break;
    default:
        printf("\n\nInvalid choice");
        break;
    }
}

void addTeacher1()
{
    FILE *fp;
    struct teacher tcd;
    char another ='y';
    system("cls");

    fp = fopen("teacherrecord.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of teacher.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(tcd.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(tcd.mobile);
        gotoxy(10,9);
        printf("Enter Teacher ID : ");
        scanf("%d",&tcd.teacherID);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter SubjectName : ");
        gets(tcd.subjectName);
        gotoxy(10,11);
        printf("Enter Subject ID: ");
        scanf("%d",&tcd.subjectID);
        fwrite(&tcd,sizeof(tcd),1,fp);
        gotoxy(10,15);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,18);
    printf("Press any key to continue.");
    getch();
    menu();
}
void viewTeacher1()
{
    FILE *fp;
    int i=1,j;
    struct teacher tcd;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    printf("S.No   Name of Teacher      Mobile No   Teacher ID  Subject Name     Subject ID");
    gotoxy(10,6);
    printf("-------------------------------------------------------------------------------");
    fp = fopen("teacherrecord.txt","r+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
    j=8;
    while(fread(&tcd,sizeof(tcd),1,fp) == 1){
        gotoxy(10,j);
        printf("%-7d%-22s%-12s%-10d%-20s%-8d",i,tcd.name,tcd.mobile,tcd.teacherID,tcd.subjectName,tcd.subjectID);
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("\n\n\t\t\tPress any key to continue.");
    getch();
    menu();
}

void addStudent()
{
    FILE *fp;
    struct student std;
    char another ='y';
    system("cls");

    fp = fopen("record.txt","ab+");
    if(fp == NULL){
        gotoxy(10,5);
        printf("Error opening file");
        exit(1);
    }
    fflush(stdin);
    while(another == 'y')
    {
        gotoxy(10,3);
        printf("<--:ADD RECORD:-->");
        gotoxy(10,5);
        printf("Enter details of student.");
        gotoxy(10,7);
        printf("Enter Name : ");
        gets(std.name);
        gotoxy(10,8);
        printf("Enter Mobile Number : ");
        gets(std.mobile);
        gotoxy(10,9);
        printf("Enter Roll No : ");
        scanf("%d",&std.rollno);
        fflush(stdin);
        gotoxy(10,10);
        printf("Enter Course : ");
        gets(std.course);
        gotoxy(10,11);
        printf("Enter Branch : ");
        gets(std.branch);
        gotoxy(10,12);
        printf("Enter Year : ");
        gets(std.year);
        gotoxy(10,13);
        printf("Enter Subject1 Name : ");
        gets(std.subject1);
        gotoxy(10,14);
        printf("Enter Subject2 Name : ");
        gets(std.subject2);
        gotoxy(10,15);
        printf("Enter Subject3 Name : ");
        gets(std.subject3);
        gotoxy(10,16);
        printf("Enter subject1 Marks : ");
        scanf("%d",&std.subject1Marks);
        gotoxy(10,17);
        printf("Enter subject2 Marks : ");
        scanf("%d",&std.subject2Marks);
        gotoxy(10,18);
        printf("Enter subject3 Marks : ");
        scanf("%d",&std.subject3Marks);
        gotoxy(10,20);
        printf("<-----Student details Successfully added in Database!!!----->");
        std.marks = std.subject1Marks + std.subject2Marks + std.subject3Marks;
        std.percentage = std.marks*100.0/300;
        std.cgpa = std.percentage/10.0;
        std.grade = (std.percentage > 80.0 ? 'A' : (std.percentage > 60.0 ? 'B' : (std.percentage > 40.0 ? 'C' : 'F')));
        if((std.subject1Marks < 33) || (std.subject2Marks < 33) || (std.subject3Marks < 33))
        std.grade = 'F';
        if((std.grade=='A' || std.grade=='B' || std.grade=='C'))
           strcpy(std.result,"PASS");
    else
        strcpy(std.result,"FAIL");
        fwrite(&std,sizeof(std),1,fp);
        gotoxy(10,18);
        printf("Want to add of another record? Then press 'y' else 'n'.");
        fflush(stdin);
        another = getch();
        system("cls");
        fflush(stdin);
    }
    fclose(fp);
    gotoxy(10,24);
    printf("Press any key to continue.");
    getch();
    menu();
}


void viewStudent()
{
    FILE *fp;
    int i=1,j;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:VIEW RECORD:-->");
    gotoxy(10,5);
    //CHANGES
    // printf("-----------------------------------------------------------------------");
    printf("S.No | Name of Student  | Roll No  | Branch  | Year  | Marks1  | Marks2  | Marks3  | CGPA  | Grade  | Result\n");
    // printf("\n\n\n\n\n\nSubject Name1 :\t\t\tSubject Marks1 : \n\n\n\nSubject Name2 :  \t\t Subject Marks2 :\n\n\n\n Subject Name3 :\t\t Subject Marks3 :");
    // printf("S.No   Name of Student       Mobile No   Roll No  Course      Branch      Subject Name   Subject Marks  Subject Name   Subject Marks Subject Name   Subject Marks");
    gotoxy(8,6);
    printf("---------------------------------------------------------------------------------------------------------------");
    fp = fopen("record.txt","r+");
    if(fp == NULL){
        gotoxy(10,8);
        printf("Error opening file.");
        exit(1);
    }
j=8;
    while(fread(&std,sizeof(std),1,fp) == 1){
        gotoxy(10,j);
        //CHANGES
        printf("%-6d|",i);
        printf(" %-16s|",std.name);
       //printf("%-11s|",std.mobile);
        printf(" %-9d|",std.rollno);
        //printf("%-11s|",std.course);
        printf(" %-8s|",std.branch);
        printf(" %-6s|",std.year);
        //printf("\n\n\n\t\t%-15s",std.subject1);
        printf(" %-8d|",std.subject1Marks);
        //printf("\n\n\n\n\t\t%-15s",std.subject2);
        printf(" %-8d|",std.subject2Marks);
        //printf("\n\n\n\n\t\t%-15s",std.subject3);
        printf(" %-8d|",std.subject3Marks);
        printf(" %-6.2f|",std.cgpa);
        //printf("%-12f|",std.percentage);
        printf(" %-7c|",std.grade);
        printf(" %-5s",std.result);
        printf("\n");
        printf("\n");
        i++;
        j++;
    }
    fclose(fp);
    gotoxy(10,j+3);
    printf("Press any key to continue.");
    getch();
    menu();
}


void modify()
{
    char stname[20];
    FILE *fp;
    struct student std;
    system("cls");
    gotoxy(10,3);
    printf("<--:MODIFY RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to modify: ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    rewind(fp);
    fflush(stdin);
    while(fread(&std,sizeof(std),1,fp) == 1)
    {
        if(strcmp(stname,std.name) == 0){
            gotoxy(10,7);
            printf("Enter name: ");
            gets(std.name);
            gotoxy(10,8);
            printf("Enter mobile number : ");
            scanf("%s",&std.mobile);
            gotoxy(10,9);
            printf("Enter roll no : ");
            scanf("%d",&std.rollno);
            gotoxy(10,10);
            printf("Enter Course : ");
            fflush(stdin);
            gets(std.course);
            gotoxy(10,11);
            printf("Enter Branch : ");
            fflush(stdin);
            gets(std.branch);
            gotoxy(10,12);
            printf("Enter Year : ");
            fflush(stdin);
            gets(std.year);
            gotoxy(10,13);
            printf("\tEnter Subject1 Name : ");
            gets(std.subject1);
            gotoxy(10,14);
            printf("\tEnter Subject2 Name : ");
            gets(std.subject2);
            gotoxy(10,15);
            printf("\tEnter Subject3 Name : ");
            gets(std.subject3);
            gotoxy(10,16);
            printf("\tEnter subject1 Marks : ");
            scanf("%d",&std.subject1Marks);
            gotoxy(10,17);
            printf("\tEnter subject2 Marks : ");
            scanf("%d",&std.subject2Marks);
            gotoxy(10,18);
            printf("\tEnter subject3 Marks : ");
            scanf("%d",&std.subject3Marks);
            std.marks = std.subject1Marks + std.subject2Marks + std.subject3Marks;
            std.percentage = std.marks*100.0/300;
            std.cgpa = std.percentage/10.0;
            std.grade = (std.percentage > 80.0 ? 'A' : (std.percentage > 60.0 ? 'B' : (std.percentage > 40.0 ? 'C' : 'F')));
            if((std.subject1Marks < 33) || (std.subject2Marks < 33) || (std.subject3Marks < 33))
            std.grade = 'F';
            if((std.grade=='A' || std.grade=='B' || std.grade=='C'))
           strcpy(std.result,"PASS");
        else
            strcpy(std.result,"FAIL");
            gotoxy(10,19);
            printf("\t\t\n\n\n\nCGPA : %-6f",std.cgpa);
            gotoxy(10,20);
            printf("\t\tPercentage : %-12f",std.percentage);
            gotoxy(10,21);
            printf("\t\tGrade :  %-6c",std.grade);
            gotoxy(10,22);
            printf("\t\tRESULT :  %-6s",std.result);
            printf("\n");
            gotoxy(10,27);
            printf("<-----UPDATED SUCCESSFULLY----->");
            fseek(fp ,-sizeof(std),SEEK_CUR);
            fwrite(&std,sizeof(std),1,fp);
            break;
        }
    }
    fclose(fp);
    gotoxy(10,30);
    printf("Press any key to continue.");
    getch();
    menu();
}
void deleterec()
{
    char stname[20];
    FILE *fp,*ft;
    struct student std; 
    system("cls");
    gotoxy(10,3);
    printf("<--:DELETE RECORD:-->");
    gotoxy(10,5);
    printf("Enter name of student to delete record : ");
    fflush(stdin);
    gets(stname);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    ft = fopen("temp.txt","wb+");
    if(ft == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp) == 1){
        if(strcmp(stname,std.name)!=0)
            fwrite(&std,sizeof(std),1,ft);
    }
    fclose(fp);
    fclose(ft);
    remove("record.txt");
    rename("temp.txt","record.txt");
    printf("<------RECORD DELETED SUCCESSFULLY----->");
    gotoxy(10,10);
    printf("Press any key to continue.");
    getch();
    menu();
}
void search()
{
    FILE *fp;
    struct student std;
    char stname[20];
    int stroll;
    system("cls");
    gotoxy(10,3);
    printf("<--:SEARCH YOUR RESULT:-->");
    gotoxy(10,5);
    printf("Enter name of student : ");
    fflush(stdin);
    gets(stname);
    gotoxy(10,6);
    printf("Enter Roll No. of student : ");
    fflush(stdin);
    scanf("%d",&stroll);
    fp = fopen("record.txt","rb+");
    if(fp == NULL){
        gotoxy(10,6);
        printf("Error opening file");
        exit(1);
    }
    while(fread(&std,sizeof(std),1,fp ) == 1){
        if(strcmp(stname,std.name) == 0 && (stroll==std.rollno) ){
            gotoxy(10,8);
            printf("Name : %s",std.name);
            gotoxy(10,9);
            printf("Mobile Number : %s",std.mobile);
            gotoxy(10,10);
            printf("Roll No : %d",std.rollno);
            gotoxy(10,11);
            printf("Course : %s",std.course);
            gotoxy(10,12);
            printf("Branch : %s",std.branch);
            gotoxy(10,13);
            printf("Year : %s",std.year);
            printf("\n\n*---------------------------------------------------------------------------------------*");
            printf("\n|                                                                                       |");
            printf("\n|\t\tSubjects");
            printf("\t\t\tMarks\t\t\t\t\t|");
            printf("\n|                                                                                       |");
            printf("\n|---------------------------------------------------------------------------------------|");
            printf("\n|                                                                                       |");
            // printf("\n|                                                                                    |");
            printf("\n|                                                                                       |");
            printf("\n|\t\t%-15s",std.subject1);
            printf("\t\t\t%-14d\t\t\t\t|",std.subject1Marks);
            printf("\n|                                                                                       |");
            printf("\n|                                                                                       |");
            // printf("\n|                                                                                    |");
            printf("\n|\t\t%-15s",std.subject2);
            printf("\t\t\t%-14d\t\t\t\t|",std.subject2Marks);
            printf("\n|                                                                                       |");
            printf("\n|                                                                                       |");
            // printf("\n|                                                                                    |");
            // printf("\n|                                                                                    |");
            printf("\n|\t\t%-15s",std.subject3);
            printf("\t\t\t%-14d\t\t\t\t|",std.subject3Marks);
            printf("\n|                                                                                       |");
            printf("\n|---------------------------------------------------------------------------------------|");
            printf("\n|                                                                                       |");
            printf("\n|\tCGPA : %-6f",std.cgpa);
            printf("\t\tPrcentage : %-12f",std.percentage);
            printf("\t\tGrade :  %-6c\t|",std.grade);
            printf("\n|                                                                                       |");
            printf("\n|\t\t\tRESULT :  %-6s\t\t\t\t\t\t|",std.result);
            printf("\n|                                                                                       |");
            printf("\n*---------------------------------------------------------------------------------------*");
            printf("\n");
        }

        
    }
    fclose(fp);
    gotoxy(10,40);
    printf("\nPress any key to continue.");
    getch();
    menu();
}


