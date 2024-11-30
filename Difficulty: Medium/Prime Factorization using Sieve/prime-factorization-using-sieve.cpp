//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    void sieve() {}

    vector<int> findPrimeFactors(int N) {

        // Write your code here
        vector<bool>p(N+1,true);
        vector<int> ans;
        
        p[0] = p[1] = false;
        
        for(int i=2;i<=N;i++){
            if(p[i]){
                for(int j=2*i;j<N;j+=i){
                    p[j] = false;
                }
            }
        }
        
        for(int i=2;i<=N;i++){
            while(N%i == 0 && p[i]){
                ans.push_back(i);
                N/=i;
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input
        int n;
        cin >> n;

        Solution obj;
        obj.sieve();
        vector<int> vec = obj.findPrimeFactors(n);
        for (int i = 0; i < vec.size(); i++) {
            cout << vec[i] << " ";
        }
        cout << endl;

        // cout << "~\n";
    
cout << "~" << "\n";
}
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends