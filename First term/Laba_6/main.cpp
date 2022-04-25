#include <iostream>
#include <cstring>
#include <algorithm>
#include <ctype.h>
#include <vector>
using namespace std;
int is_digit(char *lett, int *arr_int, char *arr_point, int *count) {
    char word1 = *lett;

    char lst[10] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};
    for (int i = 0; i<10; i++){
        if (word1 == lst[i]){
            *(arr_int + *count) = i;
            *(arr_point + *count) = *lett;
            *count = *count+1;
        }
    }

    return 0;
}

int sort_int_point(int *arr_int, char *arr_point, int *count, char *str){
    char arr_of_pointers_2[255] = {};

    for (int i = 0; i < 255; i++){
        arr_of_pointers_2[i] = *(arr_point+i);
    }

    for (int j = 0; j < *count; j++) {
        int last_max = 0;
        char last_point;
        int r=0;
        for (int i = 0+j; i <= *count; i++) {
            if (*(arr_int + i) > last_max) {
                r = i;
                last_max = *(arr_int + i);
                last_point = *(arr_point + i);
            }
        }
        int buff_int = *(arr_int + j); //Створюємо буфер значень які буд перезапис
        char buff_point = *(arr_point + j);

        *(arr_int + j) = last_max;  //перезаписуєм перші знач
        *(arr_point + j) = last_point;

        *(arr_int + r) = buff_int;  //буфер присвоюєм тим де були макс
        *(arr_point + r) = buff_point;

    }
    for (int k = 0; k < *count; k++){
        *(arr_point + k) = *(arr_int + k);
        cout <<  *(arr_int + k)  ;

    }

    return 0;
}

int main() {
    bool choose = true;

    if (choose) {

        char str[255];
        int arr_of_int[255] = {};
        char arr_of_pointers[255] = {};

        int counter = 0;

        cout << "Type string: ";
        gets(str);  //string return


        for(int i = 0; i < strlen(str); i++){
            is_digit(&str[i], &arr_of_int[0], &arr_of_pointers[0], &counter);
        }


        sort_int_point(&arr_of_int[0], &arr_of_pointers[0], &counter, &str[0]);

    }

    return 0;
}
