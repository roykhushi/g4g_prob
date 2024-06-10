//{ Driver Code Starts
//Initial Template for Java

import java.io.*;
import java.util.*;

class GFG
{
    public static void main(String args[])throws IOException
    {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        while(t-- > 0)
        {
            String s;
            s = sc.next();
            
            Solution ob = new Solution();
            
            System.out.println(ob.reverseWords (s));    
        }
    }
}
// } Driver Code Ends


//User function Template for Java
class Solution
{
   
    String reverseWords(String S)
    {
        Stack<Character> st = new Stack<>();
        StringBuilder ans = new StringBuilder();
        
        for(int i=0;i<S.length();i++){
            
            char ele = S.charAt(i);
            
            if(ele!='.'){
                st.push(ele);
            }
            else{
                while(!st.empty()){
                    ans.append(st.pop());
                }
                ans.append('.');
            }
            
        }
        
        while(!st.empty()){
            ans.append(st.pop());
        }
        
        return ans.toString();
    }
}