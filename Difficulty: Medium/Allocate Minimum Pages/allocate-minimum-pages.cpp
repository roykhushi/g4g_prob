//{ Driver Code Starts
// Initial function template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    int calcStudent(vector<int> &arr, int pages){
        int student = 1;
        long long totPages = 0;
        
        for(int i=0;i<arr.size();i++){
        if(totPages + arr[i] <= pages){
            totPages += arr[i];
        }
        else{
            student+=1;
            totPages = arr[i];
        }
    }
    return student;
    }
    int findPages(vector<int> &arr, int k) {
        // code here
        if(k>arr.size()){
            return -1;
        }
        int maxi = INT_MIN;
        
        for(int i=0;i<arr.size();i++){
            maxi = max(arr[i],maxi);
        }
        
        int sum = 0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
        }
        
        // int ans = -1;
        
        int start = maxi;
        int end = sum;
        
        while(start <= end){
            int mid = start + (end-start)/2;
            
            int students = calcStudent(arr,mid);
            
            if(students > k){
                start = mid+1;
                
            }
            else{
                // ans = mid;
                end = mid-1;
            }
        }
        
        return start;
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
        int ans = ob.findPages(arr, d);
        cout << ans << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}
// } Driver Code Ends