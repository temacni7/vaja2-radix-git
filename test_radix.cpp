#include "radix.h"
#include <iostream>
#include <cassert>
#include <vector>
using namespace std;

// Test 1: preverimo da sort pravilno sortira navaden seznam
void test_osnovno_sortiranje() {
    vector<unsigned char> A = {5, 3, 1, 8, 2};
    BinarniRadixSort(A);
    assert(A[0] == 1);
    assert(A[1] == 2);
    assert(A[2] == 3);
    assert(A[3] == 5);
    assert(A[4] == 8);
    cout << "Test 1 (osnovno sortiranje): OK" << endl;
}

// Test 2: preverimo da sort deluje z enim elementom
void test_en_element() {
    vector<unsigned char> A = {42};
    BinarniRadixSort(A);
    assert(A[0] == 42);
    cout << "Test 2 (en element): OK" << endl;
}

// Test 3: preverimo da sort deluje s praznim vektorjem
void test_prazen_vektor() {
    vector<unsigned char> A = {};
    BinarniRadixSort(A);
    assert(A.size() == 0);
    cout << "Test 3 (prazen vektor): OK" << endl;
}

// Test 4: preverimo da sort deluje z mejnimi vrednostmi (0 in 255)
void test_mejne_vrednosti() {
    vector<unsigned char> A = {255, 0, 128, 1};
    BinarniRadixSort(A);
    assert(A[0] == 0);
    assert(A[1] == 1);
    assert(A[2] == 128);
    assert(A[3] == 255);
    cout << "Test 4 (mejne vrednosti): OK" << endl;
}

// Test 5: preverimo branje iz datoteke
void test_branje_datoteke() {
    // ustvarimo testno datoteko
    FILE* f = fopen("test_branje.txt", "w");
    fprintf(f, "10 20 30");
    fclose(f);

    vector<unsigned char> A;
    bool rezultat = Branje_Stevil(A, "test_branje.txt");
    assert(rezultat == true);
    assert(A.size() == 3);
    assert(A[0] == 10);
    assert(A[1] == 20);
    assert(A[2] == 30);
    cout << "Test 5 (branje datoteke): OK" << endl;
}

int main() {
    test_osnovno_sortiranje();
    test_en_element();
    test_prazen_vektor();
    test_mejne_vrednosti();
    test_branje_datoteke();
    cout << "Vsi testi uspesni!" << endl;
    return 0;
}
