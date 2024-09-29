// BOJ 16947 서울 지하철 2호선 (G3)
// Cycle Detection with DFS + m:n BFS
// DFS로 순환선(=Cycle)에 포함되는 역 번호 탐색
// BFS로 순환선을 구성하는 역에서 다른 모든 역들로 이동하는 최단거리 탐색 (프로그래머스 등산코스 정하기 참고)

import java.io.*;
import java.util.*;

public class Main {

    static int n;
    static boolean[] visited;
    static int[] parents, answer;
    static ArrayList<Integer>[] subway;
    static List<Integer> cycles;
    static boolean alreadyFound = false;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Integer.parseInt(st.nextToken());

        subway = new ArrayList[n+1];
        parents = new int[n+1];
        answer = new int[n+1];
        for(int i=1; i<=n; i++) {
            subway[i] = new ArrayList<>();
            answer[i] = -1;
        }

        for(int i=0; i<n; i++) {
            st = new StringTokenizer(br.readLine());
            int a = Integer.parseInt(st.nextToken());
            int b = Integer.parseInt(st.nextToken());

            subway[a].add(b);
            subway[b].add(a);
        }

        cycles = new ArrayList<>();
        visited = new boolean[n+1];
        visited[1] = true;
        // DFS로 순환선에 속하는 역 목록 구하기
        dfs(1);

        // BFS로 순환선에서 다른 모든 역까지의 최단 거리 구하기
        shortestPath();
        for(int i=1; i<=n; i++) {
            bw.write(answer[i] + " ");
        }
        bw.flush();
        bw.close();
    }

    static void dfs(int current) {
        for(int i=0; i<subway[current].size(); i++) {
            int next = subway[current].get(i);
            
            if(visited[next]) {
                // 다음으로 방문할 역을 이미 방문한 적이 있으면서(순환선을 구성할 가능성 존재)
                // 다음으로 방문할 역이 현재 방문하고 있는 역의 부모가 아니고 
                // (parent-child 관계인 경우, next는 current를 root로 하는 Subtree 탐색이 종료된 후 회귀하는 지점.
                // 따라서, next 역을 이미 방문한 적이 있다고 하더라도 current와 next가 cycle을 구성한다고 볼 수 없음 (재귀 call stack에 의한 중복 방문이므로))
                // 현재 노선도에서 아직 순환선을 찾은 적이 없는 경우
                if(parents[current] != next && !alreadyFound) {
                    alreadyFound = true;
                    traverseCycle(current, next);
                }
            } else { // 방문한 적 없는 역을 새롭게 방문하는 경우
                visited[next] = true;
                parents[next] = current; //  current를 거쳐야 next를 방문할 수 있으므로, current가 next의 부모
                dfs(next); // 다음 역으로 이동
            }
        }
    }

    static void traverseCycle(int start, int end) {
        // DFS로 cycle을 찾는 경우, 마지막 역에서 시작 역으로 이어지는 간선은 DFS Spanning Tree를 기준으로 역방향 간선에 해당
        // Tree 상에서 마지막 역은 시작 역의 자손인데, 마지막 역에서 시작 역으로 이동하는 간선이 존재해야 Cycle을 형성할 수 있음.
        // 따라서, dfs 함수의 if 조건을 모두 만족하는 시점에서 current = 순환선의 마지막 역, next = 순환선의 시작 역에 해당 (정확히는 "탐색을 시작한 역")
        while(start != end) {
            cycles.add(start); // 그러므로 current = start = 마지막 역에서 시작해, parent를 타고 올라가면서 순환선을 구성하는 역을 1개씩 저장
            start = parents[start];
        }
        cycles.add(end); // 마지막에 next = end = 시작 역을 추가로 저장
    }

    static void shortestPath() {
        Queue<Integer> queue = new LinkedList<>();
        // 시간복잡도를 줄이기 위해, 각 정점에서 모든 순환선 정점까지의 거리를 구하는 것이 아니라
        // 순환선에 속하는 역에서 출발해 모든 역을 방문할 때까지 탐색하면서, 지선에 속하는 각 역까지 도달하는 데에 시간이 얼마나 걸리는지 계산
        for(int c: cycles) {
            answer[c] = 0;
            queue.offer(c);
        }

        int result = 987654321;
        while(!queue.isEmpty()) {
            int current = queue.peek();
            queue.poll();

            for(int i=0; i<subway[current].size(); i++) {
                int next = subway[current].get(i);

                if(answer[next] == -1) {
                    answer[next] = answer[current] + 1;
                    queue.offer(next);
                }
            }
        }
    }
}
