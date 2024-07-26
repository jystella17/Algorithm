// BOJ 21942 부품 대여장 (G2)
// HashMap과 TreeMap의 차이를 이해하고 코드에 활용할 것
// String 클래스의 메소드 종류 외우기

import java.io.*;
import java.util.*;

public class Main {
  
  static int[] monthDays = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
  static HashMap<String, Long> borrowBook;
  static TreeMap<String, Long> penaltySum;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		init();
		
		int n = Integer.parseInt(st.nextToken());
		int durations = convertL(st.nextToken()); 
		int f = Integer.parseInt(st.nextToken());
		
		for(int i=0; i<n; i++) {
		    st = new StringTokenizer(br.readLine());
		    long timeStamp = 0;

		    String[] ymdList = st.nextToken().split("-");
		    int month = Integer.parseInt(ymdList[1]);
		    int date = Integer.parseInt(ymdList[2]);
		    for(int m=month-1; m>=1; m--) {
		        timeStamp += (monthDays[m] * 24 * 60);
		    }
		    timeStamp += ((date-1) * 24 * 60);

		    String[] timeList = st.nextToken().split(":");
		    timeStamp += (Integer.parseInt(timeList[0]) * 60);
		    timeStamp += Integer.parseInt(timeList[1]);
		    
		    String key = st.nextToken() + "|" + st.nextToken();
		    if(borrowBook.containsKey(key)) {
		        long borrowedFrom = borrowBook.get(key);
		        long difference = timeStamp - borrowedFrom - durations;
		        
		        if(difference > 0) {
		            String name = key.substring(key.indexOf("|") + 1);
		            long current = 0L;
		            
		            if(penaltySum.containsKey(name)) {
		                current += penaltySum.get(name);
		            }
		            penaltySum.put(name, current + difference*f);
		        }
		        borrowBook.remove(key);
		        
		    } else {
		        borrowBook.put(key, timeStamp);
		    }
		}
        
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		int count = 0;
		
		for(String key: penaltySum.keySet()) {
		    if(penaltySum.get(key) > 0) {
		        count++;
		        bw.write(key + " " + penaltySum.get(key) + "\n");
		    }
		}
		
		if(count == 0) bw.write("-1");
		bw.flush();
		bw.close();
	}
	
	public static int convertL(String l) {
	    int days = Integer.parseInt(l.substring(0, 3));
	    int hours = Integer.parseInt(l.substring(4, 6));
	    int minutes = Integer.parseInt(l.substring(7, 9));
	    
	    return (days*24*60) + (hours*60) + minutes;
	}
	
	public static void init() {
	    borrowBook = new HashMap<>();
	    penaltySum = new TreeMap<>();
	}
}
