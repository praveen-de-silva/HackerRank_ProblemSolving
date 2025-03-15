#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
#include <algorithm>
using namespace std;

// heapify top to bottom
void heapifyDown(long long int arr[], int n, long long int node) {
    long long l = 2 * node + 1;
    long long r = 2 * node + 2;
    long long minimum = node;
    
    if (l < n && arr[minimum] > arr[l]) {
        minimum = l;
    }
    
    if (r < n && arr[minimum] > arr[r]) {
        minimum = r;
    }
    
    if (node != minimum) {
        swap(arr[node], arr[minimum]);
        heapifyDown(arr, n, minimum);
    }
    
}

// heapify bottom to top
void heapifyUp(long long int arr[], int n, long long int node) {
    long long child = node;
    long long parent = (child - 1) / 2;
    
    while (child > 0 && arr[parent] > arr[child]) {
        swap(arr[parent], arr[child]);
        child = parent;
        parent = (child - 1) / 2;
    }
}

void removeNode(long long int arr[], int n, long long int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            swap(arr[i], arr[n-1]);
        }
    }
}

int main() {
    int queries;
    string crntUserInp;
    vector<long long int> arr; // to contain data
    
    // get input
    cin >> queries;
    cin.ignore();
    
    for (int i = 0; i < queries; i++) {
        getline(cin, crntUserInp);
        
        stringstream ss(crntUserInp);
        vector<long long> crntInps;
        long long num;
        
        while (ss >> num) {
            crntInps.push_back(num);
        }
        
        if (crntInps[0] == 1) {
            arr.push_back(crntInps[1]);
            heapifyUp(arr.data(), arr.size(), arr.size() - 1);
        }
        
        if (crntInps[0] == 2) {
            removeNode(arr.data(), arr.size(), crntInps[1]);
            arr.pop_back();
            heapifyDown(arr.data(), arr.size(), 0);
            
        }
        
        if (crntInps[0] == 3) {
            cout << arr[0] << endl;
        }

    }
    
    return 0;
}
