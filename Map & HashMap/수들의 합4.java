// BOJ 2015 수들의 합4 (G4)
// 1차원 누적합 배열 + HashMap
// DP or 누적합 배열에 저장하는 데이터 => i번째 원소까지 고려했을 때 어떤 값의 등장 횟수, 연산값 등 => 
// 주어진 식을 변형시켰을 때 DP or 누적합 배열에 저장할 수 있는 형태의 데이터를 도출하려면 어떻게 해야할지 고민할 것.

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		long k = Long.parseLong(st.nextToken());
		
		long[] sum = new long[n+1];
		// key = sum[index]
		// value = index-1까지의 숫자들로 만들 수 있는 부분합 중 합이 sum[index] - k인 경우의 등장 횟수
		HashMap<Long, Integer> hm = new HashMap<>();
		st = new StringTokenizer(br.readLine());
		
		long answer = 0;
		for(int i=1; i<=n; i++) {
		    int num = Integer.parseInt(st.nextToken());
		    sum[i] = (sum[i-1] + num);
		    
		    if(sum[i] == k) answer++;
		}
		
		for(int i=1; i<=n; i++) {
		    answer += hm.getOrDefault(sum[i]-k, 0);
		    hm.put(sum[i], hm.getOrDefault(sum[i], 0) + 1);
		}
		System.out.println(answer);
	}
}
