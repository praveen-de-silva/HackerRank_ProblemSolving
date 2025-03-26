#include <bits/stdc++.h>

using namespace std;

string fairRations(vector<int> B) {
    int minDis = 0; // minimum no of distributions
    
    for (int i = 0; i < B.size()-1; i++) {
        if (B[i] % 2 == 1) {
            B[i+1]++;
            minDis += 2; // each one needs double distributions
        }
    }
    
    // check the last element
    if (B[B.size()-1] % 2 == 1) {
        return "NO";
    }
    
    return to_string(minDis);
}