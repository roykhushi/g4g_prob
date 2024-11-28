//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int myAtoi(char *s) {
        // Your code here
        
        // s = s.trim();
        
        int n = strlen(s);
        
        if(n == 0){
            return 0;
        }
        
        int neg = 0;
        
        if(s[0] == '-'){
            neg++;
        }
        
        long long ans = 0;
        
        for(int i=neg;i<n;i++){
            if(s[i] == ' '){
                continue;
            }
            if(s[i] >= '0' && s[i] <= '9'){
                int digit = s[i] - '0';
                ans = ans*10 + digit;
            }
            else{
                break;
            }
            
        }
        
        if(s[0] == '-'){
            ans = -1*ans;
        }
        
        if(ans <= INT_MIN){
            return INT_MIN;
        }
        if(ans >= INT_MAX){
            return INT_MAX;
        }
        
        return ans;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        char s[20];
        cin >> s;
        Solution ob;
        int ans = ob.myAtoi(s);
        cout << ans << endl;
        cout << "~" << endl;
    }
}
// } Driver Code Ends