/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

int main() {
    FILE *file, *file1;
    char Str[1000];
    float Ti, x = 0;
    time_t t = time(NULL);
    struct tm* aTm = localtime(&t);
    file1 = fopen("log - file", "at");
    fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    fprintf(file1, "Programm started.\n");
    printf("Enter name of file: ");
    scanf("%s", Str);
    printf("Enter X: ");
    scanf("%f", &x);
    file = fopen(Str,"wb");
    fprintf(file, "%f", x);
    fclose(file);
    file = fopen(Str, "rb");
    fscanf(file, "%f", &x);
    fclose(file);
    fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    fprintf(file1, "Parameters file opened. X = %f.\n", x);
    printf("Choose, txt or binary file: ");
    scanf("%s", Str);
    if (Str == "txt") {
        printf("Enter name of file: ");
        scanf("%s", Str);
        file = fopen(Str, "wt");
        Ti = x / (1 - (x * x) / (3 - (x * x) / (5 - (x * x) / 7)));
        fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
        fprintf(file1, "Expression calculated. Ti = %f.\n", Ti);
        fprintf(file, "%f", Ti);
        fclose(file);
    }
    else {
        printf("Enter name of file: ");
        scanf("%s", Str);
        file = fopen(Str, "wb");
        Ti = x / (1 - (x * x) / (3 - (x * x) / (5 - (x * x) / 7)));
        fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
        fprintf(file1, "Expression calculated. Ti = %f.\n", Ti);
        fwrite(&Ti, sizeof(float), 1, file);
        fclose(file);
    }
    fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    fprintf(file1, "Output file saved.\n");
    fprintf(file1, "[%04d/%02d/%02d %02d:%02d:%02d]\t", aTm->tm_year + 1900, aTm->tm_mon + 1, aTm->tm_mday, aTm->tm_hour, aTm->tm_min, aTm->tm_sec);
    fprintf(file1, "Program ended.\n\n\n\n");
    fclose(file1);
}
 */