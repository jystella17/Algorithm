// 프로그래머스 Lv.2 구명보트

import java.util.*;

class Solution {
    public int solution(int[] people, int limit) {
        int answer = 0;
        Arrays.sort(people);
        int low = 0, high = people.length - 1;
        
        while(low <= high) {
            if(people[low] + people[high] <= limit) {
                answer++;
                low++; high--;
            } else {
                answer++;
                high--;
            }
        }
        return answer;
    }
}
