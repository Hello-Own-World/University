#include <iostream>
#include <vector>
using namespace std;

struct col{
    int x, y;
};

int main() {
    int XL, XR, r, n;
    vector<col> arr_col;
    cin >> XL >> XR >> r >> n;

    for (int i = 0; i < n; ++i) {
        col z{};
        cin >> z.x >> z.y;
        arr_col.push_back(z);
    }




    return 0;
}
