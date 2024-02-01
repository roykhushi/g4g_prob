//{ Driver Code Starts
//Initial template for JAVA

import java.lang.*;
import java.io.*;
import java.util.*;


// } Driver Code Ends
//User function template for JAVA

class Solution
{
    //Function to check if a string is Pangram or not.
    public static boolean checkPangram  (String s) {
        // your code here
        HashSet<Character> set = new HashSet<>();
        s = s.toLowerCase();
        for(int i =0;i<s.length();i++){
            if(s.charAt(i)-'a' >=0 && s.charAt(i)-'a'<=25){//ascii value a=97 b=98..==>26 letters
                set.add(s.charAt(i));
            }
            if(set.size() == 26){
                return true;
            }
            
        }
        return false;
        
    }
}

//{ Driver Code Starts.

class GFG
 {
	public static void main (String[] args) throws IOException
	 {
	  BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	  int t=Integer.parseInt(br.readLine());
	  while(t-->0)
	  {
	    String s=br.readLine().trim();
	    
	    System.out.println(new Solution().checkPangram (s)==true?1:0);
	  }
	  
	 }
}
// } Driver Code Ends