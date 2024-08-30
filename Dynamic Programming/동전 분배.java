// BOJ 1943 동전 분배 (G2)
// 0-1 Knapsack 변형 (weight, value가 모두 주어지지 않고 weight만 주어지는 경우)
// dp 배열의 인덱스 = 0 ~ 만들 수 있는 최대 무게 (여기서는 총합의 절반)로 설정
// dp 배열 값은 true or false => 해당 무게를 만들 수 있는지

import java.io.*;
import java.util.*;

class Pair {
    int x;
    int y;
    
    public Pair(int x, int y) {
        this.x = x;
        this.y = y;
    }
}

public class Main {
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(System.out));
        StringTokenizer st;
        
        for(int t=0; t<3; t++) {
            st = new StringTokenizer(br.readLine());
            int n = Integer.parseInt(st.nextToken());
            List<Pair> coins = new ArrayList<>();
            
            int target = 0;
            for(int i=0; i<n; i++) {
                st = new StringTokenizer(br.readLine());
                int price = Integer.parseInt(st.nextToken());
                int num = Integer.parseInt(st.nextToken());

                coins.add(new Pair(price, num));
                target += (price * num);
            }
            
            if(target % 2 == 1) {
                bw.write(0 + "\n");
                continue;
            }
            
            target /= 2;
            boolean[] canMake = new boolean[target+1];
            canMake[0] = true;
            
            for(int i=0; i<coins.size(); i++) {
                int price = coins.get(i).x;
                int num = coins.get(i).y;
                
                for(int k=target; k>=price; k--) {
                    if(!canMake[k - price]) continue;

                    // 현재 설정한 가격 k - 현재 사용할 동전의 가격 price = prev라고 할 때
                    // canMake[prev] = true이면 이전에 사용한 동전에 현재 동전을 추가해 가격 k를 만들 수 있음
                    // 따라서 target보다 커지지 않는 가격 범위 내에서, 현재 동전을 사용할 수 있는 만큼 사용해 만들 수 있는 가격을 업데이트
                    // 단, k >= price이므로 이미 현재 동전을 무조건 1번은 사용해 보게 됨 => 1개를 빼고 남은 동전만 사용 가능하도록 j < num으로 설정
                    for(int j=0; j<num; j++) {
                        int current = price * j;
                        
                        if(k + current <= target) {
                            canMake[k + current] = true;
                        }
                    }
                }
            }
            
            if(canMake[target]) bw.write(1 + "\n");
            else bw.write(0 + "\n");
        }
        bw.flush();
        bw.close();
	}
}
