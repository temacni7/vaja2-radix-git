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

int main(int argc, const char* argv[]) {
    vector<unsigned char> A;

    if (argc != 2) {
        return 0;
    }

    if (!Branje_Stevil(A, argv[1])) {
        return 0;
    }

    return 0;
}