// SWEA D5 1247번 최적경로
// 순열 응용 (최대 O(10!) = 3628800이므로 완전탐색 사용 가능)

import java.util.*;
import java.io.*;

public class Solution {
    static int[][] customers;
    static int[] order;
    static boolean[] visited;
    static int n, answer;
    static int companyX, companyY, houseX, houseY;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
		    n = Integer.parseInt(br.readLine());
		    customers = new int[n][2];
		    order = new int[n];
		    visited = new boolean[n];
		    answer = 987654321;
		    
		    st = new StringTokenizer(br.readLine());
		    companyX = Integer.parseInt(st.nextToken());
		    companyY = Integer.parseInt(st.nextToken());
		    houseX = Integer.parseInt(st.nextToken());
		    houseY = Integer.parseInt(st.nextToken());
		    
		    for(int i=0; i<n; i++) {
		        int x = Integer.parseInt(st.nextToken());
		        int y = Integer.parseInt(st.nextToken());
		        customers[i][0] = x;
		        customers[i][1] = y;
		    }
		    
		    dfs(0);
		    System.out.printf("#%d %d\n", t, answer);
		}
	}
	
	static void dfs(int cnt) {
	    if(cnt == n) {
	        int distance = Math.abs(companyX - customers[order[0]][0]);
	        distance += Math.abs(companyY - customers[order[0]][1]);
	        
	        for(int i=1; i<n; i++) {
	            distance += Math.abs(customers[order[i]][0] - customers[order[i-1]][0]);
	            distance += Math.abs(customers[order[i]][1] - customers[order[i-1]][1]);
	        }
	        
	        distance += Math.abs(houseX - customers[order[n-1]][0]);
	        distance += Math.abs(houseY - customers[order[n-1]][1]);
	        
	        if(distance < answer) answer = distance;
	        return;
	    }
	    
	    for(int i=0; i<n; i++) {
	        if(visited[i] == true) continue;
	        
	        visited[i] = true;
	        order[cnt] = i;
	        dfs(cnt+1);
	        visited[i] = false;
	    }
	}
}
