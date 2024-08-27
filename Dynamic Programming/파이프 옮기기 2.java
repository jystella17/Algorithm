// BOJ 17069 파이프 옮기기 2 (G4)
// (x,y)까지 도달하는 방법의 수 = 한 단계 전까지 도달하는 방법의 수(의 합) 임을 응용해야 함

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        int[][] house = new int[n+1][n+1];
        long[][][] dp = new long[3][n+1][n+1];
        
        for(int i=1; i<=n; i++) {
            st = new StringTokenizer(br.readLine());
            for(int j=1; j<=n; j++) {
                house[i][j] = Integer.parseInt(st.nextToken());
            }
        }
        
        dp[0][1][2] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=3; j<=n; j++) {
                if(house[i][j] == 1) continue;
                
                dp[0][i][j] = dp[0][i][j-1] + dp[2][i][j-1];
                
                if(i > 1) {
                    dp[1][i][j] = dp[1][i-1][j] + dp[2][i-1][j];
                }
                
                if(house[i-1][j] == 0 && house[i][j-1] == 0) {
                    dp[2][i][j] = dp[0][i-1][j-1] + dp[1][i-1][j-1] + dp[2][i-1][j-1];
                }
            }
        }
        System.out.println(dp[0][n][n] + dp[1][n][n] + dp[2][n][n]);
	}
}
