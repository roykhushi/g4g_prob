//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<int> subarraySum(vector<int> &arr, int target) {
        // code here
        //brute force
        vector<int> ans;
        int n = arr.size();
        
        // if(n == 1){
        //     if(arr[0] == target){
        //         ans.push_back(1);
        //         ans.push_back(1);
        //     }
        //     else{
        //         ans.push_back(-1);
        //     }
        //     return ans;
        // }
        
        
        
        //brute force = O(n2)
        // for(int i=0;i<n;i++){
        //     int sum = 0;
        //     for(int j=i;j<n;j++){
        //         sum += arr[j];
        //         if(sum == target){
        //             ans.push_back(i+1);
        //             ans.push_back(j+1);
        //             return ans;
        //         }
                
        //     }
        // }
        
        //optimised 
        //sliding window
        
        int left = 0;
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
            
            while(sum > target && left<i){
                sum-=arr[left];
                left++;
            }
            
            if(sum == target){
                ans.push_back(left+1);
                ans.push_back(i+1);
                
                return ans;
            }
        }
        
       ans.push_back(-1);
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
        int d;
        string input;

        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        cin >> d;
        cin.ignore();

        Solution ob;
        vector<int> result = ob.subarraySum(arr, d);
        for (int i : result) {
            cout << i << " ";
        }
        cout << "\n~\n";
    }
    return 0;
}

// } Driver Code Ends