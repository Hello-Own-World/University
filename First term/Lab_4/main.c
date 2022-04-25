#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int arr[100];
int len_real_arr;


int del_el_arr(int ind){    //видаляє елемент за індексом, зменшує розмір спр. масиву
    arr[ind] = 0;
    for (int i = 0 ;i<100 ;i++ ){
        if(i >= ind) {
            arr[i] = arr[i+1];
        }
    }
    len_real_arr --;

    printf("\n\n Array with deleted %d th element", ind);
    for (int i=0;i<len_real_arr;i++) {
        printf("\n i = %d x =%d", i, arr[i]);
    }
    return 0;
}


int add_elem(){     // додає елемент після перш парного. Збільш мас.
    for (int i =0; i < len_real_arr; i++){
        if (arr[i]%2 == 0){
            printf("\n\nFirst even number: %d", arr[i]);
            int z = len_real_arr; // уже є на 1 більше за порядковий
            for (int g = 0;g<len_real_arr-i;g++){
                arr[z] = arr[z-1];
                z--;
            }
            arr[i+1] = arr[i-1] +2;

            break;
        }
    }
    len_real_arr++;
    printf("\nArray with additional element");
    for (int i=0;i<len_real_arr;i++) {
        printf("\n i = %d x =%d", i, arr[i]);
    }
    return 0;
}


int main() {

    while(1) {
        printf("Enter length of array(<=100):");
        scanf("%d", &len_real_arr);
        printf("%d", len_real_arr);
        if (len_real_arr > 100) {
            printf("\nWrong value! Try again\n");
        }
        else{
            break;
        }

    }
    srand(time(0)); // необхідний параметр для правильн. random

    for (int i=0;i<len_real_arr;i++){
        int r = rand()%50;
        arr[i] = r;
    }
    printf("\nCreated array of random integers:");
    for (int i=0;i<len_real_arr;i++) {
        printf("\n i = %d x =%d", i, arr[i]);
    }

    while (1) {
        printf("\n Enter which element you would like to delete:");
        int ans2;
        scanf("%d", &ans2);
        if(ans2 < len_real_arr) {
            del_el_arr(ans2);
            break;
        }
        else{
            printf("Wrong value! Try again");
        }
    }
    add_elem();
    return 0;
}
