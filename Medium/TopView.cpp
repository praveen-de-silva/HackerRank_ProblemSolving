#include <map>
#include <iostream>
using namespace std;

map<int, map<int, int>> data;

void visit(Node* root, int level, int pos) {
    if (root != nullptr) {
        visit(root->left, level+1, pos-1);
        
        // visiting root
        data[pos][level] = root->data;
        // cout << level << " " << pos << " " << root->data << endl;
        
        visit(root->right, level+1, pos+1);
    }
}

    
void topView(Node * root) {
    visit(root, 0, 0);
    
    for (auto it = data.begin(); it != data.end(); ++it) {
        cout << (it->second).begin()->second << " ";
    }
}