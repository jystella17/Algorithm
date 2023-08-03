// SWEA 4012번 요리사
// 조합 응용

import java.util.*;
import java.io.*;

public class Main {

    static int n, answer;
    static int[][] synergy;
    static boolean[] selected;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
		    answer = 987654321;
		    n = Integer.parseInt(br.readLine());
		    synergy = new int[n][n];
		    selected = new boolean[n];
		    
		    for(int i=0; i<n; i++) {
		        st = new StringTokenizer(br.readLine());
		        for(int j=0; j<n; j++) {
		            synergy[i][j] = Integer.parseInt(st.nextToken());
		        }
		    }
		    
		    combination(0, 0);
		    System.out.printf("#%d %d\n", t, answer);
		}
	}
	
	static void combination(int idx, int cnt) {
	    if(idx == n) return;
	    
	    if(cnt == n/2) {
	        answer = Math.min(answer, difference());
	        return;
	    }
	    
	    selected[idx] = true;
	    combination(idx+1, cnt+1);
	    selected[idx] = false;
	    combination(idx+1, cnt);
	}
	
	static int difference() {
	    int flavorA = 0, flavorB = 0;
	    
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<n; j++) {
	            if(i == j) continue;
	            
	            if(selected[i] == true && selected[j] == true) {
	                flavorA += synergy[i][j];
	            }
	            
	            else if(selected[i] == false && selected[j] == false) {
	                flavorB += synergy[i][j];
	            }
	        }
	    }
	    return Math.abs(flavorA - flavorB);
	}
}
