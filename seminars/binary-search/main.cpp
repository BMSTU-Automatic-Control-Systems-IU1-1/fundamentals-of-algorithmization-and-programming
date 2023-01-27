#include <iostream>
#include <vector>
#include "math.h"
using namespace std;

//works when the array is sorted
int binarySearch(vector<int> arr, int x)
{
    int i = 0;
    int j = (int)arr.size();
    while (i != j)
    {
        int m = (i + j)/2;
        if (x == arr[m])
            return m;
        if (x < arr[m])
            j = m;
        else
            i = m + 1;
    }
    return -1;
}


vector<int> items = { 2, 3, 5, 7, 11, 13, 17 };

int main(){
    cout << binarySearch(items, 1) << "\n";
//print -1
    cout << binarySearch(items, 7) << "\n";
//print 3
    cout << binarySearch(items, 19) << "\n";
//print -1

// *** simplified speed test ***

    items = vector<int>(10000000, 0);
    for (int i = 0; i < items.size(); i++) {
        items[i] = i;
    }
    int count = 100;

    time_t start = time(0);

    for (int i = 0; i < count; i++) {
        binarySearch(items, 7777777);
    }

    long seconds = time(0) - start;

    cout << seconds;
// about 15 seconds
}