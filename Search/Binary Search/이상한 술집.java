// BOJ 13702 이상한 술집 (S2)
// Parametric Search

import java.util.*;
import java.io.*;

public class Main {
	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    StringTokenizer st = new StringTokenizer(br.readLine());
	    
	    long n = Long.parseLong(st.nextToken());
	    long k = Long.parseLong(st.nextToken());
	    
	    long[] kettles = new long[10000];
	    long biggest = 0;
	    
	    for(int i=0; i<n; i++) {
	        kettles[i] = Long.parseLong(br.readLine());
	        biggest = Math.max(biggest, kettles[i]);
	    }

	    long low = 1, high = biggest;
	    while(low <= high) {
	        long count = 0;
	        long mid = (low + high) / 2;
	        
	        for(int i=0; i<n; i++) {
	            count += (kettles[i] / mid);
	        }
	        
	        if(count >= k) low = mid+1;
	        else high = mid-1;
	    }
	    System.out.println(high);
	}
}
