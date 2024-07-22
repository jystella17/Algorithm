// BOJ 12026 BOJ 거리 (S1)

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
        int n = Integer.parseInt(st.nextToken());
        // 0 = B, 1 = O, 2 = J
        int[] block = new int[n+1];
        int[] energy = new int[n+1]; // i번째 알파벳까지 도달하는 데 필요한 최소 에너지
        st = new StringTokenizer(br.readLine());
        char[] tmp = st.nextToken().toCharArray();
        
        for(int i=1; i<=n; i++) {
            if(tmp[i-1] == 'B') block[i] = 0;
            else if(tmp[i-1] == 'O') block[i] = 1;
            else block[i] = 2;
            
            energy[i] = 987654321;
        }
        
        energy[1] = 0;
        for(int i=2; i<=n; i++) {
            boolean isFound = false;
            
            for(int j=1; j<i; j++) {
                if(block[j] == (block[i] + 2) % 3) {
                    if(energy[j] > -1) {
                        isFound = true;
                        energy[i] = Math.min(energy[i], energy[j] + (i-j)*(i-j));
                    }
                }
            }
            // i번째 위치의 알파벳보다 한 단계 이전의 알파벳이 존재하지 않거나
            // 존재하더라도 B -> O -> J -> B -> ... 순서대로 방문할 수 없다면 -1로 처리
            if(!isFound) energy[i] = -1;
        }
        
        System.out.println(energy[n]);
	}
}
