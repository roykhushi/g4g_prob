//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
class Solution {
  public:
    // arr: input array
    // Function to find maximum circular subarray sum.
    
    int circularSubarraySum(vector<int> &arr) {
        // int n = arr.size();
        
        // if(n == 1){
        //     return arr[0];
        // }
        
        // int sum = arr[0];
        
        // for(int i=0;i<n;i++){
        //     int curr_sum = 0;
        //     for(int j=0;j<n;j++){
        //         int k = (i+j)%n;
        //         curr_sum += arr[k];
        //         sum = max(sum,curr_sum);
        //     }
            
        // }
        // return sum;
        
        int n = arr.size();
        
        int max_sum = 0;
        int curr_sum = 0;
        
        int curr_min = 0;
        int min_sum = 0;
        
        int sum = 0;
        
        for(int i=0;i<n;i++){
            sum += arr[i];
            
            curr_sum += arr[i];
            
            if(curr_sum > max_sum){
                max_sum = curr_sum;
            }
            
            if(curr_sum < 0){
                curr_sum = 0;
            }
        }
        
        
        for(int i=0;i<n;i++){
            curr_min += arr[i];
            
            if(curr_min < min_sum){
                min_sum = curr_min;
            }
            
            if(curr_min > 0){
                curr_min = 0;
            }
        }
        
    
        return max(max_sum,sum-min_sum);
    
        
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

        // Read first array
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        int res = ob.circularSubarraySum(arr);

        cout << res << endl;
    }
    return 0;
}

// } Driver Code Ends