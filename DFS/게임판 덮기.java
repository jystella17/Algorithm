// 알고리즘 문제해결 전략 예제 (Algospot BOARDCOVER)

import java.io.*;
import java.util.*;

public class Main {
    
    public static int h, w;
    public static int[][][] blocks = {
        {{0, 0}, {1, 0}, {0, 1}},
        {{0, 0}, {1, 0}, {1, 1}},
        {{0, 0}, {1, 0}, {1, -1}},
        {{0, 0}, {0, 1}, {1, 1}}
    };
    public static char[][] board;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		
		int tc = Integer.parseInt(st.nextToken());
		for(int t=0; t<tc; t++) {
		    st = new StringTokenizer(br.readLine());
		    h = Integer.parseInt(st.nextToken());
		    w = Integer.parseInt(st.nextToken());
		    
		    board = new char[h][w];
		    int count = 0;
		    
		    for(int i=0; i<h; i++) {
		        st = new StringTokenizer(br.readLine());
		        char[] input = st.nextToken().toCharArray();
		        
		        for(int j=0; j<w; j++) {
		            board[i][j] = input[j];
		            
		            if(input[j] == '.')
		                count++;
		        }
		    }

		    if(count % 3 == 0) bw.write(cover() + "\n");
		        
		    else bw.write(0 + "\n");
		}
		
		bw.flush();
		bw.close();
	}
	
	public static int cover() {
	    int x = -1, y = -1;
	    for(int i=0; i<h; i++) {
	        for(int j=0; j<w; j++) {
	            if(board[i][j] == '.') {
	                x = i;
	                y = j;
	                break;
	            }
	        }
	        
	        if(x != -1 && y != -1) break;
	    }
	    
	    // 모든 칸을 채웠다면, 1개의 케이스 탐색을 완료한 것
	    if(x == -1 || y == -1) return 1;
	    
	    // 현재 기준칸(x, y)을 포함한 흰색 칸을 L자 블록으로 덮을 때,
	    // 이후 남은 칸을 L자 블록으로 덮을 수 있는 경우의 수를 answer에 저장
	    // L자 블록은 4가지 방향을 가질 수 있으므로, 각 방향별로 경우의 수 카운트
	    int answer = 0;
	    for(int i=0; i<4; i++) {
	        if(can_cover(x, y, i)) {
	            set(x, y, i, '!'); // block으로 덮인 흰색 칸 = !
	            answer += cover();
	            set(x, y, i, '.');
	        }
	    }
	    return answer;
	}
	
	public static boolean can_cover(int x, int y, int idx) {
	    for(int i=0; i<3; i++) {
	        int nx = x + blocks[idx][i][0];
	        int ny = y + blocks[idx][i][1];
	        
	        if(nx < 0 || nx >= h || ny < 0 || ny >= w) return false;
	        if(board[nx][ny] == '#' || board[nx][ny] == '!') return false;
	    }
	    return true;
	}
	
	public static void set(int x, int y, int idx, char exp) {
	    for(int i=0; i<3; i++) {
	        int nx = x + blocks[idx][i][0];
	        int ny = y + blocks[idx][i][1];
	        
	        board[nx][ny] = exp;
	    }
	}
}
