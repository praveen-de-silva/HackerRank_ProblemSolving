#include <bits/stdc++.h>

using namespace std;

int getTenPow(int num) {
    /*
    * this gives the 10's power for the number
    */
    int power = 0;
    int crntNum = num;
    
    while (crntNum >= 10) {
        crntNum = crntNum / 10;
        power++;
    }
    
    return power;
}

int getDigitLength(int num) {
    /*
    * this gives the number of digits, the number has
    */
    return getTenPow(num) + 1;
}

bool isKapreka(int num) {
    /*
    * chech whether a number is Kapreka
    */
    int digitLength = getDigitLength(num); // number of digits
    
    long long int numSquar = pow(num, 2);
    long long int div = pow(10, digitLength);
    
    return ((numSquar) / (div) + (numSquar) % (div) == num);
}

void kaprekarNumbers(int p, int q) {
    int flag = 0;
    
    for (int i=p; i<=q; i++){
        if (isKapreka(i)) {
            cout << i << " ";
            flag = 1;
        }
    }
    
    if (flag == 0) {
        cout << "INVALID RANGE";
    }
}