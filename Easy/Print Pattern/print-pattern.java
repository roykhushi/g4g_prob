//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG{
    public static void main(String args[])throws IOException
    {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        while(t-- > 0){
            int N = Integer.parseInt(in.readLine().trim());
            
            Solution ob = new Solution();
            List<Integer> ans = new ArrayList<Integer>();
            ans = ob.pattern(N);
            for(int i = 0;i < ans.size();i++)
                System.out.print(ans.get(i) + " ");
            System.out.println();
        }
    }
}
// } Driver Code Ends


//User function Template for Java

class Solution{
    public List<Integer> pattern(int N){
        // code here
        List<Integer> ans=new ArrayList<>();
        if(N<=0)
        {
        ans.add(N);
        return ans;
        }
        negative(N,ans);
        int x=ans.get(ans.size()-1)+5;
        positive(N,x,ans);
        return ans;
    }
    public void negative(int N,List<Integer> ans){
        if(N<=0)
        {ans.add(N) ;
        return;}
        ans.add (N);
        negative(N-5,ans);
    }
    public void positive(int N,int x,List<Integer> ans){
        if(x==N)
        { ans.add(N);
        return ;}
        ans.add (x);
        positive(N,x+5,ans);
    }
   }
