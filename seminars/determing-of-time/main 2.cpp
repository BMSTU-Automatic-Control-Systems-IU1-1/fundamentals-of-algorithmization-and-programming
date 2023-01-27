#include <iostream>
using namespace std::chrono;
using namespace std;

void static_array_iterations(){
    const int MAX = 10000;
    int values[MAX];
    for(int i = 0; i < MAX; i++){
        values[i] = 0;
    }
}

void pointer_iterations(){
    const int MAX = 10000;
    int values[MAX];
    int* pointer = values;
    for (int i = 0; i < MAX; i ++){
        *pointer = 0;
        pointer++ ;
    }
}


int main() {
    cout <<"Calculating start" << endl;
    auto start = high_resolution_clock::now();

    clock_t startTime = clock();

    pointer_iterations();
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);

    cout << double (clock() - startTime) / double (CLOCKS_PER_SEC) << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    return 0;
}


