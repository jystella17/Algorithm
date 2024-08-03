// BOJ 15991 1,2,3 더하기 6 (S1)

import java.io.*;
import java.util.*;

public class Main {
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int tc = Integer.parseInt(st.nextToken());
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		long[] dp = new long[100001];
		dp[1] = 1; dp[2] = 2; dp[3] = 2;
		dp[4] = 3; dp[5] = 3; dp[6] = 6;
		
		for(int i=7; i<=100000; i++) {
		    dp[i] = (dp[i-2] + dp[i-4] + dp[i-6]) % 1000000009;
		}
		
		for(int t=0; t<tc; t++) {
		    st = new StringTokenizer(br.readLine());
		    int n = Integer.parseInt(st.nextToken());
		    bw.write(dp[n] + "\n");
		}
		bw.flush();
		bw.close();
	}
}
