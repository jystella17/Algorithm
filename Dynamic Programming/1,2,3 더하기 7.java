// BOJ 15992 1,2,3 더하기 7 (S1)

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken());
		int mod = 1000000009;
		
		int[][] dp = new int[1001][1001];
		dp[1][1] = 1; dp[2][1] = 1; dp[2][2] = 1;
		dp[3][1] = 1; dp[3][2] = 2; dp[3][3] = 1;
		dp[4][2] = 3; dp[4][3] = 3; dp[4][4] = 1;
		
		for(int i=5; i<=1000; i++){
		    for(int j=1; j<=i; j++){
		        dp[i][j] = (dp[i-1][j-1] + dp[i-2][j-1]) % mod;
		        dp[i][j] = (dp[i][j] + dp[i-3][j-1]) % mod;
		    }
		}
		
		for(int t=0; t<tc; t++){
		    st = new StringTokenizer(br.readLine());
		    int n = Integer.parseInt(st.nextToken());
		    int m = Integer.parseInt(st.nextToken());

		    bw.write(dp[n][m] + "\n");
		}
		bw.flush();
		bw.close();
	}
}
