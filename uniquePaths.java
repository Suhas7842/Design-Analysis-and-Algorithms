import java.io.*;
import java.util.*;

class uniquePaths {
	
    public static int NumberOfPath(int m, int n) {
        int N = n + m - 2;
            int r = m - 1; 
            double res = 1;
            
            for (int i = 1; i <= r; i++)
                res = res * (N - r + i) / i;
            return (int)res;
    }
    
	public static void main (String[] args) {
		Scanner sc=new Scanner(System.in);
		System.out.println("Test Cases: ");
		int t=sc.nextInt();
		while(t-->0)
		{
			System.out.println("Enter number of rows:");
		    int a=sc.nextInt();
		    System.out.println("Enter number of columns:");
		    int b=sc.nextInt();
		    System.out.println("Number of unique paths: "+NumberOfPath(a,b));
		}
	}
}