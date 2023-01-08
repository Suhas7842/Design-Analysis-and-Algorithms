import java.util.*;

public class buildBridges {
	
	
	// Time complexity - O(n*log(n))
	// To solve we sort the 2D-array in non-decreasing order of the first column.
	// Then we use longest Increasing Subsequence to get maximum bridges.
	
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
    
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter number of posts to build bridge");
		int n = sc.nextInt();
		int[][] posts =new int[n][2];
		System.out.println("Enter posts of the bridge on either side:");
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				posts[i][j]=sc.nextInt();
			}
		}
		
		// Sorting the array in non-decreasing order.
		Arrays.sort(posts, (a, b) -> Double.compare(a[0], b[0]));
		int[] nums = new int[n];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<2;j++)
			{
				nums[i]=posts[i][1];
			}
		}
		System.out.println("Maximum number of bridges that can be built:"+longestSubsequence(nums));
	}
}
