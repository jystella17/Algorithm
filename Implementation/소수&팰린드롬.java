// BOJ 1747 소수&팰린드롬 (S1)

import java.io.*;
import java.util.*;

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		int n = Integer.parseInt(st.nextToken());
		for(int i=n; i<=1003001; i++) {
		    if(i == 1) {
		        bw.write(2 + "");
		        break;
		    }
		    
		    if(isPalindrome(i) && isPrime(i)) {
		        bw.write(i + "");
		        break;
		    }
		}
		bw.flush();
		bw.close();
	}
	
	public static boolean isPalindrome(int num) {
	    String number = Integer.toString(num);
	    String[] numbers = number.split("");
	    
 	    int start = 0, end = numbers.length-1;
 	    while(start <= end) {
 	        if(!numbers[start].equals(numbers[end])) {
 	            return false;
 	        }
 	        start++;
 	        end--;
 	    }
	    return true;
	}
	
	public static boolean isPrime(int num) {
	    for(int i=2; i*i<=num; i++) {
	        if(num % i == 0) {
	            return false;
	        }
	    }
	    return true;
	}
}
