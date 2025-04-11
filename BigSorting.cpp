#include <bits/stdc++.h>

using namespace std;

bool func(string s1, string s2) {
    if (s1.size() > s2.size()) {
        return false;
    }
    
    else if (s1.size() < s2.size()) {
        return true;
    } 
    
    else {
        for (int i=0; i<s1.size(); i++) {
            if (s1[i] > s2[i]) {
                return false;
            } else if (s1[i] < s2[i]) {
                return true;
            }
            
            
        }
    }
    
    return false;
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), func);
    return unsorted;
}