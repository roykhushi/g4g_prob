//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int firstOcc(vector<int>& arr, int target){
        int start = 0;
        int end = arr.size()-1;
        int first = -1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                first = mid;
                end = mid-1;
            }
            else if(arr[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        
        return first;
    }
    int lastOcc(vector<int>& arr, int target){
        int start = 0;
        int end = arr.size()-1;
        int last = -1;
        
        while(start<=end){
            int mid = start + (end-start)/2;
            
            if(arr[mid] == target){
                last = mid;
                start = mid+1;
            }
            else if(arr[mid] < target){
                start = mid+1;
            }
            else{
                end = mid-1;
            }
        }
        return last;
    }
    int count(vector<int>& arr, int target) {
        // code here
        int first = firstOcc(arr,target);
        int last = lastOcc(arr,target);
        
        if(first == -1 || last == -1){
            return 0;
        }
        
        int count = (last-first+1);
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int test_case;
    cin >> test_case;
    cin.ignore();
    while (test_case--) {

        int d;
        vector<int> arr, brr, crr;
        string input;
        getline(cin, input);
        stringstream ss(input);
        int number;
        while (ss >> number) {
            arr.push_back(number);
        }
        getline(cin, input);
        ss.clear();
        ss.str(input);
        while (ss >> number) {
            crr.push_back(number);
        }
        d = crr[0];
        int n = arr.size();
        Solution ob;
        int ans = ob.count(arr, d);
        cout << ans << endl;
    }
    return 0;
}
// } Driver Code Ends