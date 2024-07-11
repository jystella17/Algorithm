// BOJ 17829 222 풀링 (S2)
// Divide and Conquer

import java.util.*;
import java.io.*;

public class Main {
    
    static int[][] matrix;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		matrix = new int[n][n];
		
		for(int i=0; i<n; i++) {
		    st = new StringTokenizer(br.readLine());
		    for(int j=0; j<n; j++) {
		        matrix[i][j] = Integer.parseInt(st.nextToken());
		    }
		}
		System.out.println(pooling(n, 0, 0));
	}
	
	public static int pooling(int size, int starti, int startj) {
	    if(size == 2) {
	        int bound1 = starti + 1;
	        int bound2 = startj + 1;
	        List<Integer> numbers = new ArrayList<>();
	        
	        for(int i=starti; i<=bound1; i++) {
	            for(int j=startj; j<=bound2; j++) {
	                numbers.add(matrix[i][j]);
	            }
	        }
	        Collections.sort(numbers);
	        return numbers.get(2);
	    }
	    
	    List<Integer> candidates = new ArrayList<>();
	    // 왼쪽 위
	    candidates.add(pooling(size/2, starti, startj));
	    // 오른쪽 위
	    candidates.add(pooling(size/2, starti, startj + size/2));
	    // 왼쪽 아래
	    candidates.add(pooling(size/2, starti + size/2, startj));
	    // 오른쪽 아래
	    candidates.add(pooling(size/2, starti + size/2, startj + size/2));
	    
	    Collections.sort(candidates);
	    return candidates.get(2);
	}
}
