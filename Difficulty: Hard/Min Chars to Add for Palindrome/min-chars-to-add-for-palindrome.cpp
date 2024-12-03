//{ Driver Code Starts
/* Driver program to test above function */

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
  
  
    // bool isPalind(string& s,int start, int end){
    //     int i = start;
    //     int j = end;
        
    //     while(i<j){
    //         if(s[i] != s[j]){
    //             return false;
    //         }
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    
    
    
    
    int minChar(string& s) {
        
        // Write your code here
        
        
        //O(n2) --> TLE
        // int n = s.length();
        
        // int count = 0;
        
        // for(int i=n-1;i>=0;i--){
        //     if(isPalind(s,0,i)){
        //          return count;
        //     }
        //     count++;
        // }
        
        // return count;
        
        
        
        ///kmp
        
        int n = s.size();
        string rev_s = s; 
        reverse(rev_s.begin(), rev_s.end());

        string combined = s + '#' + rev_s; 
        int m = combined.size();

        
        vector<int> lps(m, 0);
        for (int i = 1; i < m; i++) {
            int len = lps[i - 1];
            while (len > 0 && combined[i] != combined[len]) {
                len = lps[len - 1];
            }
            if (combined[i] == combined[len]) {
                len++;
            }
            lps[i] = len;
        }

    
        return n - lps[m - 1];
    }
};

        
        
        
        
        
        

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        Solution ob;
        int ans = ob.minChar(str);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends