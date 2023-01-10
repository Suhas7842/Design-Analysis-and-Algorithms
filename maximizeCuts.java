import java.util.*;

public class maximizeCuts {
	
	public static int maxCuts(int n, int x, int y, int z)
    {
       int[] dp = new int[n+1];
       int[] val = {x,y,z};
       
       for(int i = 1;i<=n;i++){
           int max = Integer.MIN_VALUE;
           
           for(int j=0;j<3;j++){
               if(i - val[j] == 0) max = Math.max(max,1);
               else if(i - val[j] < 0) max = Math.max(max,0);
               else{
                   if(dp[i-val[j]] > 0) max = Math.max(max,dp[i-val[j]] + 1);
                   else max = Math.max(max,0);
               } 
           }
           
           dp[i] = max;
       }
       
       return dp[n];
    }
	
	public static void main(String[] args)
	{
		Scanner sc = new Scanner(System.in);
		System.out.println("Enter length of line segment:");
		int n = sc.nextInt();
		System.out.println("Enter cut segment length:");
		int a = sc.nextInt();
		int b = sc.nextInt();
		int c = sc.nextInt();
		System.out.println("Maximum number of Cut segments: "+maxCuts(n,a,b,c));
	}
}
