//#include <iostream>
//#include <algorithm>
//
//int main() {
//    long int k, n, res = 100000;
//    std::cin >> n >> k;
//    for (long int i = 1; i < 100000; ++i) {
//        res = std::min( abs(k-i) + std::min(n%i, i-n%i),  res);
//    }
//    std::cout << res;
//    return 0;
//}

#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    int a[10];
    for(int i = 0; i < n; ++i) cin >> *(a + i);
    sort(a, a + n);
    double res = a[0];
    for (int i = 1; i < n; ++i) res = (res + a[i]) / 2;
    printf("%.7lf", res);
    return 0;
}