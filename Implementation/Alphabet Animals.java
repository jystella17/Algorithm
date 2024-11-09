// NCPC 2019 (Nordic Collegiate Programming Contest)
// Problem A (Alphabet Animals)

import java.io.*;
import java.util.*;
 
public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		String prev = st.nextToken();
		st = new StringTokenizer(br.readLine());
		int n = Integer.parseInt(st.nextToken());
		
		ArrayList<String>[] words = new ArrayList[26];
		for(int i=0; i<26; i++) {
		    words[i] = new ArrayList<>();
		}
		
		for(int i=0; i<n; i++) {
		    st = new StringTokenizer(br.readLine());
		    String w = st.nextToken();
		    words[w.charAt(0) - 'a'].add(w);
		}
		
		String answer = "";
		int start = prev.charAt(prev.length()-1) - 'a';
		for(int i=0; i<words[start].size(); i++) {
		    String current = words[start].get(i);
		    
		    if(answer.length() == 0) {
		        answer = words[start].get(0);
		    }
		    
		    int next = current.charAt(current.length()-1) - 'a';
		    if(words[next].size() == 0 || (words[next].size() == 1 && start == next)) {
		        answer = words[start].get(i) + "!";
		    }
		    
		    if(answer.charAt(answer.length()-1) == '!') break;
		}
		
		if(answer.length() == 0) {
		    bw.write("?\n");
		} else {
		    bw.write(answer);
		}
		bw.flush();
		bw.close();
	}
}
