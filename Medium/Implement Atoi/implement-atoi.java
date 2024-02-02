//{ Driver Code Starts
//Initial template for JAVA

import java.util.Scanner;

class aToi
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		sc.nextLine();
		while(t>0)
		{
			String str = sc.nextLine();
			
			Solution obj = new Solution();
			int num = obj.atoi(str);
			
			System.out.println(num);
		t--;
		}
	}
}
// } Driver Code Ends


//User function template for JAVA

/*You are required to complete this method */
class Solution
{
    int atoi(String s) {
	// Your code here
	    s = s.trim();
	    if(s.isEmpty()){
	        return -1;
	    }
	    int result = 0;
	    boolean flag = false;
	    if(s.charAt(0) == '-'){
	        flag = true; 
	    }
	    int neg = 0;
	    if(flag){
	        neg += 1;
	    }
	    for(int i=neg;i<s.length();i++){
	        if(s.charAt(i) >= '0' && s.charAt(i)<= '9'){
	            int digit = s.charAt(i) - '0';
	            result = result*10 + digit;
	        }
	        else{
	            return -1;
	        }
	    }
	    if(flag){
	        return result*-1;
	    }
	    return result;
    }
}
