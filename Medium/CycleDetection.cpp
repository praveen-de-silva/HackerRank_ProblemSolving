#include <iostream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;
 

struct Node {
    int label;
    list<int> neighbours;
};

struct Graph {
    int n; // size of the graph
    Node *nodes;
    bool isCyclic = false;
    
    // for DFS_visit
    vector<char> colors;
    vector<int> parents;
    
    Graph(int size) {
        n = size;
        nodes = new Node[n];
        
        for (int i=0; i<n; i++) {
            nodes[i].label = i+1;
        }
        
        colors = vector<char>(n, 'w');
        parents = vector<int>(n, -1);
    }
    
    ~Graph() {
        delete[] nodes;
    }
    
    // add edges
    void addEdge(int u, int v) {
        nodes[u-1].neighbours.push_back(v-1);
        nodes[v-1].neighbours.push_back(u-1);
    }
    
    // DFS_visit
    void DFS_visit(int idU) {
        colors[idU] = 'g'; // visit started
        // cout << nodes[idU].label << " " << parents[idU] << endl;
        int idParent = parents[idU];
        
        // visit neighbours
        for (int idAdj :  nodes[idU].neighbours) {
            if ((colors[idAdj] != 'w') && (idAdj != idParent)) {
                isCyclic = true;
            }
            if (colors[idAdj] == 'w') {
                parents[idAdj] = idU;
                DFS_visit(idAdj);
            }
        }
        
        colors[idU] = 'b'; // visit completed
    }
    
    void DFS() {
        for (int i = 0; i < n; i++) {
            if (colors[i] == 'w') {
                DFS_visit(i);
            }
        }
    }
    
    void detectCycles() {
        DFS();
        
        if (isCyclic) {
            cout << "There is atleast one cycle." << endl;
        } else {
            cout << "There are no cycles." << endl;
        }
    }
    
    void printGraph() {
        for (int i=0; i<n; i++) {
            // print nodes data
            cout << nodes[i].label << " --> ";
            
            // print neighbour details
            for (int iAdj : nodes[i].neighbours) {
                cout << (iAdj+1) << " ";
            }
            
            cout << endl;
        }
    }
};

int main() {
    Graph gp = Graph(5);
    
    gp.addEdge(1, 2);
    gp.addEdge(1, 3);
    gp.addEdge(2, 4);
    gp.addEdge(2, 5);
    gp.addEdge(4, 5);

    gp.printGraph();
    
    gp.detectCycles();

    return 0;
}