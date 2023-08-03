// SWEA D3 5215번 햄버거 다이어트
// 순열 응용

import java.util.*;
import java.io.*;

public class Solution {
    
    static int n, l, answer;
    static int[] flavor;
    static int[] calories;
    static boolean[] selected;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st;
		int T = Integer.parseInt(br.readLine());
		
		for(int t=1; t<=T; t++) {
		    answer = 0;
		    st = new StringTokenizer(br.readLine());
		    n = Integer.parseInt(st.nextToken());
		    l = Integer.parseInt(st.nextToken());
		    
		    flavor = new int[n];
		    calories = new int[n];
		    selected = new boolean[n];
		    
		    for(int i=0; i<n; i++) {
		        st = new StringTokenizer(br.readLine());
		        flavor[i] = Integer.parseInt(st.nextToken());
		        calories[i] = Integer.parseInt(st.nextToken());
		    }
		    
		    hamburger(0, 0, 0);
		    System.out.printf("#%d %d\n", t, answer);
		}
	}
	
	static void hamburger(int idx, int flavorSum, int calorieSum) {
	    if(calorieSum > l) return;
	    if(idx == n) {
	        answer = Math.max(answer, flavorSum);
	        return;
	    }
	    
	    selected[idx] = true;
	    hamburger(idx+1, flavorSum+flavor[idx], calorieSum+calories[idx]);
	    selected[idx] = false;
	    hamburger(idx+1, flavorSum, calorieSum);
	}
}
