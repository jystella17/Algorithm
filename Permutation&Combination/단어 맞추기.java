// 백준 9081 S1 단어 맞추기
// next_permutation

import java.util.*;
import java.io.*;

public class Main {
    
    static String[] word;
    
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		int tc = Integer.parseInt(st.nextToken());
		
		for(int t=0; t<tc; t++){
		    st = new StringTokenizer(br.readLine());
		    String str = st.nextToken();
		    word = new String[str.length()];
		    
		    for(int i=0; i<str.length(); i++){
		        word[i] = Character.toString(str.charAt(i));
		    }
		    
		    System.out.println(nextPermutation());
		}
	}
	
	public static String nextPermutation() {
	    boolean isChanged = false;
	    
	    for(int i=word.length-1; i>=1; i--) {
	        if((word[i-1].charAt(0) - 'A') < (word[i].charAt(0) - 'A')) {
	            int criteria = word[i-1].charAt(0) - 'A';
	            
	            for(int j=word.length-1; j>=i; j--) {
	                if(word[j].charAt(0) - 'A' > criteria) {
	                    String tmp = word[j];
	                    word[j] = word[i-1];
	                    word[i-1] = tmp;
	                    
	                    Arrays.sort(word, i, word.length);
	                    isChanged = true;
	                    break;
	                }
	            }
	        }
	        if(isChanged) break;
	    }
	    return String.join("", word);
	}
}
