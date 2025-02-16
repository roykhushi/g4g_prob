//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node *buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree
    Node *root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node *> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node *currNode = queue.front();
        queue.pop();

        // Get the current Node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current Node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current Node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends

class Solution {
  public:
    vector<int> serialize(Node *root) {      
        vector<int> arr;
        queue<Node*> q;
        
        if (root == NULL) {
            return arr;
        }
        
        q.push(root);
        
        while (!q.empty()) {
            Node* frontNode = q.front();
            q.pop();
            
            if (frontNode == NULL) {
                arr.push_back(-1);
                continue;
            }
            
            arr.push_back(frontNode->data);
            
            q.push(frontNode->left);
            q.push(frontNode->right);
        }
        
        return arr;
    }

    Node *deSerialize(vector<int> &arr) {
        int n = arr.size();
        
        if (n == 0 || arr[0] == -1) {
            return NULL;
        }
        
        queue<Node*> q;
        int i = 0;
        Node* root = new Node(arr[i++]);
        q.push(root);
        
        while (i < n) {
            Node* frontNode = q.front();
            q.pop();
            
            if (arr[i] != -1) {
                frontNode->left = new Node(arr[i]);
                q.push(frontNode->left);
            }
            
            i++;  
            
            if (i >= n) break;  
            
            if (arr[i] != -1) {
                frontNode->right = new Node(arr[i]);
                q.push(frontNode->right);
            }
            i++; 
        }
        
        return root;
    }
};


//{ Driver Code Starts.

void inorder(Node *root) {
    if (root == NULL)
        return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void _deleteTree(Node *node) {
    if (node == NULL)
        return;

    /* first delete both subtrees */
    _deleteTree(node->left);
    _deleteTree(node->right);

    /* then delete the node */
    // cout << "Deleting node: " << node->data << endl;
    delete node;
}

/* Deletes a tree and sets the root as NULL */
void deleteTree(Node **node_ref) {
    _deleteTree(*node_ref);
    *node_ref = NULL;
}

int main() {
    int tc;
    scanf("%d ", &tc);
    while (tc--) {
        string treeString;
        getline(cin, treeString);
        Node *root = buildTree(treeString);

        Solution serial, deserial;
        vector<int> A = serial.serialize(root);
        Node *temp = root;
        deleteTree(&root);
        Node *getRoot = deserial.deSerialize(A);
        inorder(getRoot);

        cout << "\n";

        cout << "~"
             << "\n";
    }

    return 0;
}
// } Driver Code Ends