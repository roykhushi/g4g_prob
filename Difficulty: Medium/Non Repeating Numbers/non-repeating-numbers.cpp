//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution
{
public:
    vector<int> singleNumber(vector<int> nums) 
    {
        // Code here.
        vector<int> res;
        
        
        //TLE ===> O(n) space
        // unordered_map<int,int> mp; 
        
        // for(int i=0;i<nums.size();i++){
        //     mp[nums[i]]++;
        // }
        // for(auto i : mp){
        //     if(i.second == 1){
        //         res.push_back(i.first);
        //     }
        // }
        
        //using bit masking
        
        int ans = 0;
        
        for(int i=0;i<nums.size();i++){ //xor of two distinct nos
            ans = ans^nums[i];
        }
        
        int mask = ((ans) & (-ans));
        
        int num1 = 0;
        int num2 = 0;
        
        for(int num : nums){
            if(num & mask){
                num1^=num;
            }
            else{
                num2^=num;
            }
        }
        
        res.push_back(num1);
        res.push_back(num2);
        sort(res.begin(),res.end());
        
        return res;
    }
};

//{ Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}
// } Driver Code Ends