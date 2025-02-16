//{ Driver Code Starts
// Program to find the maximum profit job sequence from a given array
// of jobs with deadlines and profits
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution {
  public:
    vector<int> JobSequencing(vector<int> &id, vector<int> &deadline,
                              vector<int> &profit) {
        // code here
        
        
        int n = id.size();
        vector<vector<int>> task(n);
        
        for(int i=0;i<n;i++){
            task[i] = {deadline[i],profit[i]};
        }
        
        sort(task.begin(),task.end());
        
        priority_queue<int, vector<int>, greater<int>> minHeap;
        
        int i = 0;
        
        for(int j=1;j<=n;j++){
            while(i<n && task[i][0] <= j){
                if(minHeap.size() < j){
                    minHeap.push(task[i][1]);
                }
                else if(minHeap.top() < task[i][1]){
                    minHeap.pop();
                    minHeap.push(task[i][1]);
                }
                i++;
            }
        }
        
        int total = minHeap.size();
        int max_profit = 0;
        
        while(!minHeap.empty()){
            max_profit += minHeap.top();
            minHeap.pop();
        }
        
        return {total,max_profit};
        
    }
};


//{ Driver Code Starts.
//            Driver program to test methods
int main() {
    int t;
    // testcases
    cin >> t;
    cin.ignore();
    while (t--) {
        vector<int> jobIDs, deadlines, profits;
        string temp;
        getline(cin, temp);
        istringstream ss1(temp);
        int x;
        while (ss1 >> x)
            jobIDs.push_back(x);

        getline(cin, temp);
        istringstream ss2(temp);
        while (ss2 >> x)
            deadlines.push_back(x);

        getline(cin, temp);
        istringstream ss3(temp);
        while (ss3 >> x)
            profits.push_back(x);

        int n = jobIDs.size();

        Solution obj;
        vector<int> ans = obj.JobSequencing(jobIDs, deadlines, profits);
        cout << ans[0] << " " << ans[1] << endl;

        cout << "~"
             << "\n";
    }
    return 0;
}

// } Driver Code Ends