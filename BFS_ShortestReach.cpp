#include <bits/stdc++.h>

using namespace std;

vector<int> bfs(int n, int m, vector<vector<int>> edges, int s) {
    vector<bool> isVisited(n, false);  // Initialize with n false values
    map<int, vector<int>> graph;       // Adjacency list representation
    vector<int> distances(n, -1);      // Initialize all distances to -1
    queue<int> visitingData;
    vector<int> level(n, -1);          // Track levels (hops) from start node
    
    // Build the undirected graph (note: nodes are 1-based in input)
    for (vector<int> edge : edges) {
        graph[edge[0]-1].push_back(edge[1]-1);
        graph[edge[1]-1].push_back(edge[0]-1);
    }
    
    // Start BFS from source node (convert to 0-based)
    int start = s-1;
    visitingData.push(start);
    level[start] = 0;  // Starting node is at level 0
    
    while (!visitingData.empty()) {
        int crnt = visitingData.front();
        visitingData.pop();
        
        if (isVisited[crnt]) {
            continue;
        }
        
        isVisited[crnt] = true;
        distances[crnt] = level[crnt] * 6;  // Each edge has weight 6
        
        // Explore neighbors
        for (int adj : graph[crnt]) {
            if (!isVisited[adj] && level[adj] == -1) {
                level[adj] = level[crnt] + 1;
                visitingData.push(adj);
            }
        }
    }
    
    // Remove the distance to the start node (problem requirement)
    distances.erase(distances.begin() + start);
    return distances;
}