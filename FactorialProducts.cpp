#include <iostream>
// #include <vector>
#include <stack>
#include <set>
// #include <cmath>

using namespace std;

int factorial(int num) {
    int res = 1;
    
    for (int i=1;i<=num;i++) {
        res=res*i;
    }
    return res;
}

int F(string a) {
    int res = 1;
    int crnt;
    for (char dig : a) {
        crnt = dig - '0';
        res *= factorial(crnt);
    }
    return res;
}

int generateNum(stack<int> stackNums) {
    int res = 0;
    int tenMul = 1;
    
    while (!stackNums.empty()) {
        res += stackNums.top() * tenMul;
        stackNums.pop();
        tenMul *= 10;
    }
    
    return res;
}

int main() {
    stack<int> nums;
    int target = 2073600;
    int maxPosDig = 9;
    set<int> crntDigs;
    
    while (target > 1) {
        //  set Maximum Possible Digit
        if (factorial(maxPosDig) > target) {
            while (factorial(maxPosDig) > target) {
                maxPosDig--;
            }
        }
        cout << maxPosDig << endl;
        
        // add next max possible digit if CAN
        for (int tempDig = maxPosDig; tempDig>1; tempDig--) {
            
            if (target%factorial(tempDig) == 0) {
                target /= factorial(tempDig);
                nums.push(tempDig);
                
                break;
            }
        }
        
    }
    
    
    
    
    cout << generateNum(nums) << endl;
    cout << F("564");
    return 0;
}