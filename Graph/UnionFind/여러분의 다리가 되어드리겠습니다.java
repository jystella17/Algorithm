// BOJ 17352 여러분의 다리가 되어드리겠습니다! (G5)
// N-2개의 다리로 섬을 연결할 때, 2개의 서로소 집합이 만들어짐을 이용
// N-2개의 다리로 섬을 연결한 후, parents[i] = i 인 섬, 즉 집합의 root 역할을 하는 섬은 2개 존재 => 해당 값 출력

import java.io.*;
import java.util.*;

public class Main {
    
  static int n;
  static int[] parents;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		n = Integer.parseInt(st.nextToken());
		
		parents = new int[n+1];
		for(int i=1; i<=n; i++) {
		    parents[i] = i;
		}
		
		for(int i=0; i<n-2; i++) {
		    st = new StringTokenizer(br.readLine());
		    int a = Integer.parseInt(st.nextToken());
		    int b = Integer.parseInt(st.nextToken());
		    
		    union(a, b);
		}
		
		for(int i=1; i<=n; i++) {
		    if(parents[i] == i) {
		        bw.write(i + " ");
		    }
		}
		bw.flush();
		bw.close();
	}
	
	static int find(int x) {
	    if(parents[x] == x) {
	        return x;
	    }
	    
	    return find(parents[x]);
	}
	
	static void union(int a, int b) {
	    int pa = find(a);
	    int pb = find(b);
	    
	    if(pa < pb) {
	        parents[pb] = pa;
	    } else if(pa > pb) {
	        parents[pa] = pb;
	    }
	}
}
