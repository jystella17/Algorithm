// BOJ 17951 흩날리는 시험지 속에서 내 평점이 느껴진거야 (G3)
// Optimization problem = n개의 시험지를 (순서를 유지하며) k개의 그룹으로 나눴을 때, 점수 합계가 가장 작은 그룹의 최대 점수 구하기
// Decision problem = n개의 시험지를 (순서를 유지하며) k개의 그룹으로 나눴을 때, 각 그룹의 점수 합계가 각각 k 이상인가?

import java.io.*;
import java.util.*;

public class Main {
    
    static int[] scores;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int k = Integer.parseInt(st.nextToken());
		
		scores = new int[n];
		st = new StringTokenizer(br.readLine());
		int low = 0, high = 0;
		
		for(int i=0; i<n; i++) {
		    scores[i] = Integer.parseInt(st.nextToken());
		    high += scores[i];
		}

		while(low <= high) {
		    int mid = (low + high) / 2;

		    if(isBiggerThan(k, mid)) low = mid + 1;
		    else high = mid - 1;
		}
		System.out.println(high);
	}
	
	static boolean isBiggerThan(int k, int target) {
	    int sum = 0, groups = 0;
	    
	    for(int i=0; i<scores.length; i++) {
	        sum += scores[i];
	        
	        if(sum >= target) {
	            sum = 0;
	            groups++;
	        }
	    }

	    if(groups >= k) return true;
	    else return false;
	}
}
