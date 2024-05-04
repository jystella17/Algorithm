// 프로그래머스 Lv.2

import java.util.*;

class Position {
    int x, y;
    
    Position(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

class PosComparator implements Comparator<Position> {
    
    @Override
    public int compare(Position p1, Position p2) {
        if(p1.x == p2.x) {
            return p1.y - p2.y;
        } else {
            return p1.x - p2.x;
        }
    }
}

class Solution {
    public int solution(int[][] targets) {
        int answer = 0, threshold = 0;
        PriorityQueue<Position> targetList = new PriorityQueue<>(1, new PosComparator());
        
        for(int i=0; i<targets.length; i++) {
            int x = targets[i][0];
            int y = targets[i][1];
            
            targetList.offer(new Position(x, y));
        }
        
        while(!targetList.isEmpty()) {
            Position p = targetList.poll();
            
            if(p.x >= threshold) {
                threshold = p.y;
                answer++;
            }
            
            if(p.y < threshold) {
                threshold = p.y;
            }
        }
        return answer;
    }
}
