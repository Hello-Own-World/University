//
// Created by yushc on 22.10.2021.
//
#include<iostream>
#ifndef LABA_5_AP_FUNCTIONS_H
#define LABA_5_AP_FUNCTIONS_H

using namespace std;
int repl_row_col(int **matr,int row,int col,int n){
    cout << **matr<< " row= "<<row<<" column = "<< col<<"\n";
    //create new matrix
    int **temp = new int *[n];
    for (int i = 0; i<n; i++){
        temp[i] = new int [n];
    }
    //create new row
    for (int i = 0; i < n; i++){
        temp[i][col] = matr[row][i];
    }
    for (int i = 0; i < n; i++){
        temp[row][i] = matr[i][col];
    }
    // assign new rows to matrix
    for (int i = 0; i < n; i++){
        *(*(matr+i)+col) = temp[i][col];
    }
    for (int i = 0; i < n; i++){
        *(*(matr+row)+i) = temp[row][i];
    }

    return 0;

}

#endif //LABA_5_AP_FUNCTIONS_H
