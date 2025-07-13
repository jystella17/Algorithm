// 프로그래머스 Lv.2 의상
// HashMap + 경우의 수

import java.util.*;

class Solution {
    public int solution(String[][] clothes) {
        HashMap<String, Integer> items = new HashMap<>();
        
        for(int i=0; i<clothes.length; i++) {
            if(items.containsKey(clothes[i][1])) {
                int count = items.get(clothes[i][1]);
                items.replace(clothes[i][1], count+1);
            }
            
            else {
                items.put(clothes[i][1], 1);
            }
        }
        
        int combination = 1;
        for(String key: items.keySet()) {
            // 각 종류의 의상 중 1개를 선택하거나(items.get(key)) + 아예 선택하지 않음 (1) 
            combination *= (items.get(key) + 1);
        }
        // 모든 종류의 의상을 하나도 선택하지 않은 케이스 제외 (-1)
        return combination-1;
    }
}
