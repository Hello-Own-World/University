#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include "functions.h"

using namespace std;
int n;

int main() {
    srand(time(NULL)); //Create seed for pseudo random

    while (true) {
        cout << "\nEnter dimension of matrix:";
        cin >> n;

        if (n>1){
            break;
        }
        printf("Wrong value!");
    }


    int **matr = new int *[n];// arr of pointers
    for (int a = 0; a < n; a++)
        matr[a] = new int[n];//memory for elem in arr

    for (int a = 0; a < n; a++)
        for (int b = 0; b < n; b++)
            matr[a][b] = rand() % 10;//fill natrix


    for (int a = 0; a < n; a++) {
        for (int b = 0; b < n; b++)
            cout << matr[a][b] << " ";
        cout << "\n";
    }

    for (int i = 0;i<n;i++){
        for (int j =0;j<n;j++) {
            //cout<<i<<j<<"\n";
            if (matr[0][i] == matr[j][0]){
                repl_row_col(matr,j,i,n);
                for (int a = 0; a < n; a++) {
                    for (int b = 0; b < n; b++)
                        cout << matr[a][b] << " ";
                    cout << "\n";
                }
            }
        }
    }


}