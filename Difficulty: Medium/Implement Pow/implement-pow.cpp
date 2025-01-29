//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++
class Solution {
  public:
    double power(double b, int e) {
        // code here
        double ans = 1.0;
        long long exp = e;
        
        if(exp < 0){
            exp = -exp;
            b = 1.0/b;
        }
        
        while(exp > 0){
            if(exp%2 != 0){
                ans = ans*b;
            }
            b = b*b;
            exp = exp/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    cout << fixed << setprecision(5);
    int t;
    cin >> t;
    while (t--) {
        double b;
        cin >> b;
        int e;
        cin >> e;
        Solution ob;
        cout << ob.power(b, e) << endl;
        cout << "~" << endl;
    }

    return 0;
}
// } Driver Code Ends