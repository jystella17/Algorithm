// 프로그래머스 Lv.2 전화번호 목록
// HashMap or HashSet

import java.util.*;

class Solution {
    public boolean solution(String[] phone_book) {
        HashMap<String, Integer> phoneBook = new HashMap<>();
        
        for(int i=0; i<phone_book.length; i++) {
            phoneBook.put(phone_book[i], 1);
        }
        
        for(int i=0; i<phone_book.length; i++) {
            String number = phone_book[i];
            
            for(int j=1; j<number.length(); j++) {
                String num = number.substring(0, j);
                
                if(phoneBook.containsKey(num)) {
                    return false;
                }
            }
        }
        return true;
    }
}
