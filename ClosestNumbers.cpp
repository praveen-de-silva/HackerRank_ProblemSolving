#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<int> closestNumbers(vector<int> arr) {
    sort(arr.begin(), arr.end()); // sort the array
    int n = arr.size(); // size of the array
    int crntMinDif = arr[1] - arr[0];
    int tempMinDif;
    map<int, vector<int>> data;

    // get the adjecent differences
    for (int i=1; i<n; i++) {
        tempMinDif = arr[i] - arr[i-1]; // this is the temporal absolute difference
        
        if (tempMinDif <= crntMinDif) {
            if (tempMinDif < crntMinDif) {
                cout << crntMinDif << endl;
                crntMinDif = tempMinDif; // update crnt min difference
            }
            
            // push data to the existing vector array
            data[tempMinDif].push_back(arr[i-1]); 
            data[tempMinDif].push_back(arr[i]);
        }
    }
    
    return data[crntMinDif];
}