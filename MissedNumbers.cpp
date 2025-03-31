#include <bits/stdc++.h>
#include <algorithm>

using namespace std;

vector<int> missingNumbers(vector<int> arr, vector<int> brr) {
    // sort arrays for easy manipulations
    sort(arr.begin(), arr.end());
    sort(brr.begin(), brr.end());
    
    arr.push_back(-1); // for add rest of the elements (Trick)
    
    vector<int> missed;  // resultant array for contain missed elements
    int i_arr = 0;       // index through first array 
    
    for (int i_brr=0; i_brr<brr.size(); i_brr++) {
        if (brr[i_brr] != arr[i_arr]) { // 'brr[i_brr]' not in 'arr[i_arr]'
            if (!binary_search(missed.begin(),missed.end() , brr[i_brr])) { // 'brr[i_brr]' has not beed catched yet. (Binary search is much efficient since array is sorted)
            
               missed.push_back(brr[i_brr]);
            }
            continue;
        }
        
        i_arr++; // go to the next elements of the first array
    }
    
    return missed;
}