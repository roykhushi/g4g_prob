//{ Driver Code Starts
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.*;


public class Driver {
    
    public static void main(String[] args)throws IOException {
       
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int tc = Integer.parseInt(br.readLine());
        while(tc-->0)
        {
            String s1 = br.readLine();
            String s2 = br.readLine();
            
            Solution obj = new Solution();
            
            boolean a = obj.areIsomorphic(s1,s2);
            if(a)
            System.out.println(1);
            else
            System.out.println(0);
        }
    }
    
}

// } Driver Code Ends




class Solution
{
    //Function to check if two strings are isomorphic.
    public static boolean areIsomorphic(String str1,String str2)
    {
        // Your code here
        HashMap<Character,Character> map1 =  new HashMap<>();
        HashMap<Character,Character> map2 =  new HashMap<>();
        if(str1.length() != str2.length()){
            return false;
        }
        for(int i=0;i<str1.length();i++){
            char let1 = str1.charAt(i);
            char let2 = str2.charAt(i);
            //map1
            if(map1.containsKey(let1)){
                if(map1.get(let1) != let2){
                    return false;
                }
            }
            else{
                map1.put(let1,let2);
            }
            //map2
            if(map2.containsKey(let2)){
                if(map2.get(let2) != let1){
                    return false;
                }
            }
            else{
                map2.put(let2,let1);
            }
            
        }
        return true;
    }
}