#include "radix.h"
#include <iostream>
using namespace std;

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;
    if (argc != 2) {
        return 0;
    }
    if (!Branje_Stevil(A, argv[1])) {
        return 0;
    }
    BinarniRadixSort(A);
    Izpis_Stevil(A);
    return 0;
}
