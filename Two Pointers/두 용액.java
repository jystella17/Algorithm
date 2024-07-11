// BOJ 2470 두 용액 (G5)
// Two Pointers with long (8 bytes) data

import java.util.*;
import java.io.*;

public class Main {
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		List<Long> liquids = new ArrayList<>();
		st = new StringTokenizer(br.readLine());
		for(int i=0; i<n; i++) {
		    liquids.add(Long.parseLong(st.nextToken()));
		}
		Collections.sort(liquids);
		
		int left = 0, right = n-1;
    // 특성값이 999999999와 1000000000인 용액 두 개만 주어지는 경우, 답은 1999999999가 되므로
    // 2000000000 이상의 값으로 초기화해야 정상적으로 답을 구할 수 있다.
		long featureValue = 2000000001;
		long value1 = 0, value2 = 0;
		
		while(left < right) {
		    long sum = (liquids.get(left) + liquids.get(right));
		    if(Math.abs(sum) < featureValue) {
		        value1 = liquids.get(left); value2 = liquids.get(right);
		        featureValue = Math.abs(sum);
		    }
		    
		    if(sum < 0) left++;
		    else right--;
		}
		
		if(value1 > value2) {
		    long tmp = value1;
		    value1 = value2;
		    value2 = tmp;
		}
		System.out.println(value1 + " " + value2);
	}
}
