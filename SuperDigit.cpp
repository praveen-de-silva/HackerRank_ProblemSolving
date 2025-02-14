#include <iostream>

using namespace std;

int findSuperDigit(long num) {
    if (num < 10) {
        return num;
    }
    return findSuperDigit((num%10) + findSuperDigit(num/10));
    
}

/*
    --------------------------------------------------
    findReqNum - Method 01 (some isseus are available)
    --------------------------------------------------


long findReqNum(int n, int k) {
    int fac = 10, crnt = n;
    long reqNum = n;
    
    while (crnt/10) {
        fac *= 10;
        crnt /= 10;
    }
    
    for (int i=k-1; i>0; i--) {
        reqNum = reqNum * fac + n;
    }
    
    return reqNum;
}
*/

/*
    -----------------------------
    findReqNum - Method 02 (Best)
    -----------------------------
*/

long findReqNum(string n, int k) {
    int sum = 0;
    
    for (char dig : n) {
        sum +=  dig - '0';    
    }
    
    return sum * k;
}

int superDigit(string n, int k) {
    long p = findReqNum(n, k);
    int result = findSuperDigit(p);
    
    cout << result << endl;
    return result;
}

int main() {

    superDigit("100", 2);

    return 0;
}