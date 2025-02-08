#include <bits/stdc++.h>

using namespace std;

/*
    -------------
    Algo 01 (bad)
    -------------
*/

long findMax(vector<int> arr) {
    long crntMax = 0;
    
    for (int num : arr) {
        if (num > crntMax) {
            crntMax = num;
        }
        // cout << "current max : " << crntMax << endl;
    }
    
    
    return crntMax;
}

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<int> res;
    
    for (int i=0; i<n; i++) {
        res.push_back(0);
    }
    
    for (vector<int> tempVect : queries) {
        int start=tempVect[0]-1, end=tempVect[1]-1, fill=tempVect[2];
        
        for (int i=start; i<=end; i++) {
            res[i] += fill;
        }
        
        
    }
    long maxVal = findMax(res);
    cout << maxVal << endl;
    return maxVal;
}

/*
    ---------------
    Algo 02 (Super)
    ---------------
*/

long arrayManipulation(int n, vector<vector<int>> queries) {
    vector<long> res(n+1, 0); // initialize vector
    long maxVal=0, crntSum=0;
    
    for (vector<int> tempVect : queries) {
        int start = tempVect[0]-1, end = tempVect[1]-1, fill = tempVect[2];
        
        res[start] += fill;
        res[end+1] -= fill; 
    }
    
    for (int i=0; i<n; i++) {
        crntSum += res[i];
        
        if (crntSum>maxVal) {
            maxVal = crntSum;
        }
    }
    return maxVal;
}