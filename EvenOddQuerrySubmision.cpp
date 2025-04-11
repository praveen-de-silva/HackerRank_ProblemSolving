#include <iostream>
#include <vector>

using namespace std;

vector<string> solve(vector<int> arr, vector<vector<int>> queries) {
    int x, y;
    vector<string> res;
    for (vector<int> querry : queries) {
        x = querry[0];
        y = querry[1];
        
        if ((arr[x-1] % 2 == 0) && (((x < y) && (arr[x]!=0)) || (x == y))) {
            res.push_back("Even");
        } else {
            res.push_back("Odd");
        }
    }
    return res;
}