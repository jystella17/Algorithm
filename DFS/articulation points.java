// 절단점 (Articulation Points or Cut Vertices) 찾기 알고리즘 예제

import java.io.*;
import java.util.*;

public class Main {
    
    static int n = 8;
    static int counter = 0;
    static int[] sequences;
    static List<Integer>[] graph;
    static Set<Integer> spofList;
    
	public static void main(String[] args) {
		
		sequences = new int[n];
		spofList = new HashSet<>();
		graph = new ArrayList[n];
		for(int i=0; i<n; i++) {
		    graph[i] = new ArrayList<>();
		}
		
		graph[0].add(1); graph[1].add(0);
		graph[1].add(2); graph[2].add(1);
		graph[1].add(3); graph[3].add(1);
		graph[2].add(3); graph[3].add(2);
		graph[2].add(5); graph[5].add(2);
		graph[3].add(4); graph[4].add(3);
		graph[3].add(5); graph[5].add(3);
		graph[5].add(6); graph[6].add(5);
		graph[5].add(7); graph[7].add(5);
		
		int answer = dfs(0, true);
    
		for(int s: spofList) {
		    System.out.print(s + " ");
		}
	}
	
	// return하는 데이터 = 현재 정점에서 도달 가능한 조상 중 방문 순서가 가장 빠른 조상의 순번
	static int dfs(int current, boolean isRoot) {
	    sequences[current] = ++counter;
	    // 현재 정점에서 도달 가능한 정점 중 방문 순서가 가장 빠른 정점의 순번은 기본적으로 현재 정점의 순번
	    int result = sequences[current];
	    
	    // current가 root 정점인 경우, root의 조상에 대한 탐색은 불가능하므로
	    // root 바로 다음에 방문되어야 하는 정점(= root와 연결되어 있으면서 
	    // 재귀 호출 순서로 인해 다른 정점으로부터 먼저 방문되지 않는 정점)이 2개 이상이면 root는 절단점에 포함
	    // 그렇지 않은 경우, root 바로 다음 정점을 새로운 root로 하는 단일 컴포넌트 존재 (절단점 X)
	    int children = 0; // 따라서, root의 자손 개수를 카운트해야 함
	    for(int i=0; i<graph[current].size(); i++) {
	        int next = graph[current].get(i);
	        
	        // sequences 배열은 0으로 초기화되었고, 가장 먼저 방문되는(root) 정점의 방문 순번은 1
	        // 따라서 next 정점을 방문한 적이 없는 경우, sequences[next] = 0임을 이용
	        if(sequences[next] == 0) {
	            children++; // 다른 정점에 의해 먼저 방문되지 않았으므로, 카운트 증가
	            
	            // next(= next를 root로 하는 subtree)에서 도달할 수 있는 정점 중 방문 순서가 가장 빠른 정점의 순번 구하기
	            // 주의: current가 next의 parent이므로, next는 어떤 경우에도 root가 될 수 없음.
	            // 따라서 isRoot를 false로 할당
	            int minAncestor = dfs(next, false);
	            
	            // next에서 역방향으로 도달 가능한 정점 중 current의 조상이 없으면
	            // = next와 연결된 정점 중 current보다 먼저 방문되는 정점이 없으면
	            if(!isRoot && minAncestor >= sequences[current]) {
	                spofList.add(current); // 절단점 추가
	                // 단, root의 절단점 여부는 이 방법으로 정확하게 판단할 수 없으므로
	                // current가 root가 아닌 경우에만 적용되는 로직
	            }
	            
	            // next에 대한 조상 탐색이 끝난 후, current 정점에서 도달 가능한 정점의 최소 순번 업데이트
	            // current는 next 직전에 방문되는 정점이므로 (next의 직전 조상)
	            // next의 조상이면서 current보다 먼저 방문되는 정점 = current의 조상
	            // 따라서 current에서 도달 가능한 정점의 최소 순번이 업데이트 되어야 함.
	            // 반대로 next가 current의 조상에 도달할 수 없다면, 현재 값 유지
	            result = Math.min(result, minAncestor);
	        } else {
	            // next가 이미 방문된 정점인 경우
	            // sequences[next] = next에서 도달 가능한 정점의 최소 순번이 이미 업데이트 된 상태
	            // 이 경우 역시 current는 next 직전에 방문되는 정점이므로 (next의 직전 조상)
	            // next의 조상이면서 current보다 먼저 방문되어야 하는 정점 = current의 조상
	            // 따라서 current에서 도달 가능한 정점의 최소 순번 업데이트
	            // 그렇지 않은 경우 현재 값 유지
	            result = Math.min(result, sequences[next]);
	        }
	    }
	    
	    // if(!isRoot)에 의해 current = root인 경우의 절단점 업데이트는 전혀 수행되지 않았으므로
	    // child가 2개 이상인 경우 절단점 업데이트 수행
	    if(isRoot && children >= 2) {
	        spofList.add(current);
	    }
	    return result;
	}
}
