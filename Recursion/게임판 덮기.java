// 알고리즘 문제해결 전략 예제
// ID: BOARDCOVER, 난이도: 하

import java.util.*;
import java.io.*;

public class Main {
    
    private static int[][] board;
    private static int[][] dx = {{0, 0, 1}, {0, 0, 1}, {0, 1, 1}, {0, 1, 1}};
    private static int[][] dy = {{0, 1, 0}, {0, 1, 1}, {0, 0, 1}, {0, -1, 0}};
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken());
		
		for(int t=0; t<tc; t++) {
		    st = new StringTokenizer(br.readLine());
		    int h = Integer.parseInt(st.nextToken());
		    int w = Integer.parseInt(st.nextToken());
		    board = new int[h][w];
		    
		    for(int i=0; i<h; i++) {
		        st = new StringTokenizer(br.readLine());
		        
		        for(int j=0; j<w; j++) {
		            if(st.nextToken().equals("#")) board[i][j] = 1;
		            else board[i][j] = 0;
		        }
		    }
		    System.out.println(countCases(h, w));
		}
	}
	
	public static boolean cover(int caseNum, int x, int y, int h, int w, int mode) {
	    boolean result = true;
	    
	    for(int i=0; i<3; i++) {
	        int nx = x + dx[caseNum][i];
	        int ny = y + dy[caseNum][i];
	        
	        if(nx < 0 || nx >= h || ny < 0 || ny >= w) {
	            result = false;
	            continue;
	        }
	        // mode = -1인 경우, 해당 조건을 만족하지 않아도 계속 for문이 실행되어야 복구 가능
	        // 바로 return false 하지 않고, flag = false로 대체
	        if(board[nx][ny] >= 1) result = false;
	        board[nx][ny] += mode;
	    }
	    
	    return result;
	}
	
	public static int countCases(int h, int w) {
	    int x = -1, y = -1;
	    for(int i=0; i<h; i++) {
	        for(int j=0; j<w; j++) {
	            if(board[i][j] == 0) {
	                x = i;
	                y = j;
	                break;
	            }
	        }
	        if(y > -1) break;
	    }
	    
	    if(x == -1 && y == -1) return 1;
	    
	    int result = 0;
	    for(int i=0; i<4; i++) {
	        if(cover(i, x, y, h, w, 1)) {
	            result += countCases(h, w);
	        }
	        // 덮은 부분 복구
	        cover(i, x, y, h, w, -1);
	    }
	    return result;
	}
}
