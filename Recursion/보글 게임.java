// 알고리즘 문제해결 전략 예제
// ID: BOGGLE, 난이도: 하

import java.util.*;
import java.io.*;

public class Main {
    
    private static int[]dx = {1, -1, 0, 0, 1, -1, 1, -1};
    private static int[]dy = {0, 0, 1, -1, 1, -1, -1, 1};
    private static char[] word = {'R', 'E', 'P', 'E', 'A', 'T', ' '};
    private static char[][] board = new char[5][5];
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		for(int i=0; i<5; i++) {
		    st = new StringTokenizer(br.readLine());
		    
		    for(int j=0; j<5; j++) {
		        board[i][j] = st.nextToken().charAt(0);
		    }
		}
		System.out.println(hasWord(1, 2, 0));
	}
	
	public static boolean hasWord(int x, int y, int idx) {
	    // Base Case
	    if(idx == word.length) return true;
	    
	    if(board[x][y] != word[idx]) return false;
	    
	    // 8방탐색
	    for(int i=0; i<8; i++) {
	        int nx = x + dx[i];
	        int ny = y + dy[i];
	        
	        if(nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
	            
	        if(hasWord(nx, ny, idx+1) return true;
	    }
	    return false;
	}
}
