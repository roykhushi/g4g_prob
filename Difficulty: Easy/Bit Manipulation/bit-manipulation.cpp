//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    void bitManipulation(int x, int i) {
        // your code here
        
        //getting ith bit
        int get = (x >> i-1) & 1;
        
        //setting ith bit
        int set = x | (1 << i-1);
        
        //clear
        int clear = x & (~(1 << i-1));
        
        cout<<get<<" "<<set<<" "<<clear<<" ";
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n >> i;
        Solution ob;
        ob.bitManipulation(n, i);
        cout << "\n";
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends