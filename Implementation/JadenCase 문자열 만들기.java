// 프로그래머스 Lv.2 JadenCase 문자열 만들기
// 정규표현식과 String 클래스 사용법 숙지 필요

import java.util.*;

class Solution {
    public String solution(String s) {
        String answer = "";
        String[] splits = s.split(" ");
        
        int idx = 0;
        for(String sp: splits) { 
            if(!sp.equals("")) {
                String first = sp.substring(0, 1);
                String second = sp.substring(1, sp.length());
                
                if(first.matches("[0-9]+")) {
                    answer += first;
                } else {
                    answer += first.toUpperCase();
                }
                answer += second.toLowerCase();
            } else {
                answer += sp;
            }
            
            if(idx != splits.length-1) {
                answer += " ";
            }
            idx++;
        }
        
        String repair = String.join(" ", splits);
        for(int i=0; i<s.length() - repair.length(); i++) {
            answer += " ";
        }
        
        return answer;
    }
}
