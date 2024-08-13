// BOJ 1644 소수의 연속합 (G3)
// 소수 판별 (에라토스테네스의 체) + Two Pointers

import java.io.*;
import java.util.*;

public class Main {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());
        
        int n = Integer.parseInt(st.nextToken());
        boolean[] isPrime = new boolean[n+1];
        Arrays.fill(isPrime , true);
        
        isPrime[0] = false; isPrime[1] = false;
        for(int i=2; i<=Math.sqrt(n); i++) {
            if(isPrime[i]) {
                for(int j=i*i; j<=n; j+=i) isPrime[j] = false;
            }
        }
        
        int length = 0;
        List<Integer> primeNumbers = new ArrayList<>();
        for(int i=1; i<=n; i++) {
            if(isPrime[i]) {
                primeNumbers.add(i);
                length++;
            }
        }
        
        int left = 0, right = -1, count = 0, sum = 0;
        while(right < length) {
            if(sum < n) {
                right++;
                if(right == length) continue;
                
                sum += primeNumbers.get(right);
            } else if(sum >= n) {
                if(sum == n) count++;
                
                sum -= primeNumbers.get(left);
                left++;
            }
        }
        System.out.println(count);
    }
}
