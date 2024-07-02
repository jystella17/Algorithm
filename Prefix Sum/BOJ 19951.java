// 백준 19951 태상이의 훈련소 생활 (G5)
// 누적합 응용

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		int m = Integer.parseInt(st.nextToken());
		int[] heights = new int[n+1];
		int[] diff = new int[n+2];
		
		st = new StringTokenizer(br.readLine());
		for(int i=1; i<=n; i++) {
		    heights[i] = Integer.parseInt(st.nextToken());
		}
		
		for(int i=0; i<m; i++) {
		    st = new StringTokenizer(br.readLine());
		    int a = Integer.parseInt(st.nextToken());
		    int b = Integer.parseInt(st.nextToken());
		    int k = Integer.parseInt(st.nextToken());
		    
		    diff[a] += k;
		    diff[b+1] += k*(-1);
		}
		
		for(int i=1; i<=n+1; i++) {
		    diff[i] += diff[i-1];
		}
		
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		for(int i=1; i<=n; i++) {
		    int answer = heights[i] + diff[i];
		    bw.write(answer+ " ");
		}
		bw.flush();
		bw.close();
	}
}
