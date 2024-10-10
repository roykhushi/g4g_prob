//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int maxDistance(vector<int> &arr) {
        // Code here
        map<int,int> mp;
        
        int ans = 0;
        
        for(int i=0;i<arr.size();i++){
            mp[arr[i]] = i;
        }
        
        for(int i=0;i<arr.size();i++){
            if(mp.find(arr[i]) != mp.end()){
                int res = mp[arr[i]]-i;
                
                ans = max(ans,res);
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> arr;
        string input;
        getline(cin, input);

        stringstream s1(input);
        int num;
        while (s1 >> num) {
            arr.push_back(num);
        }

        Solution ob;
        cout << ob.maxDistance(arr) << endl;
    }
    return 0;
}
// } Driver Code Ends