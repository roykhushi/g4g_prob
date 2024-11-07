//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

class Solution{   
public:
    int median(vector<vector<int>> &matrix, int R, int C){
        // code here  
        //brute force
        vector<int> merger;
        
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                merger.push_back(matrix[i][j]);
            }
        }
        
        sort(merger.begin(),merger.end());
        
        int n = merger.size();
        
        return merger[n/2];
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        int ans=-1;
        ans=obj.median(matrix, r, c);
        cout<<ans<<"\n";        
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends