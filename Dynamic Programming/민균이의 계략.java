// BOJ 11568 민균이의 계략 (S2)
// LIS 기본

import java.io.*;
import java.util.*;

public class Main {
    
    static int[] cards = new int[1001];
    // cards[i]를 가장 큰 원소로 하는 증가 수열의 최대 길이
    static int[] maxCardsNum = new int[1001];
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
		    cards[i] = Integer.parseInt(st.nextToken());
		}

		maxCardsNum[1] = 1;
		for(int i=2; i<=n; i++) {
		    for(int j=1; j<i; j++) {
		        if(cards[i] > cards[j]) {
		            maxCardsNum[i] = Math.max(maxCardsNum[i], maxCardsNum[j]+1);
		        } else {
		            maxCardsNum[i] = Math.max(maxCardsNum[i], 1);
		        }
		    }
		}
		
		int answer = 0;
		for(int i=1; i<=n; i++) {
		    answer = Math.max(answer, maxCardsNum[i]);
		}
		System.out.println(answer);
	}
}
