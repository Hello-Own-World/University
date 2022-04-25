#include <stdio.h>
#include <math.h>

int main() {
    double a, b, x, k, step, eps, std_res;
    a = 0.1;
    b = 1;
    x = a;
    k = 10;
    step = 0.01;
    eps = 1e-500;
    double ls_cos[100] = {};
    double ls_SN[100] = {};
    double ls_SE[100] = {};
    double ls_X[100] = {};
    int i = 0;

    while (a<=x && x<=b){

        ls_X[i] = x;
        //Обчислення cos
        std_res = cos(x);
        ls_cos[i] = std_res;



        double sum_an = 0;

        double an = (-1 * x * x ) / 2 ; // при n = 1
        sum_an += an;
        // Обчислення суми ряду для заданого n
        for (int n=2; n<=10; n++){
            an = an * (( -1 * x * x ) / (4 * n * n + 6 * n + 2));
            //printf("\nan = %.10f", an);
            sum_an += an;
        }
        double fin_res = 1 + sum_an;
        ls_SN[i] = fin_res;

        double an1 = (-1 * x * x ) / 2 ;
        double an1_sum = 0;
        an1_sum += an1;
        double n = 2;
        // Обчисленя суми для заданої точності
        while(an1 < -eps || an1 > eps){
            an1 = an1 * (( -1 * x * x ) / (4 * n * n + 6 * n + 2));
            //printf("\nan = %.20f ", an1);
            an1_sum += an1;
            n++;
        }
        double fin_res2 = 1 + an1_sum;
        ls_SE[i] = fin_res2;

        x+=step;
        i++;
    }

    int d = sizeof (ls_cos)/8; // виведення списку косинусів/ for double
    for (i=0; i<d; i++){
        printf("\n X = %f   SN = %f     SE = %f     Y = %f", ls_X[i], ls_SN[i], ls_SE[i], ls_cos[i]);
    }

    return 0;
}
