//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:
    vector<double> getMedian(vector<int> &arr) {
        
        priority_queue<int>maxHeap;
        priority_queue<int,vector<int>,greater<int>>minHeap;
        
        int n = arr.size();

        vector<double>res;
        
        double ans;
        
        for(int i=0; i<n; i++){
            
            if(maxHeap.size() == minHeap.size()){
                
                if(maxHeap.empty() || arr[i]<=maxHeap.top()){
                   maxHeap.push(arr[i]);
                   ans = maxHeap.top();
                }
                else{
                    minHeap.push(arr[i]);
                    ans = minHeap.top();
                }
            }
            
            else if(maxHeap.size()>minHeap.size()){
                maxHeap.push(arr[i]);
                int top = maxHeap.top();
                maxHeap.pop();
                minHeap.push(top);
                ans = (minHeap.top()+maxHeap.top())/2.0;
            }
            else{
                minHeap.push(arr[i]);
                int top = minHeap.top();
                minHeap.pop();
                maxHeap.push(top);
                ans = (minHeap.top()+maxHeap.top())/2.0;
            }
            res.push_back(ans);
        }
        return res;
        
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    cin.ignore();
    while (t--) {

        string s;
        getline(cin, s);
        stringstream ss(s);
        vector<int> nums;
        int num;
        while (ss >> num) {
            nums.push_back(num);
        }
        Solution ob;
        vector<double> ans = ob.getMedian(nums);
        cout << fixed << setprecision(1);
        for (auto &i : ans)
            cout << i << " ";
        cout << "\n";
        cout << "~" << endl;
    }
    return 0;
}
// } Driver Code Ends