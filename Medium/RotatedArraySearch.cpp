#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

int findFirst(vector<int> &arr, int l, int r) {
    if (arr[l] <= arr[r]) {
        return l;
    }
    int mid = (l + r)/2;
    
    if (arr[mid] < arr[l]) {
        return findFirst(arr, l, mid);
    }
    
    return findFirst(arr, mid+1, r);
}

int binarySearch(vector<int> &arr, int l, int r, int target) {
    if (l > r) {
        return -1;
    }
    
    int mid = (l + r) / 2;
    
    if (arr[mid] == target) {
        return mid;
    } else if (arr[mid] > target) {
        return binarySearch(arr, l, mid-1, target);
    } 
    return binarySearch(arr, mid+1, r, target);
}

int search(vector<int> &arr, int target) {
    int n = arr.size();
    int idFirst = findFirst(arr, 0, n-1);
    int l, r;
    
    // selecting left(l), right(r)
    if (target >= arr[idFirst] && target <= arr[n-1]) {
        l = idFirst;
        r = n-1;
    } else {
        l = 0;
        r = idFirst-1;
    }

    return binarySearch(arr, l, r, target);
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */ 
    string userInp;
    getline(cin, userInp);
    vector<int> nums;
    string token;
    
    stringstream ss(userInp);
    
    while (getline(ss, token, ',')) {
        nums.push_back(stoi(token));
    }
    
    int target;
    cin >> target;
    
    cout << search(nums, target);
    
    return 0;
}
