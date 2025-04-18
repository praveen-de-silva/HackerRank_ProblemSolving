#include <bits/stdc++.h>

using namespace std;

bool sortAs(string s1, string s2) {
    if (s1.size() != s2.size()) {
        return s1.size() < s2.size();
    }

    return s1 < s2;
}

vector<string> bigSorting(vector<string> unsorted) {
    sort(unsorted.begin(), unsorted.end(), sortAs);
    return unsorted;
}