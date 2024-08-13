// BOJ 2073 수도배관공사 (G4)
// index가 아닌 다른 값을 기준으로 dp 배열을 만들 수 있음에 유의
// index가 아닌 값을 기준으로 dp 배열을 만들더라도, 모든 입력값이 계산 시에 고려되어야 함에 유의 (크기를 비교, 정렬, 대표값 뽑기 등 X)

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int d = Integer.parseInt(st.nextToken());
		int p = Integer.parseInt(st.nextToken());
		
		int[] capacity = new int[d+1];
		capacity[0] = 987654321;
		
		for(int i=0; i<p; i++) {
		    st = new StringTokenizer(br.readLine());
		    int l = Integer.parseInt(st.nextToken());
		    int c = Integer.parseInt(st.nextToken());
		    
		    // l ~ d 순으로 탐색할 경우 capacity[l]이 중복 호출됨
		    // ex. d=7일 때, l=4, l=3인 파이프가 각각 1개씩 등장한 경우
		    // 길이 6인 수도관을 만들 수 없음 (capacity[6] = 0)
		    // 하지만 오름차순으로 탐색하는 경우, capacity[3]이 이미 계산된 상태이므로
		    // (= l=3인 파이프가 이전에 등장한 것과 동일한 상태)
		    // capacity[6]이 양수 값을 갖게 됨 (길이 6인 수도관을 만들 수 있음)
		    for(int len=d; len>=l; len--) {
		        int tmp = Math.min(capacity[len-l], c);
		        capacity[len] = Math.max(capacity[len], tmp);
		    }
		}
		System.out.println(capacity[d]);
	}
}
