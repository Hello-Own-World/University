#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

int main() {
    vector<int> time(43200, 1);
    int n;
    cin >> n;
    int start, end, temp_h, temp_min, seconds;

    for (int i = 0; i < n; ++i) {
        cin >> temp_h >> temp_min >> seconds;
        temp_h -= 8;
        seconds += temp_h*3600 + temp_min*60;
        start = seconds;
        cin >> temp_h >> temp_min >> seconds;
        temp_h -= 8;
        seconds += temp_h*3600 + temp_min*60;
        end = seconds;
        std::fill(time.begin()+start, time.begin()+end, 0);
    }
    cout << std::accumulate(time.begin(), time.end(), 0);

    return 0;
}
/*
2
08 30 00
10 00 00
11 00 00
12 23 05

 4
 08 30 00 09 00 00
 10 00 00 18 00 00
 08 00 00 08 10 00
 08 05 00 08 20 00
 */
