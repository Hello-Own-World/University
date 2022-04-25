#include <iostream>
using namespace std;

int main() {
   int l, x, y, z, sum, counter=0;
   long long int r;
   cin >> l;
   cin >>r;
   x = l;


   while (x != r+1){
       sum = 0;
       z = x;
       while(z>0){ //get sum of digits of number
           y = z%10;
           sum += y;
           z = z/10;
       }
       if (sum % 9 == 0){
           break;
       }
       x ++;
   }
   while(x<r){
       x = x+9;
       counter++;
   }

    cout << counter;

    return 0;
}
