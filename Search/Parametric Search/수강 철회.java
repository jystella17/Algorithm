// 알고리즘 문제해결 전략 예제
// ID: WITHDRAWAL 난이도 : 상
// 풀기 어려운 결정 문제 => 수식 형태로 작성하고, 식을 변형해 풀기 쉬운 형태로 만들 것.
// 결정 문제는 parameter로 주어진 값 x에 대해 x 이상/이하를 만족하는지 판정 (정확하게 x인지 판정하는 것이 아님) 
// => 값의 범위를 판정한다는 개념을 수식을 세울 때에도 반영할 것.

import java.io.*;
import java.util.*;

public class Main {
    
    static List<Double> middleScores;
    static int[] r;
    static int[] c;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken());
		
		for(int t=0; t<tc; t++) {
		    st = new StringTokenizer(br.readLine());
		    int n = Integer.parseInt(st.nextToken());
		    int k = Integer.parseInt(st.nextToken());
		    
		    r = new int[n]; c = new int[n];
		    st = new StringTokenizer(br.readLine());
		    
		    for(int i=0; i<n; i++) {
		        r[i] = Integer.parseInt(st.nextToken());
		        c[i] = Integer.parseInt(st.nextToken());
		    }
		    
		    double low = 0, high = 1;
		    for(int it=0; it<100; it++) {
		        double mid = (low + high) / 2;
		        
		        if(decision(mid, n, k)) high = mid;
		        else low = mid;
		    }
		    System.out.printf("%.10f", high);
		}
	}
	
	static boolean decision(double score, int n, int k) {
	     middleScores = new ArrayList<>();
	     for(int i=0; i<n; i++) {
	         middleScores.add(score * c[i] - r[i]);
	     }
	     Collections.sort(middleScores);
	     
	     double sum = 0;
	     for(int i=(n-k); i<n; i++) {
	         sum += middleScores.get(i);
	     }
	     
	     return sum >= 0;
	}
}
