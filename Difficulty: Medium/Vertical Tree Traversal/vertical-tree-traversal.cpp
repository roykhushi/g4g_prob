//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
          
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

// Function for Inorder Traversal
void printInorder(Node* root)
{
    if(!root)
        return;
        
    printInorder(root->left);
    cout<<root->data<<" ";
    printInorder(root->right);
}


// } Driver Code Ends
class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        //Your code here
        
        map<int,map<int,vector<int>>> mp;
        queue<pair<Node* , pair<int,int>>> q;
        vector<int> ans;
        
        if(root == NULL){
            return ans;
        }
        
        q.push(make_pair(root, make_pair(0,0))); //initially both the hd and lvl would be 0
        
        while(!q.empty()){
            pair<Node* , pair<int,int>> temp = q.front();
            q.pop();
            Node* frontNode = temp.first;
            int horizontalDist = temp.second.first;
            int level = temp.second.second;
            
            mp[horizontalDist][level].push_back(frontNode->data);
            
            if(frontNode->left != NULL){
                q.push(make_pair(frontNode->left, make_pair(horizontalDist-1, level+1))); //for the left side when going down the hd decreases
            } 
            if(frontNode->right != NULL){
                q.push(make_pair(frontNode->right, make_pair(horizontalDist+1, level+1)));
            }
        }
        
        for(auto i : mp){
            for(auto j : i.second){
                for(auto k : j.second){
                    ans.push_back(k);
                }
            }
        }
        return ans;
        
    }
};



//{ Driver Code Starts.
int main() {
    int t;
    string  tc;
    getline(cin,tc);
    t=stoi(tc);
    while(t--)
    {
        string s;
        getline(cin,s);
        // string c;
        // getline(cin,c);
        Solution obj;
    	Node* root = buildTree(s);
    	
    	vector <int> res = obj.verticalOrder(root);
    	for (int i : res) cout << i << " ";
        cout << endl;
    
cout << "~" << "\n";
}
	return 0;
}



// } Driver Code Ends