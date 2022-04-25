#include <stdio.h>
#include <stdlib.h>

struct student{
    char name[50];
    char home_address[50];
    char group[50];
    double ranking;
};
struct student get_new_stud(){
    struct student a;
    printf("Enter in one line your name, surname and patronym:\n");
    gets(a.name);
    gets(a.name);
    printf("Enter your home address:\n");
    gets(a.home_address);
    printf("Enter your group:\n");
    gets(a.group);
    printf("Enter your ranking:\n");
    scanf("%lf", &a.ranking);
    return a;
}
int prnt_file(int n,FILE *fptr){//function that reads file & prints into console
    struct student c;
    fptr = fopen("Student.bin", "rb");
    for (int i = 0; i<n; i++) {
        fread(&c, sizeof(struct student), 1, fptr);
        printf(" Name: %s\n Home address: %s\n Group: %s\n Rating: %lf\n\n", c.name, c.home_address, c.group,
               c.ranking);
    }
    fclose(fptr);
    return 0;
}

int add_stud(FILE *fptr) {
    fptr = fopen("Student.bin", "ab");
    int n2;
    printf("How many students you want to add?:");
    scanf("%d", &n2);

    for (int i = 0; i < n2; i++){
        struct student b = get_new_stud();
        fwrite(&b, sizeof(struct student), 1, fptr);
    }
    fclose(fptr);

    return n2;
}

int del_stud(FILE *fptr,int n, struct student* lst) {
    int counter=0;
    double x;
    printf("Enter min value of rating:\n");
    scanf("%lf", &x);
    printf("All students with rating below %lf will be deleted\nRemaining students:\n", x);

    fptr = fopen("Student.bin", "wb");
    for (int i = 0; i<n; i++){
        if (lst[i].ranking > x){
            counter++;
            fwrite(&lst[i], sizeof(struct student), 1, fptr);
        }
    }
    fclose(fptr);

    return counter;
}



int main() {
    //create file with students
    int n;
    printf("How many students you want to add?:");
    scanf("%d", &n);

    struct student c;
    struct student lst[10];

    FILE *fptr;
    fptr = fopen("Student.bin", "wb");
    if(fptr == NULL)
    {
        printf("Error!");
        exit(1);
    }

    for (int i = 0; i<n; i++){
        struct student b = get_new_stud();
        lst[i] = b;
        fwrite(&b, sizeof(struct student), 1, fptr);
    }

    fclose(fptr);

    prnt_file(n, fptr);

    int counter = del_stud(fptr, n, lst);

    prnt_file(counter, fptr);

    int n2 = add_stud(fptr);

    printf("File with added students");

    prnt_file(counter+n2, fptr);

    return 0;
    }

