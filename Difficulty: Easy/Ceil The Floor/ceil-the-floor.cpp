//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User code template

class Solution {
  public:
    int getCeil(int x, vector<int> &arr){
        
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(arr[mid]>=x){
                ans = arr[mid];
                end = mid-1;
            }
            else{
                start = mid+1;
            }
        }
        return ans;
    }
    int getFloor(int x, vector<int> &arr){
        int start = 0;
        int end = arr.size()-1;
        int ans = -1;
        
        while(start<=end){
            int mid = start+(end-start)/2;
            
            if(arr[mid]<=x){
                ans = arr[mid];
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return ans;
    }
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        //
        sort(arr.begin(),arr.end());
        
        int floor = getFloor(x,arr);
        int ceil = getCeil(x,arr);
        
        
        vector<int> ans = {floor,ceil};
        
        
        return ans;
        
        
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    cin.ignore(); // Ignore the newline character after t
    while (t--) {
        vector<int> arr;
        int x;
        string input;
        cin >> x;
        cin.ignore();

        getline(cin, input); // Read the entire line for the array elements
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }

        Solution ob;
        auto ans = ob.getFloorAndCeil(x, arr);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends