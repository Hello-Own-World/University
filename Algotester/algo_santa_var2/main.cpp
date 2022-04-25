#include <iostream>
using namespace std;

int main() {
    long long int l, x, y, z, sum, counter=0;
    long long int r;
    cin >> l;
    cin >>r;
    x = l;


    while (x != r+1){
        sum = 0;
        z = x;
        while(z>0){
            y = z%10;
            sum += y;
            z = z/10;
        }
        if (sum % 9 == 0){
            counter++;
            break;
        }
        x ++;

    } // get x that represents first multiple to 9

    while( x <= r){
        if( x + 999999999999 < r){
            x += 999999999999;
            counter += 111111111111;
        } else{
            break;
        }
    }




    while( x <= r){
        if( x + 999999999 < r){
            x += 999999999;
            counter += 111111111;
        } else{
            break;
        }
    }

    while( x <= r){
        if( x + 999999 < r){
            x += 999999;
            counter += 111111;
        } else{
            break;
        }
    }

    while( x <= r){
        if( x + 99999 < r){
            x += 99999;
            counter += 11111;
        } else{
            break;
        }
    }

    while( x <= r){
        if( x + 9999 < r){
            x += 9999;
            counter += 1111;
        } else{
            break;
        }
    }


    while( x <= r){
        if( x + 999 < r){
            x += 999;
            counter += 111;
        } else{
            break;
        }
    }
    while( x <= r){
        if( x + 99 < r){
            x += 99;
            counter += 11;
        } else{
            break;
        }
    }
    while( x < r){
        if( x + 9 <= r){
            x += 9;
            counter += 1;
        } else{
            break;
        }
    }









    cout << counter;

    return 0;
}
