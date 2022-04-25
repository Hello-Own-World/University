#include "stdio.h"

int main(){
    double eps = 0.0001;
    double sum;
    double n;
    printf("Enter value for n:");
    scanf("%lf", &n);

    double an = 1/((3*n-2)*(3*n+1));
    printf("eps = %lf\n", eps);
    printf("n = %lf; an = %lf;\n", n, an);

    while (an > eps){
        sum += an;
        an = (an*(3*n-2))/(3*n+4); // використання рекурентної формули
        n++;
        //printf("n = %lf; an = %lf;\n", n, an);
        if (an<eps) {
            break;
        }
    }
    printf("Result:\nn = %lf, an = %lf, sum = %lf ", n, an, sum);
    return 0;
}
