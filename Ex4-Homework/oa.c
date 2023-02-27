//THOMAS BALZAN
//EXERCICE 4 - HOMEWORK
//VERSION 6

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//-----------------------------------
// struct
//-----------------------------------

typedef struct {
    char name[20], surname[20];
    int day,month,year;
    float n1, n2, n3, m;
} student;

//-----------------------------------
// func
//-----------------------------------

int vdate(int dd,int mm, int yy)
{    //check year
    if(yy>=1900 && yy<=9999)
    {
        //check month
        if(mm>=1 && mm<=12)
        {
            //check days
            if((dd>=1 && dd<=31) && (mm==1 || mm==3 || mm==5 || mm==7 || mm==8 || mm==10 || mm==12)){
                printf("Date is valid.\n");
                return 1;}
            else if((dd>=1 && dd<=30) && (mm==4 || mm==6 || mm==9 || mm==11)){
                printf("Date is valid.\n");
                return 1;}
            else if((dd>=1 && dd<=28) && (mm==2)){
                printf("Date is valid.\n");
                return 1;}
            else if(dd==29 && mm==2 && (yy%400==0 ||(yy%4==0 && yy%100!=0))){
                printf("Date is valid.\n");
                return 1;}
            else
                printf("Day is invalid.\n");
        }
        else
        {
            printf("Month is not valid.\n");
        }
    }
    else
    {
        printf("Year is not valid.\n");
    }

    return 0;
}
//-----------------------------------

student Enter_1_Student(int n) {
    int dd,mm,yy;
    student s;
    printf("\n------------------------");
    printf("\nStudent n%d:", n);
    printf("\n------------------------");
    printf("\nName : ");
    scanf("%s", &s.name);
    printf("Surname : ");
    scanf("%s", &s.surname);
    do {
        printf("Grade 1 (/20):", s.n1);
        scanf("%f", &s.n1);
    } while (0 > s.n1 || s.n1 > 20);
    do {
        printf("Grade 2 (/20):", s.n2);
        scanf("%f", &s.n2);
    } while (0 > s.n2 || s.n2 > 20);
    do {
        printf("Grade 3 (/20):", s.n3);
        scanf("%f", &s.n3);
    } while (0 > s.n3 || s.n3 > 20);
    do{
        printf("Enter birthday (DD/MM/YYYY format): ");
        scanf("%d/%d/%d",&s.day,&s.month,&s.year);
    }while (vdate(s.day,s.month,s.year)!=1);
    s.m = (s.n1 + s.n2 + s.n3) / 3;
    return (s);
}
//-----------------------------------
void line(){
    printf("\n------------------------");
}

void show_1_student(student s, int n) {
    printf("\n--------------\nStudent %d\n--------------", n);
    printf("\nName: %s", s.name);
    printf("\nSurname: %s", s.surname);
    printf("\nGrade 1: %.2f/20", s.n1);
    printf("\nGrade 2: %.2f/20", s.n2);
    printf("\nGrade 3: %.2f/20", s.n3);
    printf("\nAverage: %.2f/20", s.m);
    if(s.day<10 && s.month<10) {
        printf("\nBirthday: 0%d/0%d/%d", s.day, s.month, s.year);
    }
    if(s.day<10 && s.month>=10){
        printf("\nBirthday: 0%d/%d/%d", s.day, s.month, s.year);
    }
    if(s.day>=10 && s.month<10){
        printf("\nBirthday: %d/0%d/%d", s.day, s.month, s.year);
    }
    if(s.day>=10 && s.month>=10){
        printf("\nBirthday: %d/%d/%d", s.day, s.month, s.year);
    }
}
//-----------------------------------
void comparename(student *s,char * n,int N){
    int indices[N];
    int count = 0;
    int result =1;
    for (int i = 0; i < N; ++i) {
        result = strcmp((s + i)->name, n);
        if(result ==0){
            indices[count] = i;
            count++;
        }
        if (count == 0){
            printf("\nNo students have this name in the system");}
        else {
            printf("\n%d students have the same name:\n", count);
            for (int i = 0; i < count; i++) {
                show_1_student(*(s + indices[i]), (indices[i] + 1));
            }
        }
    }
}
//-----------------------------------
void comparelastname(student *s,char *n,int N){
    int indices[N];
    int count = 0;
    int result =1;
    for (int i = 0; i < N; ++i) {
        result = strcmp((s + i)->surname, n);
        if(result ==0){
            indices[count] = i;
            count++;
        }
        if (count == 0){
            printf("\nNo students have this last name in the system");}
        else {
            printf("\n%d students have the same last name:\n", count);
            for (int i = 0; i < count; i++) {
                show_1_student(*(s + indices[i]), (indices[i] + 1));
            }
        }
    }
}
//-----------------------------------
void comparebirth(student *s, int dd, int mm, int yy, int N) {
    int indices[N];
    int count = 0;
    int n[3] = {dd, mm, yy};
    for (int i = 0; i < N; ++i) {
        if ((s + i)->year == n[2] && (s + i)->month == n[1] && (s + i)->day == n[0]) {
            indices[count] = i;
            count++;
        }
    }
    if (count == 0) {
        printf("\nNo students have this date of birth in the system\n");
    } else {
        printf("\n%d students have the same date of birth:\n", count);
        for (int i = 0; i < count; i++) {
            show_1_student(*(s + indices[i]), (indices[i] + 1));
        }
    }
}
//-----------------------------------
void search(student *s,int N){
    char sn,sl;
    int dd,mm,yy;
    line();
    printf("\nSearch Menu");
    line();
    printf("\nHow would you like to look up the student?");
    line();
    int choiceSearch=0;
    do {
        printf("\n1 - By name\n2 - By last name\n3 - Birthday\n4 - Exit");
        line();
        scanf("%d",&choiceSearch);
    } while (choiceSearch<0 || choiceSearch>3);
    switch (choiceSearch) {
        case 1:{
            printf("\nPlease enter the student's name :");
            scanf("%s",&sn);
            comparename(s,&sn,N);
            break;
        }
        case 2:{
            printf("\nPlease enter the student's last name :");
            scanf("%s",&sl);
            comparelastname(s,&sl,N);
            break;
        }
        case 3:{
            do{
                printf("\nPlease enter the student's birthday (DD/MM/YYYY format):");
                scanf("%d/%d/%d",&dd,&mm,&yy);
            }while(vdate(dd,mm,yy)!=1);
            comparebirth(s,dd,mm,yy,N);
        }
    }
}
//-----------------------------------
void erase(student *s, int n) {
    char name[20], surname[20];
    int i, j, N = 0;
    printf("\nPlease enter the name and surname of the student : ");
    printf("\nName : ");
    scanf("%s", name);
    printf("\nSurname : ");
    scanf("%s", surname);

    for (i = 0; i < n; i++) {
        if (strcmp(s[i].name, name) == 0 && strcmp(s[i].surname, surname) == 0) {
            N = 1;
            break;
        }
    }
    if (N==1) {
        for (j = i; j < n - 1; j++) {
            *(s+j) = *(s + j + 1);
        }
        printf("Student record for %s %s erased.\n", name, surname);
    } else {
        printf("Student record for %s %s not found.\n", name, surname);
    }
}
//-----------------------------------
void modify(student *s, int n) {
    char name[20], surname[20];
    int i, N = 0;
    printf("\nPlease enter the name and surname of the student you want to modify: ");
    printf("\nName: ");
    scanf("%s", name);
    printf("\nSurname: ");
    scanf("%s", surname);

    for (i = 0; i < n; i++) {
        if (strcmp(s[i].name, name) == 0 && strcmp(s[i].surname, surname) == 0) {
            N = 1;
            break;
        }
    }
    if (N == 1) {
        printf("\nStudent record for %s %s found.\n", name, surname);
        printf("\nEnter the new data for the student:\n");
        printf("Name: ");
        scanf("%s", s[i].name);
        printf("Surname: ");
        scanf("%s", s[i].surname);
        do{
            printf("Grade 1 (/20): ");
            scanf("%f", &s[i].n1);
        }while (0 > s[i].n1 || s[i].n1 > 20);
        do{
            printf("Grade 2 (/20): ");
            scanf("%f", &s[i].n2);
        }while (0 > s[i].n2 || s[i].n2 > 20);
        do{
            printf("Grade 3 (/20): ");
            scanf("%f", &s[i].n3);
        }while (0 > s[i].n3 || s[i].n3 > 20);
        do{
            printf("\nBirthday (DD/MM/YYYY format):");
            scanf("%d/%d/%d",&s[i].day,&s[i].month,&s[i].year);
        }while(vdate(s[i].day,s[i].month,s[i].year)!=1);
        printf("New data for %s %s updated.\n", s[i].name, s[i].surname);
    } else {
        printf("Student record for %s %s not found.\n", name, surname);
    }
}
//-----------------------------------

int numberstudent() {
    int n;
    do {
        printf("\nHow many students do you want to enter ? :  ");
        scanf("%d", &n);
    } while (n < 0);
}

//-----------------------------------

student Enter_n_student(student *s, int d, int f) {
    int i;
    for (i = d; i < f; i++) {
        *(s + i) = Enter_1_Student(i + 1);
        system("pause");
    }
}

//-----------------------------------

void show_n_student(student *s, int n) {
    int i;
    printf("\n------------------------");
    printf("\n   Results : %d students  ", n);
    printf("\n------------------------");
    for (i = 0; i < n; i++)
        show_1_student(*(s + i), i + 1);
}
//-----------------------------------
//----------BONUS CSV PART-----------
//-----------------------------------
void entercsv(student *s, int N){
    FILE *file;
    char filename[50]="StudentData.csv";
    file = fopen(filename, "w");
    if(file==NULL){
        printf("Error opening student file");
        return;
    }
    for (int i = 0; i < N; ++i) {
        fprintf(file, "%s,%s,%f,%f,%f,%f,%d,%d,%d", (s+i)->name, (s+i)->surname, (s+i)->n1, (s+i)->n2, (s+i)->n3, (s+i)->m,
                (s+i)->day, (s+i)->month, (s+i)->year);
    }
    printf("\nNew data entered into student file");
    fclose(file);
}
//-----------------------------------
void showcsv(student *s, int N){
    FILE *file;
    char filename[50]="StudentData.csv";
    int count=0;
    file = fopen(filename, "r");
    if(file==NULL){
        printf("Error opening student file");
        return;
    }
    for (int i = 0; i < N; ++i) {
        fscanf(file, "%s,%s,%f,%f,%f,%f,%d,%d,%d", &s[i].name, &s[i].surname, &s[i].n1, &s[i].n2, &s[i].n3, &s[i].m,
               &s[i].day, &s[i].month, &s[i].year);
    }
    show_n_student(s,N);
    fclose(file);
}
//-----------------------------------
//-----------MAIN PROGRAM------------
//-----------------------------------
void exo4() {
    student *s;
    int n, g, N = 0;
    char sn,sl,sd;
    do {
        do {
            printf("\n------------------------");
            printf("\n          Menu ");
            printf("\n------------------------");
            printf("\n 1 - Enter Student");
            printf("\n 2 - Show Student");
            printf("\n 3 - Search Student");
            printf("\n 4 - Erase Student");
            printf("\n 5 - Modify Student");
            printf("\n 6 - Save data in file ");
            printf("\n 7 - Show saved data ");
            printf("\n 8 - END ");
            printf("\n------------------------");
            printf("\n What is your choice ? : ");
            printf("\n------------------------\n");
            scanf("%d", &g);
            if (scanf("%c", &sn) != 15 || !isdigit(sn)) {
                fflush(stdin);
                printf("Please enter a valid choice");
                printf("\n");
                system("pause");
                continue;
            }
            g = sn - '0';
        } while (g <= 0 || g >6);

        if (g == 1) {
            if (N == 0) {
                n = numberstudent();
                s = (student *)malloc(n * sizeof(student));
                Enter_n_student(s, 0, n);
                N = N + n;
            } else {
                n = numberstudent();
                s = (student *)realloc(s, (N + n) * sizeof(student));
                Enter_n_student(s, N, N + n);
                N = N + n;
            }
        }
        if (g == 2) {
            show_n_student(s, N);
            printf("\n");
            system("pause");
        }
        if (g == 3){
            search(s,N);
            printf("\n");
            system("pause");
        }
        if (g == 4){
            erase(s,N);
            printf("\n");
            N--;
            s = (student *)realloc(s,(N) * sizeof(student));
            system("pause");
        }
        if (g == 5){
            modify(s,N);
            printf("\n");
            system("pause");
        }
        if (g == 6){
            entercsv(s,N);
            printf("\n");
            system("pause");
        }
        if (g == 7){
            showcsv(s,N);
            printf("\n");
            system("pause");
        }
    }while (g != 8);
    printf("\n");
    printf("\nYou chose to end the program");
    printf("\nSee you next time");

    free(s);
}
