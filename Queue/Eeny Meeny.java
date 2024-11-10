// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem E (Eeny Meeny)

import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		String input = br.readLine();
		String[] rhymes = input.split(" ");
		int length = rhymes.length;
		
		StringTokenizer st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		Queue<String> queue = new LinkedList<>();
		List<String> groups = new ArrayList<>();
		for(int i=0; i<n; i++) {
		    st = new StringTokenizer(br.readLine());
		    queue.offer(st.nextToken());
		}
		
		while(!queue.isEmpty()) {
        // for (length of rhyme - 1), simply pop element from the queue and push again
		    for(int i=0; i<length-1; i++) {
		        String name = queue.poll();
		        queue.offer(name);
		    }

        // for the kid who matches the word of the rhyme, 
        // pop the name from the queue and add them to answer list
		    String cur = queue.poll();
		    groups.add(cur);
		}
		
		bw.write((n - n/2) + "\n");
		for(int i=0; i<n; i++) {
		    if(i % 2 == 0) {
		        bw.write(groups.get(i) + "\n");
		    }
		}
		
		bw.write(n/2 + "\n");
		for(int i=0; i<n; i++) {
		    if(i % 2 == 1) {
		        bw.write(groups.get(i) + "\n");
		    }
		}
		bw.flush();
		bw.close();
	}
}
