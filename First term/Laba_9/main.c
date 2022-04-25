#include <stdio.h>
#include <stdlib.h>

int count_lett(FILE *f2, int n2, int n3, int MAXLINE, char str1[]){
    if (n2>0){
        fgets(str1, MAXLINE, f2);
        int i = 0;
        while ( str1[i] != ' '){
            n3++;
            i++;
        }
        printf("\nThere are %d characters in first word of second file.", n3);
    } else{
        printf("Second file is empty.");
    }
    return 0;
}

int add_str(FILE *f,char str[], int n){

    for (int i = 0; i < n ; i++){ // print sentences to file
        printf("Enter line #%d:\n", i+1);
        fflush(stdin);
        gets(str);
        fputs(str ,f);
        fputs("\n", f);
    }
    fclose(f);
    return 0;
}

int copy_to_sec_file(FILE *f1, FILE *f2, int n, int n2, char str1[], int MAXLINE){
    for (int i = 0; i < n ; i++){
        fgets(str1, MAXLINE, f1);
        if (str1[0] != 'A' && str1[0] != 'a'){
            fputs(str1 ,f2);
            n2++;
            printf("%s", str1); // for printing file
        }
    }
    return n2;
}

int main() {
    int n, n2=0, n3=0;
    int const MAXLINE = 255;
    char str[MAXLINE], str1[MAXLINE];

    while(1){
        printf("How many rows would you like to have?:");
        scanf("%d", &n);
        if (n > 0 || n ){
            break;
        } else{
            printf("Wrong input!\n");
        }
    }

    FILE *f1;
    FILE *f2;

    f1 = fopen("First_file.txt", "w");
    add_str(f1, str, n);
    fclose(f1);

    f1 = fopen("First_file.txt", "r");
    f2 = fopen("Second_file.txt", "w");

    printf("\nWriting to second file...\n\n");

    n2 = copy_to_sec_file(f1, f2, n, n2, str1, MAXLINE);
    fclose(f2);
    fclose(f1);

    f2 = fopen("Second_file.txt", "r");
    count_lett(f2, n2, n3, MAXLINE, str1);
    fclose(f2);
    return 0;
}
