// BOJ 1890 점프 (S1)
// DFS or BFS로 풀 수 없는 이유 => 조합론
// (1, 1) -> (n, n)까지 가기 위해 오른쪽으로 가는 선택을 n번, 아래쪽으로 가는 선택을 n번 해야 함 => 총 2n번의 선택
// 2n개의 문자(n개의 R, n개의 D)를 나열하는 경우의 수 = (1, 1) -> (n, n)까지 가는 경로의 수
// = 2n! / n! * n! = 2n C n
// n <= 100 이므로 최대 200 C 100 => 완전탐색으로 풀 경우 시간초과
// 위상 정렬 방법론을 활용해 Tabulation DP로 풀 수도 있음

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int[][] map = new int[n+1][n+1];
		long[][] dp = new long[n+1][n+1];
		
		for(int i=1; i<=n; i++) {
		    st = new StringTokenizer(br.readLine());
		    for(int j=1; j<=n; j++) {
		        map[i][j] = Integer.parseInt(st.nextToken());
		    }
		}
		
		int[] dx = {0, 1}, dy = {1, 0};
		dp[1][1] = 1;
		
		for(int i=1; i<=n; i++) {
		    for(int j=1; j<=n; j++) {
		        if(i == n && j == n) break;
		        
		        for(int k=0; k<2; k++) {
		            int nx = i + (dx[k] * map[i][j]);
		            int ny = j + (dy[k] * map[i][j]);
		            
		            if(nx < 1 || nx > n || ny < 1 || ny > n) continue;
		            else dp[nx][ny] += dp[i][j];
		        }
		    }
		}
		System.out.println(dp[n][n]);
	}
}
