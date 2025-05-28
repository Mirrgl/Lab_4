#include <iostream>
#include <ctime>

using namespace std;

long XORShift(int step) {
    long seed = time(nullptr) + step;
    seed ^= (seed << 21);
    seed ^= (seed >> 35);
    seed ^= (seed << 4);
    return seed;
}

int main() {
    for (int i = 0; i < 10; i++) {
        cout << XORShift(i) << " ";
    }

    return 0;
}