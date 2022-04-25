#include <iostream>

int main() {
    int n;
    double t;
    std::cin>>n;
    double lst1[n];
    double lst2[n];
    for(int i=0; i<n; i++){
        double x,y;
        std::cin>>x>>y;
        if (x<0){
            t += 0-x;
            x = 0;
        }
        if (y<0){
            t += 0-y;
            y = 0;
        }
        lst1[i] = x;
        lst2[i] = y;
    }
    double x_max = 0;
    double y_max = 0;
    for(int i=0; i <n; i++){
        if (x_max < lst1[i]){
            x_max = lst1[i];
        }
    }
    for(int i=0; i <n; i++) {
        if (y_max < lst2[i]) {
            y_max = lst2[i];
        }
    }
    for(int i=0; i <n; i++) {
        t += x_max - lst1[i];
        t += y_max - lst2[i];
    }

    std::cout << t << std::endl;
    return 0;
}
