#include <iostream>
#include <CString>
#include <ctype.h>
#include <string>

using namespace std;


int is_digit(char* lett, int* arr_int, int* count)
{
    char word1 = *lett;

    if ((word1 >= '0') && (word1 <= '9')) {  //так перевірка менше часу займає, + лайфхак, використовуються коди аскі
        //cout << word1 << endl;
        *(arr_int + *count) = (int) (word1-'0');
        *count = *count + 1;
        return 1;
    }
    return 0;
}

int sort_int_point(int* arr_int, int count) {
    for (int j = 0; j < count; j++) {

        int last_max = 0;
        int i, r = 0;

        for ( i = j; i < count; i++)
        {
            if (*(arr_int + i) >= last_max) {
                r = i;
                last_max = *(arr_int + i);
            }
        }
        int buff_int = *(arr_int + j); //Створюємо буфер значень які буд перезапис

        *(arr_int + j) = last_max; //перезаписуєм перші знач

        *(arr_int + r) = buff_int; //буфер присвоюєм тим де були макс

    }

        return 0;
}


int main() {

    char str[255];
    int arr_of_int[255];
    bool arr_of_pointers[255] = { 0 };

    int counter = 0, i=0;

    cout << "Type string: ";
    gets(str); //string return


    for (int i = 0; i < strlen(str); i++)
        arr_of_pointers[i] = is_digit(&str[i], &arr_of_int[0], &counter);

    sort_int_point(&arr_of_int[0], /* &arr_of_pointers[0], */ counter);

    for (i = 0, counter=0; i < strlen(str); i++)
        if (arr_of_pointers[i]) str[i] = (arr_of_int[counter++] + '0');

    for ( i = 0; i < strlen(str); i++) {
        cout << str[i];
    }
    return 0;
}