#include <bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node (int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};

Node* makeBT(vector<vector<int>> &arr) {
    queue<Node*> prevNodes;
    
    Node* bt = new Node(1);
    Node* crnt;
    
    prevNodes.push(bt);
    
    for (vector<int> subArr : arr) {
        crnt = prevNodes.front();
        prevNodes.pop();
        
        if (subArr[0] != -1) {
            crnt->left = new Node(subArr[0]);
            prevNodes.push(crnt->left);
        }
        
        if (subArr[1] != -1) {
            crnt->right = new Node(subArr[1]);
            prevNodes.push(crnt->right);
        }
    }
    
    return bt;
}

void traverseInOrderWithSwap(Node* binaryTree, int k, int depth, vector<int>& nums) {
    if (binaryTree != nullptr) {
        if (depth%k == 0) {
            swap(binaryTree->left, binaryTree->right);
        }
        traverseInOrderWithSwap(binaryTree->left, k, depth+1, nums);
        nums.push_back(binaryTree->data); 
        traverseInOrderWithSwap(binaryTree->right, k, depth+1, nums);
    }
}

vector<vector<int>> swapNodes(vector<vector<int>> indexes, vector<int> queries) {
    Node* root = makeBT(indexes);
    vector<vector<int>> result;
    
    for (int k : queries) {
        vector<int> temp;
        traverseInOrderWithSwap(root, k, 1, temp);
        result.push_back(temp);
    }
    
    
    return result;
}