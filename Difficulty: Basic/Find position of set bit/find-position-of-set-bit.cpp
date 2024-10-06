//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        //pls remember the opr precedences
        if ((N & (N - 1)) != 0 || N <= 0) {
        return -1;
    }
        
        int idx = 1;
        
        while(N>0){
            if((N&1) == 1){
                return idx;
            }
            idx++;
            N = N>>1;
        }
        return -1;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
// } Driver Code Ends