#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

bool Branje_Stevil(vector<unsigned char>& vec, const char filename[]) {
    ifstream input(filename);
    int st;

    if (!input.is_open()) {
        return false;
    }

    while (input >> st) {
        if (st < 0 || st > 255) {
            input.close();
            return false;
        }

        vec.push_back(static_cast<unsigned char>(st));
    }

    input.close();
    return true;
}

void Izpis_Stevil(const vector<unsigned char>& vec);
void BinarniRadixSort(vector<unsigned char>& A);

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

void BinarniRadixSort(vector<unsigned char>& A) {
    size_t n = A.size();
    if (n <= 1) {
        return;
    }

    vector<unsigned char> B(n);

    for (int k = 0; k < 8; k++) {
        int C[2] = { 0, 0 };

        for (size_t i = 0; i < n; i++) {
            int bit = (A[i] >> k) & 1;
            C[bit]++;
        }

        C[1] += C[0];

        for (int i = static_cast<int>(n) - 1; i >= 0; i--) {
            int bit = (A[i] >> k) & 1;
            B[C[bit] - 1] = A[i];
            C[bit]--;
        }

        A = B;
    }
}

void Izpis_Stevil(const vector<unsigned char>& vec) {
    ofstream output("out.txt");

    for (size_t i = 0; i < vec.size(); i++) {
        output << static_cast<int>(vec[i]);
        if (i + 1 < vec.size()) {
            output << ' ';
        }
    }

    output.close();
}