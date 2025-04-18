#include <bits/stdc++.h>

using namespace std;

void updateData(set<int>& data, char letter, int count) {
    int charSize = int(letter) - 'a' + 1;
    int crntSize = 0;
    
    for (int i=0; i<count; i++) {
        crntSize += charSize;
        data.insert(crntSize);
    }
}

set<int> getWeights(set<int>& data, string s) {
    char prev = s[0];
    char crnt;
    int count = 1;
    
    for (int i=1; i<s.size(); i++) {
        crnt = s[i];
        
        if (crnt != prev) {
            updateData(data, prev, count);
            prev = crnt;
            count = 0;
        }
        
        count++;
    }
    
    updateData(data, prev, count);
    return data;
}


vector<string> weightedUniformStrings(string s, vector<int> queries) {
    set<int> data;
    vector<string> result;
    
    getWeights(data, s); // insert the all sizes to the set
    
    for (int q : queries) {
        if (data.find(q) != data.end()) {
            result.push_back("Yes");
        } else {
            result.push_back("No");
        }
    }
    
    return result;
}