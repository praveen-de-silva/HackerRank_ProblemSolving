#include <iostream>
#include <cmath>

using namespace std;

int powerSumHelper(int X, int N, int num) {
    if (X == 0) {
        return 1;  // Found a valid combination
    }
    if (X < 0 || pow(num, N) > X) {
        return 0;  // No valid combination
    }

    // Include current number `num` in sum OR skip it
    return powerSumHelper(X - pow(num, N), N, num + 1) + powerSumHelper(X, N, num + 1);
}

int powerSum(int X, int N) {
    return powerSumHelper(X, N, 1);
}