// BOJ 14500 테트로미노 (G4)
// Rule-based Brute Force
// 각 테트로미노의 회전&대칭 모양을 모두 구하고, 기준 좌표 x,y에서 해당 모양을 만들기 위한 좌표 이동값을 모두 저장
// 종이 위에 존재하는 모든 좌표 (x,y)에 대해, 해당 지점을 기준 좌표로 모든 테트로미노 모양을 시도한 뒤 최대값을 저장

import java.io.*;
import java.util.*;

public class Main {
    
  static int n, m;
  static int[][] paper;
  static int[][][] tetrominoX, tetrominoY;
    
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
		
		tetrominoX = new int[5][8][4]; tetrominoY = new int[5][8][4];
		
		// skyblue
		tetrominoX[0][0] = new int[] {0, 0, 0, 0}; tetrominoY[0][0] = new int[] {0, 1, 2, 3}; // 기본형
		tetrominoX[0][1] = new int[] {0, 1, 2, 3}; tetrominoY[0][1] = new int[] {0, 0, 0, 0}; // 90도
		
		// yellow
		tetrominoX[1][0] = new int[] {0, 0, 1, 1}; tetrominoY[1][0] = new int[] {0, 1, 0, 1}; // 기본형
		
		// orange
		tetrominoX[2][0] = new int[] {0, 1, 2, 2}; tetrominoY[2][0] = new int[] {0, 0, 0, 1}; // 기본형
		tetrominoX[2][1] = new int[] {1, 1, 1, 0}; tetrominoY[2][1] = new int[] {0, 1, 2, 2}; // 90도
		tetrominoX[2][2] = new int[] {0, 0, 1, 2}; tetrominoY[2][2] = new int[] {0, 1, 1, 1}; // 180도
		tetrominoX[2][3] = new int[] {0, 0, 0, 1}; tetrominoY[2][3] = new int[] {0, 1, 2, 0}; // 270도
		tetrominoX[2][4] = new int[] {0, 1, 2, 2}; tetrominoY[2][4] = new int[] {1, 1, 1, 0}; // 기본 대칭
		tetrominoX[2][5] = new int[] {1, 1, 1, 0}; tetrominoY[2][5] = new int[] {2, 1, 0, 0}; // 90도 대칭
		tetrominoX[2][6] = new int[] {0, 0, 1, 2}; tetrominoY[2][6] = new int[] {0, 1, 0, 0}; // 180도 대칭
		tetrominoX[2][7] = new int[] {0, 0, 0, 1}; tetrominoY[2][7] = new int[] {0, 1, 2, 2}; // 270도 대칭
		
		// green
		tetrominoX[3][0] = new int[] {0, 1, 1, 2}; tetrominoY[3][0] = new int[] {0, 0, 1, 1}; // 기본형
		tetrominoX[3][1] = new int[] {1, 1, 0, 0}; tetrominoY[3][1] = new int[] {0, 1, 1, 2}; // 90도
		tetrominoX[3][2] = new int[] {0, 1, 1, 2}; tetrominoY[3][2] = new int[] {1, 0, 1, 0}; // 기본 대칭
		tetrominoX[3][3] = new int[] {1, 1, 0, 0}; tetrominoY[3][3] = new int[] {2, 1, 1, 0}; // 90도 대칭

		// pink
		tetrominoX[4][0] = new int[] {0, 0, 0, 1}; tetrominoY[4][0] = new int[] {0, 1, 2, 1}; // 기본형
		tetrominoX[4][1] = new int[] {0, 1, 2, 1}; tetrominoY[4][1] = new int[] {0, 0, 0, 1}; // 90도
		tetrominoX[4][2] = new int[] {1, 1, 1, 0}; tetrominoY[4][2] = new int[] {0, 1, 2, 1}; // 180도
		tetrominoX[4][3] = new int[] {1, 0, 1, 2}; tetrominoY[4][3] = new int[] {0, 1, 1, 1}; // 270도
		
		int answer = 0;
		for(int i=0; i<n; i++){
		    for(int j=0; j<m; j++){
		        for(int t=0; t<5; t++){
		            answer = Math.max(answer, partialSum(i, j, t));
		        }
		    }
		}
		System.out.println(answer);
	}
	
	static int partialSum(int x, int y, int num){
	    int result = 0;
	    
	    if(num == 0) {
	        for(int i=0; i<2; i++) {
	            int[] coordX = tetrominoX[num][i];
	            int[] coordY = tetrominoY[num][i];
	            
	            if(x + coordX[0] >= n || y + coordY[0] >= m) continue;
	            if(x + coordX[1] >= n || y + coordY[1] >= m) continue;
	            if(x + coordX[2] >= n || y + coordY[2] >= m) continue;
	            if(x + coordX[3] >= n || y + coordY[3] >= m) continue;
	            
	            int tmp = 0;
	            tmp += paper[x + coordX[0]][y + coordY[0]] + paper[x + coordX[1]][y + coordY[1]];
	            tmp += paper[x + coordX[2]][y + coordY[2]] + paper[x + coordX[3]][y + coordY[3]];
	            
	            result = Math.max(result, tmp);
	        }
	    }
	    
	    else if(num == 1) {
	        int[] coordX = tetrominoX[num][0];
	        int[] coordY = tetrominoY[num][0];
	        
	        if(x + coordX[0] >= n || y + coordY[0] >= m) return 0;
	        if(x + coordX[1] >= n || y + coordY[1] >= m) return 0;
	        if(x + coordX[2] >= n || y + coordY[2] >= m) return 0;
	        if(x + coordX[3] >= n || y + coordY[3] >= m) return 0;
	        
	        result += paper[x + coordX[0]][y + coordY[0]] + paper[x + coordX[1]][y + coordY[1]];
	        result += paper[x + coordX[2]][y + coordY[2]] + paper[x + coordX[3]][y + coordY[3]];
	    }
	    
	    else if(num == 3 || num == 4) {
	        for(int i=0; i<4; i++) {
	            int[] coordX = tetrominoX[num][i];
	            int[] coordY = tetrominoY[num][i];
	            
	            if(x + coordX[0] >= n || y + coordY[0] >= m) continue;
	            if(x + coordX[1] >= n || y + coordY[1] >= m) continue;
	            if(x + coordX[2] >= n || y + coordY[2] >= m) continue;
	            if(x + coordX[3] >= n || y + coordY[3] >= m) continue;
	            
	            int tmp = 0;
	            tmp += paper[x + coordX[0]][y + coordY[0]] + paper[x + coordX[1]][y + coordY[1]];
	            tmp += paper[x + coordX[2]][y + coordY[2]] + paper[x + coordX[3]][y + coordY[3]];
	            
	            result = Math.max(result, tmp);
	        }
	    }
	    
	    else {
	        for(int i=0; i<8; i++) {
	            int[] coordX = tetrominoX[num][i];
	            int[] coordY = tetrominoY[num][i];
	            
	            if(x + coordX[0] >= n || y + coordY[0] >= m) continue;
	            if(x + coordX[1] >= n || y + coordY[1] >= m) continue;
	            if(x + coordX[2] >= n || y + coordY[2] >= m) continue;
	            if(x + coordX[3] >= n || y + coordY[3] >= m) continue;
	            
	            int tmp = 0;
	            tmp += paper[x + coordX[0]][y + coordY[0]] + paper[x + coordX[1]][y + coordY[1]];
	            tmp += paper[x + coordX[2]][y + coordY[2]] + paper[x + coordX[3]][y + coordY[3]];
	            
	            result = Math.max(result, tmp);
	        }
	    }
	    
	    return result;
	}
}
