#include <bits/stdc++.h>

using namespace std;

string organizingContainers(vector<vector<int>> container) {
    map<int, int> containerCounts; // contains : size, count of containers
    map<int, int> typeCounts;      // contains : type, count of type
    int n = container.size();
    int crntContainerSize, crntBallCount;
    
    // add count details
    for (int i=0; i<n; i++) {
        crntContainerSize = 0;
        
        for (int j=0; j<n; j++) {
            crntBallCount = container[i][j];
            crntContainerSize += crntBallCount;
            typeCounts[j] += crntBallCount;
        }
        
        containerCounts[crntContainerSize] += 1;
    }
    
    // check each type has a suitable container
    for (int i=0; i<n; i++) {
        if (containerCounts[typeCounts[i]] > 0) {
            containerCounts[typeCounts[i]] -= 1;
        } else {
            return "Impossible";
        }
    }
    
    return "Possible";
}