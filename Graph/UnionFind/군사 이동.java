// BOJ 11085 군사 이동 (G3)
// MST or Union Find 풀이 가능
// Union Find - 모든 길을 너비의 내림차순으로 정렬하고, C, V의 root가 같아질 때까지 각 지점을 연결

import java.io.*;
import java.util.*;

class Node {
    int start;
    int end;
    int width;
    
    public Node(int start, int end, int width) {
        this.start = start;
        this.end = end;
        this.width = width;
    }
}

class NodeComparator implements Comparator<Node> {
    
    @Override
    public int compare(Node n1, Node n2) {
        if(n1.width == n2.width) {
            if(n1.start == n2.start) {
                return n1.end - n2.end;
            } else {
                return n1.start - n2.start;
            }
        } else {
            return n2.width - n1.width;
        }
    }
}

public class Main {
    
  static int[] parents;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int p = Integer.parseInt(st.nextToken());
		int w = Integer.parseInt(st.nextToken());
		
		st = new StringTokenizer(br.readLine());
		int c = Integer.parseInt(st.nextToken());
		int v = Integer.parseInt(st.nextToken());
		
		PriorityQueue<Node> pq = new PriorityQueue<>(new NodeComparator());
		for(int i=0; i<w; i++) {
		    st = new StringTokenizer(br.readLine());
		    int start = Integer.parseInt(st.nextToken());
		    int end = Integer.parseInt(st.nextToken());
		    int width = Integer.parseInt(st.nextToken());
		    
		    pq.offer(new Node(start, end, width));
		}
		
		parents = new int[p];
		for(int i=0; i<p; i++) {
		    parents[i] = i;
		}
		int minimum = 1001;

    // C, V의 root가 같아지면 두 지점이 연결된 것이므로 탐색 종료
    // pq.isEmpty()를 종료 조건으로 설정하는 경우, C, V가 연결된 후에도 다른 지점들이 계속 C와 연결되면서 오답이 나올 수 있음
    // 모든 지점이 C를 root로 가질 필요는 없음 (C와 연결될 필요는 없음)에 유의
		while(find(c) != find(v)) {
		    Node node = pq.poll();
		    int a = node.start;
		    int b = node.end;
		    int width = node.width;
		    
		    if(find(a) != find(b)) {
		        minimum = Math.min(minimum, width);
		        union(a, b, c);
		    }
		}
		System.out.println(minimum);
	}
	
	public static int find(int x) {
	    if(x == parents[x]) {
	        return x;
	    }
	    return find(parents[x]);
	}
	
	public static void union(int a, int b, int start) {
	    int pa = find(a);
	    int pb = find(b);
	    
	    if(pa == pb) return;
	    else if(pa == start) parents[pb] = start;
	    else if(pb == start) parents[pa] = start;
	    else if(pa < pb) parents[pb] = pa;
	    else parents[pa] = pb;
	}
}
