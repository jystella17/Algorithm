// BOJ 1300 K번째 수 (G1)
// Parametric Search 응용 - 연속적인 값을 갖지 않는 집합에서의 parametric search

import java.io.*;
import java.util.*;

public class Main {

    static long n, k;

    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st = new StringTokenizer(br.readLine());

        n = Long.parseLong(st.nextToken());
        st = new StringTokenizer(br.readLine());
        k = Long.parseLong(st.nextToken());

        long low = 0, high = n*n + 1;
        while(low < high - 1) {
            long mid = (low + high) / 2;
            long num = countUntilX(mid);

            if(num >= k) { // num보다 작은 숫자의 개수가 K 이상이면, num은 K번째 원소가 될 수 없음
                high = mid; // 더 작은 num을 테스트하도록 설정
            } else { // num보다 작은 숫자의 개수가 K보다 작으면, num은 K번째 원소가 될 가능성이 있음
                low = mid; // num보다 더 큰 숫자이면서 K번째 원소가 될 수 있는 다른 숫자가 존재하는지 테스트하도록 설정
            }
        }
        bw.write(low + "\n");
        bw.flush();
        bw.close();
    }

    public static long countUntilX(long x) { // X보다 작은 숫자의 개수 구하기
        long count = 0;

        // X보다 작은 숫자들 중 1 ~ n의 배수의 개수 구하기
        for(int i=1; i<=n; i++) {
            if((x / i) > n) { // x가 i*n보다 큰 경우 (ex. x=90, i=3, n=10)
                count += n; // i*1 ~ i*n까지의 숫자 n개에 대해서만 카운트
            } else {
                if((x % i) == 0) { // x가 i로 나누어 떨어지는 경우 (x가 i의 배수)
                    count += (x / i) - 1; // x보다 작은 숫자에 대해 계산해야 하므로 x에 대한 카운트 1개를 제외
                } else { // 이외의 경우에는 (x-1)/i 와 x/i의 몫이 동일하므로 별도의 처리 없이 카운트
                    count += (x / i);
                }
            }
        }
        return count;
    }
}
