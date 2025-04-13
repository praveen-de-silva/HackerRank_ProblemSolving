/* Hidden stub code will pass a root argument to the function below. Complete the function to solve the challenge. Hint: you may want to write one or more helper functions.  

The Node struct is defined as follows:
	struct Node {
		int data;
		Node* left;
		Node* right;
	}
*/ 
void getNodes(vector<Node*> &nodes, Node* root) {
    if (root != NULL) {
        nodes.push_back(root);
        getNodes(nodes, root->left);
        getNodes(nodes, root->right);
    }
}

void addNode(Node* &root, int newKey) {
    Node* crnt = NULL;
    Node* temp = root;
    Node* newNode = new Node();
    newNode->data = newKey;
    
    while (temp != NULL) {
        crnt = temp;
        if (newKey <= temp->data) {
            temp = temp->left;
        } else {
            temp = temp->right;
        }  
    }
    
    if (crnt == NULL) {
        root = newNode;
    } else {
        if (newKey < crnt->data) {
            crnt->left = newNode;
            // cout << crnt->data << " --> " << crnt->left->data << endl;
        } else {
            crnt->right = newNode;
            // cout << crnt->data << " --> " << crnt->right->data << endl;
        }
    }
}

bool checkBST(Node* root) {
    vector<Node*> givenTree; // pre order traversal using Node*
    getNodes(givenTree, root);
    
    
    // create correct binary tree
    Node* rootNew = new Node();
    rootNew->data = root->data;
            
    for (int i=1; i<givenTree.size(); i++) {
        // cout << givenTree[i]->data << " ";
        addNode(rootNew, givenTree[i]->data);
    }
    // cout << endl;
    
    vector<Node*> correctTree; // pre order traversal using Node*
    getNodes(correctTree, rootNew);
    
    for (int i=0; i<givenTree.size(); i++) {
        
        if (givenTree[i]->data != correctTree[i]->data) {
            // cout << givenTree[i]->data << "1 " << correctTree[i]->data << endl;
            return false;
        }
        
        if (givenTree[i]->left!=NULL || correctTree[i]->left!=NULL) {
            if (givenTree[i]->left==NULL || correctTree[i]->left==NULL) {
                return false;
            } 
            if (givenTree[i]->left->data != correctTree[i]->left->data) {
                // cout << givenTree[i]->left->data << "2 " << correctTree[i]->left->data << endl;
                return false;
            }
        } 
        
        if (givenTree[i]->right!=NULL || correctTree[i]->right!=NULL) {
            if (givenTree[i]->right==NULL || correctTree[i]->right==NULL) {
                return false;
            } 
            if (givenTree[i]->right->data != correctTree[i]->right->data) {
                // cout << givenTree[i]->right->data << "3 " << correctTree[i]->right->data << endl;
                return false;
            }
        }
        
    }
    
    
    
    return true;
}