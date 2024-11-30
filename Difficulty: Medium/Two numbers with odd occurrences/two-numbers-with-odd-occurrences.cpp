//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
    public:
    
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        // code here
        map<long long int,long long int> mp;
        vector<long long int> ans;
        
        for(int i=0;i<N;i++){
            mp[Arr[i]]++;
        }
    
        for(auto &i : mp){
            if(i.second%2 == 1){
                ans.push_back(i.first);
            }
        }
        //custom comparator
        sort(ans.begin(),ans.end(),[](int a, int b){
            return a>b;
        });
            
        
        return ans;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        long long int N;
        cin>>N;
        long long int Arr[N];
        for(long int i = 0;i < N;i++)
        cin>>Arr[i];
        Solution ob;
        vector<long long int>ans=ob.twoOddNum(Arr,N);
        for(long long int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
        cout<<endl;
    
cout << "~" << "\n";
}
    return 0;
}
// } Driver Code Ends