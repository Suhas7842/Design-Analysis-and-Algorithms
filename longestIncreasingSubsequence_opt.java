import java.io.*;
import java.util.*; 

class longestIncreasingSubsequence_opt {
	
	//Time complexity - O(n*log(n))
	//Space Complexity - O(n)
	
    public static int ceilIdx(int tail[],int l,int r,int x)
    {
        while(r>l)
        {
            int m=l+(r-l)/2;
            if(tail[m]>=x)
            {
                r=m;
            }
            else
            {
                l=m+1;
            }
        }
        return r;
    }
    public static int longestSubsequence(int[] nums) {
        int[] tail = new int[nums.length];
        tail[0]=nums[0];
        int count=1;
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]>tail[count-1])
            {
                tail[count]=nums[i];
                count++;
            }
            else
            {
                int c = ceilIdx(tail,0,count-1,nums[i]);
                tail[c]=nums[i];
            }
        }
        return count;
    }

  public static void main(String args[]) throws IOException {
      Scanner sc = new Scanner(System.in);
      System.out.println("Test Cases:");
      int t = sc.nextInt();
      while(t-->0){
    	  System.out.println("Enter size of array: ");
          int n = sc.nextInt();
          int[] nums = new int[n];
          System.out.println("Enter array:");
          for (int i = 0; i < n; ++i)
          {
              nums[i] = sc.nextInt();
          }
          System.out.println("Length of longest subsequence is: "+longestSubsequence(nums));
      }
  } 
} 