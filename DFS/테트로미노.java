// BOJ 14500 테트로미노 (G4)
// DFS + 예외 케이스에 대해 Rule-based Brute Force
// 1~4번째 테트로미노는 DFS, 5번째(ㅜ 모양) 테트로미노는 Brute Force
// 재귀+DFS의 특성(더 이상 탐색할 수 없는 지점에 도달할 때까지 이전의 선택 상태를 유지하고 다음 칸으로 이동) 이용
// 1~4번째 테트로미노와 이를 변형한 모든 형태는 DFS로 만들 수 있는 궤적이므로, DFS 탐색 가능
// 5번째 테트로미노는 가운데 칸이 분기점이 되어, 분기점에서 동시에 갈라져 나오는 두 지점을 순차적으로 방문해야 만들 수 있는 형태 => 
// 재귀호출 트리에서, 같은 부모에게서 파생되는 자식은 한 케이스에서 1개만 방문되고 다음 Depth로 이동해야 한다. 
// 따라서 5번째 테트로미노는 재귀+DFS로 만들 수 없는 궤적이다. 좌표 이동값을 따로 저장하고 탐색해야 한다.

import java.io.*;
import java.util.*;

public class Main {
    
    static int n, m;
    static int[] dx = {1, -1, 0, 0}, dy = {0, 0, 1, -1};
    static int[][] paper;
    static int[][] exceptionX, exceptionY;
    static boolean[][] visited;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		m = Integer.parseInt(st.nextToken());
		
		paper = new int[n][m];
		for(int i=0; i<n; i++){
		    st = new StringTokenizer(br.readLine());
		    for(int j=0; j<m; j++){
		        paper[i][j] = Integer.parseInt(st.nextToken());
		    }
		}
		
		// pink
		exceptionX = new int[4][4]; exceptionY = new int[4][4];
		exceptionX[0] = new int[] {0, 0, 0, 1}; exceptionY[0] = new int[] {0, 1, 2, 1}; // ㅜ
		exceptionX[1] = new int[] {0, 1, 2, 1}; exceptionY[1] = new int[] {0, 0, 0, 1}; // ㅏ
		exceptionX[2] = new int[] {1, 1, 1, 0}; exceptionY[2] = new int[] {0, 1, 2, 1}; // ㅗ
		exceptionX[3] = new int[] {1, 0, 1, 2}; exceptionY[3] = new int[] {0, 1, 1, 1}; // ㅓ
		
		int answer = 0;
		visited = new boolean[n][m];
		
		for(int i=0; i<n; i++){
		    for(int j=0; j<m; j++){
		        visited[i][j] = true;
		        answer = Math.max(answer, tetromino(i, j, 1, paper[i][j]));
		        answer = Math.max(answer, exception(i, j));
		        visited[i][j] = false;
		    }
		}
		System.out.println(answer);
	}
	
	static int exception(int x, int y){
	    int result = 0;
	    
	    for(int i=0; i<4; i++) {
	        int[] coordX = exceptionX[i];
	        int[] coordY = exceptionY[i];
	            
	        if(x + coordX[0] >= n || y + coordY[0] >= m) continue;
	        if(x + coordX[1] >= n || y + coordY[1] >= m) continue;
	        if(x + coordX[2] >= n || y + coordY[2] >= m) continue;
	        if(x + coordX[3] >= n || y + coordY[3] >= m) continue;
	            
	        int tmp = 0;
	        tmp += paper[x + coordX[0]][y + coordY[0]] + paper[x + coordX[1]][y + coordY[1]];
	        tmp += paper[x + coordX[2]][y + coordY[2]] + paper[x + coordX[3]][y + coordY[3]];
	            
	        result = Math.max(result, tmp);
	    }
	    return result;
	}
	
	static int tetromino(int x, int y, int count, int sum) {
	    if(count == 4) {
	        return sum;
	    }
	    
	    int result = 0;
	    for(int i=0; i<4; i++) {
	        int nx = x + dx[i];
	        int ny = y + dy[i];
	        
	        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
	        if(visited[nx][ny]) continue;
	        
	        visited[nx][ny] = true;
	        result = Math.max(result, tetromino(nx, ny, count+1, sum + paper[nx][ny]));
	        visited[nx][ny] = false;
	    }
	    
	    return result;
	}
}
