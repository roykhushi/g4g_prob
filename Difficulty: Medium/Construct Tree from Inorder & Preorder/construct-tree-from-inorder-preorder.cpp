//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Definition of the Node class
class Node {
  public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};

// Function to print the tree in postorder traversal
void printPostOrder(Node *root) {
    if (root == NULL)
        return;
    printPostOrder(root->left);
    printPostOrder(root->right);
    cout << root->data << " ";
}


// } Driver Code Ends
// Class that contains the logic to build the binary tree
/*
Definition of the Node class
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/
class Solution {
    //preorder = MLR
    //inorder = LMR
  public:
    Node* solve(vector<int> &inorder, vector<int> &preorder, int start, int end, int &pos){
        //out of bound conditions
        if(start>end || start > inorder.size()){
            return NULL;
        }
        
        //find the root 
        //get the dividing point i.e, the index where the root is inorder using preoder
        //recursively call for left & right parts from that dividing pt in inorder
        Node* root = new Node(preorder[pos]);
        int mid = 0;
        for(int i=start;i<=end;i++){
            if(preorder[pos] == inorder[i]){
                mid = i;
            }
        }
        pos++;
        //recurse
        root->left = solve(inorder,preorder,start,mid-1,pos);
        root->right = solve(inorder,preorder,mid+1,end,pos);
        
        return root;
    }
    // Function to build the tree from given inorder and preorder traversals
    Node *buildTree(vector<int> &inorder, vector<int> &preorder) {
        // code here
        int pos = 0;
        int n = inorder.size()-1;
        
        Node* ans = solve(inorder,preorder,0,n,pos);
        
        return ans;
        
    }
};

//{ Driver Code Starts.

// Main function where the test cases are handled
int main() {
    int t;
    cin >> t;
    cin.ignore();

    while (t--) {
        vector<int> inorder, preorder;

        // Input the inorder traversal
        string input;
        getline(cin, input);
        stringstream ss1(input);
        int num;
        while (ss1 >> num)
            inorder.push_back(num);

        // Input the preorder traversal
        getline(cin, input);
        stringstream ss2(input);
        while (ss2 >> num)
            preorder.push_back(num);

        // Create Solution object and build the tree
        Solution obj;
        Node *root = obj.buildTree(inorder, preorder);

        // Print the postorder traversal of the constructed tree
        printPostOrder(root);
        cout << endl;
        cout << "~" << endl;
    }
    return 0;
}

// } Driver Code Ends