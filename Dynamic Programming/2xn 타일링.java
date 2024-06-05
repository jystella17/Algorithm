// BOJ 11726 2Xn 타일링 (S3)

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		int dp[] = new int[1001];
		dp[0] = 0; dp[1] = 1; dp[2] = 2;
		
		for(int i=3; i<=n; i++) {
		    dp[i] = (dp[i-1] + dp[i-2]) % 10007;
		}
		
		System.out.println(dp[n]);
	}
}
