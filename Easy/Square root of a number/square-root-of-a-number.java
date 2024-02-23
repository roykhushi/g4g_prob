//{ Driver Code Starts
import java.util.Scanner;

class SquartRoot
{
	public static void main(String args[])
	{
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t>0)
		{
			long a = sc.nextInt();
			Solution obj = new Solution();
			System.out.println(obj.floorSqrt(a));
		t--;
		}
	}
}
// } Driver Code Ends


/*You are required to complete
this function*/

// Function to find square root
// x: element to find square root
class Solution
{
     long floorSqrt(long x)
	 {
		// Your code here
		long start = 0;
		long end = x;
		long ans = -1;
		while(start <= end){
		    long mid = start + (end-start)/2;
		    long sq = (mid*mid);
		    if(sq == x){
		        return mid;
		    }
		    else if(sq > x){
		        end = mid-1;
		    }
		    else{
		        ans = mid;
		        start = mid+1;
		    }
		}
		return ans;
	 }
}
