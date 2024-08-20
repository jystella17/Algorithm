// BOJ 17485 진우의 달 여행 (Large) (G5)
// 3차원 DP => Edge case를 통해 직전 row에서 최소값만 선택하는 방식이 최적해를 보장하지 않는다는 것을 확인해야 함

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		
		int[][] fuels = new int[n][m];
		int[][][] dp = new int[n][m][3];
		int[] directions = new int[] {-1, 0, 1};
		int[] lastDir = new int[m];
		
		for(int i=0; i<n; i++) {
		    st = new StringTokenizer(br.readLine());
		    for(int j=0; j<m; j++) {
		        fuels[i][j] = Integer.parseInt(st.nextToken());
		        Arrays.fill(dp[i][j], Integer.MAX_VALUE);
		    }
		}
		
		for(int i=0; i<m; i++) {
		    dp[0][i][0] = fuels[0][i];
		    dp[0][i][1] = fuels[0][i];
		    dp[0][i][2] = fuels[0][i];
		}
        
		for(int i=1; i<n; i++) {
		    for(int j=0; j<m; j++) {
		        if(j+1 < m) {
		            dp[i][j][0] = Math.min(dp[i-1][j+1][1], dp[i-1][j+1][2]) + fuels[i][j];
		        }
		        
		        if(j-1 >= 0) {
		            dp[i][j][2] = Math.min(dp[i-1][j-1][0], dp[i-1][j-1][1]) + fuels[i][j];
		        }
		        
		        dp[i][j][1] = Math.min(dp[i-1][j][0], dp[i-1][j][2]) + fuels[i][j];
		    }
		}

		int answer = 987654321;
        for(int i=0; i<m; i++) {
            for(int j=0; j<3; j++) {
                answer = Math.min(dp[n-1][i][j], answer);
            }
        }
        System.out.println(answer);
	}
}
