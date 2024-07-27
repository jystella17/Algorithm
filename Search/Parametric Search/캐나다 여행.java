// 알고리즘 문제해결 전략 예제
// ID: CANADATRIP 난이도: 중

import java.io.*;
import java.util.*;

class Location {
    int start;
    int end;
    int interval;
    
    public Location(int start, int end, int interval) {
        this.start = start;
        this.end = end;
        this.interval = interval;
    }
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken());
		
		for(int t=0; t<tc; t++) {
		    st = new StringTokenizer(br.readLine());
		    int n = Integer.parseInt(st.nextToken());
		    int k = Integer.parseInt(st.nextToken());
		    
		    List<Location> locationList = new ArrayList<>();
		    for(int i=0; i<n; i++) {
		        st = new StringTokenizer(br.readLine());
		        int end = Integer.parseInt(st.nextToken());
		        int before = Integer.parseInt(st.nextToken());
		        int interval = Integer.parseInt(st.nextToken());
		        
		        Location loc = new Location(end-before, end, interval);
		        locationList.add(loc);
		    }
		    
		    int low = -1, high = 8030001;
		    while(low <= high) {
		        int mid = (low + high) / 2;
		        int sum = 0;
		        
		        for(int i=0; i<n; i++) {
		            int start = locationList.get(i).start;
		            int end = locationList.get(i).end;
		            int interval = locationList.get(i).interval;
		            
		            if(mid >= start) {
		                int bound = Math.min(end, mid);
		                sum += ((bound - start) / interval + 1);
		            }
		        }
		        
		        if(sum >= k) high = mid - 1;
		        else low = mid + 1;
		    }
		    System.out.println(low);
		}
	}
}
