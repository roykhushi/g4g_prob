//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;
class GfG
{
    public static void main(String args[])
        {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            while(t-->0)
                {
                    int n = sc.nextInt();
                    Solution ob = new Solution();
                    System.out.println(ob.padovanSequence(n));
                }
        }
}    
// } Driver Code Ends


//User function Template for Java

class Solution
{
  public int padovanSequence(int n)
    {
        //code here.
        int mod = 1000000007;
        //tle
        // if(n<=2){
        //     return 1;
        // }
        // return (padovanSequence(n-2)%mod + padovanSequence(n-3)%mod)%mod;
    
        //dp approach
        
        if(n<=2){
            return 1;
        }
        int pre0 =1 ;
        int pre1 = 1;
        int pre2 = 1;
        
        for(int i=3;i<=n;i++){
            int curr = (pre0+pre1)%mod;
            pre0 = pre1;
            pre1 = pre2;
            pre2 = curr;
        }
        
        return pre2;
    }
    
}
