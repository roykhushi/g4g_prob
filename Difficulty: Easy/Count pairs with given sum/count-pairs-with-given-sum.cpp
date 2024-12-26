//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int countPairs(vector<int> &arr, int target) {
        // Code here
       //brute force
        //   int count = 0;
        //   for(int i=0;i<arr.size();i++){
        //       for(int j=i+1;j<arr.size();j++){
        //           if(arr[i] + arr[j] == target){
        //               count++;
        //           }
        //       }
        //   }
        //   return count;
    
        //optimal 
        map<int,int> mp;
        int n = arr.size();
        int count = 0;
    
        for(int i=0;i<n;i++){
            int half = target-arr[i];
            
            if(mp.find(half) != mp.end()){
                count += mp[half];
            }
            
            mp[arr[i]]++;
        }
        
        return count;
    
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
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        int target;
        cin >> target;
        cin.ignore();
        Solution ob;
        int res = ob.countPairs(arr, target);

        cout << res << endl << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends