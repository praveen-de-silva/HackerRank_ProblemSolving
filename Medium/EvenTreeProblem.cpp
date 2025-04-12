#include <iostream>
#include <vector>
#include <list>

using namespace std;

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph {
    int n;
    Node *nodes;
    int removableEdges;
    
    // for DFS
    vector<char> colors;
    vector<int> parents;
    vector<int> subTreeSizes;
    
    Graph (int size) {
        n = size;
        nodes = new Node[n];
        removableEdges = 0;
        
        for (int i=0; i<n; i++) {
            nodes[i].label = i+1;
            
            colors = vector<char>(n, 'w');
            parents = vector<int>(n, -1);
            subTreeSizes = vector<int>(n, 0);
        }
    }
    
    ~Graph() {
        delete[] nodes;
    }
    
    void addEdge(int u, int v) {
        nodes[u-1].neighbours.push_back(v-1);
        nodes[v-1].neighbours.push_back(u-1);
    }
    
    int DFS_visit(Node &node) {
        int subTreeSize = 1; // inital size (itself)
        colors[node.label-1] = 'g'; // visit started
        
        // cout << node.label << " ";
        
        // visiting neighbhours
        for (int iAdj : node.neighbours) {
            if (colors[iAdj] == 'w') { // can be visited
                parents[iAdj] = node.label-1;
                subTreeSize += DFS_visit(nodes[iAdj]);
            }
        }
        
        subTreeSizes[node.label-1] = subTreeSize;
        
        if ((subTreeSize % 2 == 0) && (node.label != 1)) {
            removableEdges++;
        }
        
        
        colors[node.label-1] = 'b'; // visit completed
        return subTreeSize;
    }
    
    void DFS() {
        for (int i=0; i<n; i++) {
            if (colors[i]=='w') {
                DFS_visit(nodes[i]);    
            }
            
        }
    }
    
    int solve() {
        DFS_visit(nodes[0]);
        return removableEdges;
    }
    
    void printGraph() {
        for (int i=0; i<n; i++) {
            cout << nodes[i].label << " --> ";
            
            for (int adj : nodes[i].neighbours) {
                cout << adj+1 << " ";
            }
            cout << endl;
        }
    }
};